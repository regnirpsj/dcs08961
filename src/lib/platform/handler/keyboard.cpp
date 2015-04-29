// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/handler/keyboard.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/handler/keyboard.hpp"

// includes, system

#include <boost/io/ios_state.hpp> // boost::io::ios_all_saver
#include <glm/gtx/io.hpp>         // glm::operator<<
#include <ostream>                // std::ostream

// includes, project

#include <support/io_utils.hpp>
#include <handler/common.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal
  
} // namespace {

namespace platform {

  namespace handler {

    namespace keyboard {
  
      // variables, exported
  
      // functions, exported

      /* explicit */
      base::base(unsigned a)
        : handler::base     (),
          keyboardq_        (),
          keyboardq_max_len_(a)
      {
        TRACE("platform::handler::keyboard::base::base");
      }
      
      /* virtual */
      base::~base()
      {
        TRACE("platform::handler::keyboard::base::~base");
      }

      /* virtual */ bool
      base::press(key::ascii a, uint8_t b, glm::ivec2 const& c, time_point const& d)
      {
        TRACE("platform::handler::keyboard::base::press(key::ascii)");

        update_queue(keyboardq_,
                     record{ uint16_t(a), key::state::down, b, c, d },
                     keyboardq_max_len_);

        return false;
      }

      /* virtual */ bool
      base::press(key::code a, uint8_t b, glm::ivec2 const& c, time_point const& d)
      {
        TRACE("platform::handler::keyboard::base::press(key::code)");

        update_queue(keyboardq_,
                     record{ uint16_t(unsigned(a) << 8), key::state::down, b, c, d },
                     keyboardq_max_len_);

        return false;
      }

      /* virtual */ bool
      base::release(key::ascii a, uint8_t b, glm::ivec2 const& c, time_point const& d)
      {
        TRACE("platform::handler::keyboard::base::release(key::ascii)");

        update_queue(keyboardq_,
                     record{ uint16_t(a), key::state::up, b, c, d },
                     keyboardq_max_len_);

        return false;
      }

      /* virtual */ bool
      base::release(key::code a, uint8_t b, glm::ivec2 const& c, time_point const& d)
      {
        TRACE("platform::handler::keyboard::base::release(key::code)");

        update_queue(keyboardq_,
                     record{ uint16_t(unsigned(a) << 8), key::state::up, b, c, d },
                     keyboardq_max_len_);

        return false;
      }

      /* virtual */ void
      base::print_on(std::ostream& os) const
      {
        TRACE_NEVER("platform::handler::keyboard::base::print_on");

        platform::handler::base::print_on(os);

        support::ostream::format_saver const sofs(os);
        
        using support::ostream::operator<<;
        
        os << "\b::keyboard,"
           << keyboardq_.size() << '(' << keyboardq_max_len_ << "):"
           << support::ostream::delimeter<char>('{', '}', ',')
           << support::ostream::indent<char>("\n ")
           << keyboardq_
           << ']';
      }

      std::ostream&
      operator<<(std::ostream& os, key::ascii const& a)
      {
        TRACE_NEVER("platform::handler::keyboard::operator<<(key::ascii)");

        typename std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          static std::array<std::string const, 32> const ascii1 = {
            { "NUL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL", "BS", "HT", "LF", "VT", "FF",
              "CR", "SO", "SI", "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB", "CAN", "EM",
              "SUB", "ESC", "FS", "GS", "RS", "US", }
          };

          static std::array<std::string const, 1> const ascii2 = {
            { "DEL", }
          };
          
          os << '[';

          uint8_t const idx(static_cast<uint8_t>(a));

          if        (/* (  0 <= idx) && */ ( 31 >= idx)) {
            os << ascii1[idx];
          } else if (( 32 <= idx) && (126 >= idx)) {
            os << static_cast<unsigned char>(idx - '\0');
          } else if ((127 <= idx) /* && (127 >= idx) */) {
            os << ascii2[idx-127];
          } else {
            boost::io::ios_all_saver const ias(os);
            
            os << "INVALID ("
               << std::hex << std::setw(2) << std::setfill('0') << idx
               << ")";
          }
          
          os << ']';
        }
    
        return os;
      }
      
      std::ostream&
      operator<<(std::ostream& os, key::code const& a)
      {
        TRACE_NEVER("platform::handler::keyboard::operator<<(key::code)");

        typename std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          static std::array<std::string const, 33> const code = {
            { "INVALID",
              "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "Left",
              "Up", "Right", "Down", "PageUp", "PageDown", "Home", "End", "Insert", "NumLock",
              "Begin", "Delete", "AltLeft", "AltRight", "CtrlLeft", "CtrlRight", "ShiftLeft",
              "ShiftRight", "SuperLeft", "SuperRight", }
          };

          os << '[';

          uint8_t const idx(static_cast<uint8_t>(a));
          
          if ((0 < idx) && (code.size()-1 > idx)) {
            os << code[idx];
          } else {
            boost::io::ios_all_saver const ias(os);

            os << code[0] << " ("
               << std::hex << std::setw(2) << std::setfill('0') << idx
               << ")";
          }
          
          os << ']';
        }
    
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, key::modifier const& a)
      {
        TRACE_NEVER("platform::handler::keyboard::operator<<(key::modifier)");

        typename std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          os << '[';

          switch (a) {
          case key::modifier::None:  os << "NONE";  break;
          case key::modifier::Alt:   os << "ALT";   break;
          case key::modifier::Ctrl:  os << "CTRL";  break;
          case key::modifier::Shift: os << "SHIFT"; break;
          case key::modifier::Super: os << "SUPER"; break;
          default:
            {
              boost::io::ios_all_saver const ias (os);

              os << "INVALID ("
                 << std::hex << std::setw(2) << std::setfill('0') << static_cast<int8_t>(a)
                 << ")";
            }
            break;
          }
          
          os << ']';
        }
    
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, key::state const& a)
      {
        TRACE_NEVER("platform::handler::keyboard::operator<<(key::state)");

        typename std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          std::string result("[]");

          switch (a) {
          case key::state::down: result.insert(1, "DOWN"); break;
          case key::state::up:   result.insert(1, "  UP");   break;
          default:                                         break;
          }
          
          os << result;
        }
    
        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, record const& a)
      {
        TRACE_NEVER("platform::handler::keyboard::operator<<(record)");

        typename std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          using namespace std::chrono;
          
          boost::io::ios_all_saver const ias (os);
          glm::io::format_saver const    iofs(os);
        
          os << '[';

          if (0xFF00 & a.key) {
            os << static_cast<key::code> (a.key >> 8);
          } else {
            os << static_cast<key::ascii>(a.key);
          }

          os << ','
             << a.updwn << ",[";

          static std::array<uint8_t const, 4> const modifier = {
            { key::modifier::Alt, key::modifier::Ctrl, key::modifier::Shift, key::modifier::Super, }
          };

          bool insert(false);
          
          for (auto m : modifier) {
            if (a.mod & m) {
              os << key::modifier(a.mod) << '|';

              insert = true;
            }
          }

          if (insert) {
            os << '\b';
          } else {
            os << "NONE";
          }
          
          os << "],"
             << glm::io::width(4)
             << a.pos << ','
             << std::dec
             << std::setw(12)
             << duration_cast<microseconds>(a.stamp.time_since_epoch()).count()
             << ']';
        }
    
        return os;
      }
      
    } // namespace keyboard {
    
  } // namespace handler {
  
} // namespace platform {
