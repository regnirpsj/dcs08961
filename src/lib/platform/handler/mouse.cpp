// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/handler/mouse.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/handler/mouse.hpp"

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

    namespace mouse {
  
      // variables, exported
  
      // functions, exported

      /* explicit */
      base::base(unsigned a)
        : handler::base  (),
          mouseq_        (),
          mouseq_max_len_(a)
      {
        TRACE("platform::handler::mouse::base::base");
      }
      
      /* virtual */
      base::~base()
      {
        TRACE("platform::handler::mouse::base::~base");
      }
      
      /* virtual */ bool
      base::motion(uint8_t a, glm::ivec2 const& b, time_point const& c)
      {
        TRACE("platform::handler::mouse::base::motion");

        update_queue(mouseq_,
                     record{ button::none, state::up, direction::none, a, b, c },
                     mouseq_max_len_);

        return false;
      }
      
      /* virtual */ bool
      base::press(button a, uint8_t b, glm::ivec2 const& c, time_point const& d)
      {
        TRACE("platform::handler::mouse::base::press");

        update_queue(mouseq_,
                     record{ a, state::down, direction::none, b, c, d },
                     mouseq_max_len_);

        return false;
      }

      /* virtual */ bool
      base::release(button a, uint8_t b, glm::ivec2 const& c, time_point const& d)
      {
        TRACE("platform::handler::mouse::base::release");

        update_queue(mouseq_,
                     record{ a, state::up, direction::none, b, c, d },
                     mouseq_max_len_);

        return false;
      }

      /* virtual */ bool
      base::scroll(float /* a */, direction b, uint8_t c, glm::ivec2 const& d, time_point const& e)
      {
        TRACE("platform::handler::mouse::base::release");

        update_queue(mouseq_,
                     record{ button::wheel, state::down, b, c, d, e },
                     mouseq_max_len_);

        return false;
      }
      
      /* virtual */ void
      base::print_on(std::ostream& os) const
      {
        TRACE_NEVER("platform::handler::mouse::base::print_on");

        platform::handler::base::print_on(os);

        support::ostream::format_saver const sofs(os);
        
        using support::ostream::operator<<;
        
        os << "\b::mouse,"
           << mouseq_.size() << '(' << mouseq_max_len_ << "):"
           << support::ostream::delimeter<char>('{', '}', ',')
           << support::ostream::indent<char>("\n ")
           << mouseq_
           << ']';
      }
      
      std::ostream&
      operator<<(std::ostream& os, button const& a)
      {
        TRACE_NEVER("platform::handler::mouse::operator<<(button)");

        typename std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          boost::io::ios_all_saver const ias (os);
          
          os << '['
             << std::right << std::setw(6);

          switch (a) {
          case button::none:   os << "NONE";   break;
          case button::left:   os << "LEFT";   break;
          case button::middle: os << "MIDDLE"; break;
          case button::right:  os << "RIGHT";  break;
          case button::wheel:  os << "WHEEL";  break;
          case button::aux5:   os << "AUX5";   break;
          case button::aux6:   os << "AUX6";   break;
          case button::aux7:   os << "AUX7";   break;
          case button::aux8:   os << "AUX8";   break;
          case button::aux9:   os << "AUX9";   break;
          default:
            {
              os << "INVALID ("
                 << std::setw(2) << std::setfill('0') << static_cast<int8_t>(a)
                 << ")";
            }
            break;
          }
          
          os << ']';
        }

        return os;
      }
      
      std::ostream&
      operator<<(std::ostream& os, direction const& a)
      {
        TRACE_NEVER("platform::handler::mouse::operator<<(direction)");

        typename std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          boost::io::ios_all_saver const ias (os);
          
          os << '['
             << std::right << std::setw(5);

          switch (a) {
          case direction::none:  os << "NONE";  break;
          case direction::down:  os << "DOWN";  break;
          case direction::left:  os << "LEFT";  break;
          case direction::right: os << "RIGHT"; break;
          case direction::up:    os << "UP";    break;
          default:
            {
              os << "INVALID ("
                 << std::setw(2) << std::setfill('0') << static_cast<int8_t>(a)
                 << ")";
            }
            break;
          }
          
          os << ']';
        }

        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, state const& a)
      {
        TRACE_NEVER("platform::handler::mouse::operator<<(state)");

        typename std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          boost::io::ios_all_saver const ias(os);
          
          os << '['
             << std::right << std::setw(4);

          switch (a) {
          case state::down: os << "DOWN";    break;
          case state::up:   os << "UP";      break;
          default:
            {
              os << "INVALID ("
                 << std::setw(2) << std::setfill('0') << static_cast<int8_t>(a)
                 << ")";
            }
            break;
          }
          
          os << ']';
        }

        return os;
      }

      std::ostream&
      operator<<(std::ostream& os, record const& a)
      {
        TRACE_NEVER("platform::handler::mouse::operator<<(record)");

        typename std::ostream::sentry const cerberus(os);
    
        if (cerberus) {
          using namespace std::chrono;
          
          boost::io::ios_all_saver const ias (os);
          glm::io::format_saver const    iofs(os);
        
          os << '['
             << a.btn   << ','
             << a.updwn << ','
             << a.dir   <<  ',';

          using key = keyboard::key;
          
          static std::array<uint8_t const, 4> const modifier = {
            { key::modifier::Alt, key::modifier::Ctrl, key::modifier::Shift, key::modifier::Super, }
          };

          for (auto m : modifier) {
            if (m & a.mod) {
              os << key::modifier(m) << '|';
            }
          }
          
          os << "\b,"
             << glm::io::width(4)
             << a.pos << ','
             << std::dec
             << std::setw(12)
             << duration_cast<microseconds>(a.stamp.time_since_epoch()).count()
             << ']';
        }
    
        return os;
      }
      
    } // namespace mouse {
    
  } // namespace handler {
  
} // namespace platform {
