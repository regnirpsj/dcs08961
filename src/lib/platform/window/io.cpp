// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/window/io.cpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/window/io.hpp"

// includes, system

#include <array>          // std::array<>
#include <glm/gtx/io.hpp> // glm::operator<<
#include <ostream>        // std::ostream

// includes, project

#include <support/chrono_io.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

  std::string const
  button_to_string(signed a)
  {
    std::string result("[" + std::to_string(a) + "]");

    return result;
  }

  std::string const
  duration_to_string(support::clock::duration const& a)
  {
    using namespace std::chrono;
    
    std::ostringstream ostr;

    ostr << duration_fmt(symbol) << duration_cast<microseconds>(a);
    
    return ostr.str();
  }

  std::string const
  key_to_string(signed a, bool b)
  {
    static std::array<std::pair<signed const, std::string const>, 32> const keys_ascii1 = {
      {
        { 0x00, "NUL" },
        { 0x01, "SOH" },
        { 0x02, "STX" },
        { 0x03, "ETX" },
        { 0x04, "EOT" },
        { 0x05, "ENQ" },
        { 0x06, "ACK" },
        { 0x07, "BEL" },
        { 0x08, "BS"  },
        { 0x09, "HT"  },
        { 0x0A, "LF"  },
        { 0x0B, "VT"  },
        { 0x0C, "FF"  },
        { 0x0D, "CR"  },
        { 0x0E, "SO"  },
        { 0x0F, "SI"  },
        { 0x10, "DLE" },
        { 0x11, "DC1" },
        { 0x12, "DC2" },
        { 0x13, "DC3" },
        { 0x14, "DC4" },
        { 0x15, "NAK" },
        { 0x16, "SYN" },
        { 0x17, "ETB" },
        { 0x18, "CAN" },
        { 0x19, "EM"  },
        { 0x1A, "SUB" },
        { 0x1B, "ESC" },
        { 0x1C, "FS"  },
        { 0x1D, "GS"  },
        { 0x1E, "RS"  },
        { 0x1F, "US"  },
      }
    };
    
    static std::array<std::pair<signed const, std::string const>, 1> const keys_ascii2 = {
      {
        { 0x7F, "DEL" },
      }
    };    
    
    std::ostringstream ostr;

    ostr << '[';

    bool handled(true);
    
    if (b) {
      ostr << "KEY?";
        
      handled = false;
    } else {
      if        ((keys_ascii1[0].first <= a) &&
                 ((keys_ascii1[0].first + signed(keys_ascii1.size())) > a)) {
        ostr << keys_ascii1[a - keys_ascii1[0].first].second;
      } else if ((keys_ascii2[0].first <= a) &&
                 ((keys_ascii2[0].first + signed(keys_ascii2.size())) > a)) {
        ostr << keys_ascii2[a - keys_ascii2[0].first].second;
      } else if (((keys_ascii1[0].first + signed(keys_ascii1.size())) <= a) &&
                 (keys_ascii2[0].first > a)) {
        ostr << static_cast<unsigned char>(a - '\0');
      } else {
        ostr << "ASC?";
        
        handled = false;
      }
    }

    if (!handled) {
      ostr << '('
           << "0x" << std::hex << std::setw(2) << std::setfill('0') << a
           << ')';
    }
    
    ostr << ']';
    
    return ostr.str();
  }
  
  std::string const
  modifier_to_string(signed a)
  {
    std::string result("[" + std::to_string(a) + "]");    

    return result;
  }

  std::string const
  stamp_to_string(support::clock::time_point const& a)
  {
    using namespace std::chrono;
    
    std::ostringstream ostr;

    ostr << std::dec
         << std::setw(12)
         << duration_cast<microseconds>(a.time_since_epoch()).count();
    
    return ostr.str();
  }

  std::string const
  state_to_string(signed a)
  {
    std::string result("[]");

    result.insert(1, a ? "  UP" : "DOWN");
    
    return result;
  }
  
} // namespace {

namespace platform {

  namespace window {
    
    // variables, exported
  
    // functions, exported

    std::ostream& operator<<(std::ostream& os, frame_record_t const& a)
    {
      TRACE_NEVER("platform::window::operator<<(frame_record_t)");

      std::ostream::sentry const cerberus(os);

      if (cerberus) {
        os << '['
           << std::dec << std::setw(9)
           << a.counter                     << ','
           << duration_to_string(a.delta_t) << ','
           << stamp_to_string(a.stamp)
           << ']';
      }

      return os;
    }
    
    std::ostream& operator<<(std::ostream& os, keyboard_record_t const& a)
    {
      TRACE_NEVER("platform::window::operator<<(keyboard_record_t)");

      std::ostream::sentry const cerberus(os);

      if (cerberus) {
        os << glm::io::width(4)
           << '['
           << key_to_string(a.key, a.special) << ','
           << state_to_string(a.state)        << ','
           << modifier_to_string(a.modifier)  << ','
           << a.pos                           << ','
           << stamp_to_string(a.stamp)
           << ']';
      }

      return os;
    }

    std::ostream& operator<<(std::ostream& os, mouse_record_t const& a)
    {
      TRACE_NEVER("platform::window::operator<<(mouse_record_t)");

      std::ostream::sentry const cerberus(os);

      if (cerberus) {
        os << glm::io::width(4)
           << '['
           << button_to_string(a.button)     << ','
           << state_to_string(a.state)       << ','
           << modifier_to_string(a.modifier) << ','
           << a.pos                          << ','
           << stamp_to_string(a.stamp)
           << ']';
      }

      return os;
    }
    
  } // namespace window {
  
} // namespace platform {
