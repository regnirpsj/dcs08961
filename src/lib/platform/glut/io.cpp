// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glut/io.cpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/glut/io.hpp"

// includes, system

// needs to be first!!!
#include <GL/glew.h>      // gl*

#include <GL/freeglut.h>  // ::glut*
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
    std::string result("[]");

    switch (a) {
    case GLUT_LEFT_BUTTON:   result.insert(1, "LEFT");   break;
    case GLUT_MIDDLE_BUTTON: result.insert(1, "MIDDLE"); break;
    case GLUT_RIGHT_BUTTON:  result.insert(1, "RIGHT");  break;
    default:                 result.insert(1, "NONE");   break;
    }

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
    
    static std::array<std::pair<signed const, std::string const>, 12> const keys_function = {
      {
        { GLUT_KEY_F1,  "F1"  },
        { GLUT_KEY_F2,  "F2"  },
        { GLUT_KEY_F3,  "F3"  },
        { GLUT_KEY_F4,  "F4"  },
        { GLUT_KEY_F5,  "F5"  },
        { GLUT_KEY_F6,  "F5"  },
        { GLUT_KEY_F7,  "F7"  },
        { GLUT_KEY_F8,  "F8"  },
        { GLUT_KEY_F9,  "F9"  },
        { GLUT_KEY_F10, "F10" },
        { GLUT_KEY_F11, "F11" },
        { GLUT_KEY_F12, "F12" },
      }
    };

    static std::array<std::pair<signed const, std::string const>, 18> const keys_special = {
      {
        { GLUT_KEY_LEFT,      "LEFT"      },
        { GLUT_KEY_UP,        "UP"        },
        { GLUT_KEY_RIGHT,     "RIGHT"     },
        { GLUT_KEY_DOWN,      "DOWN"      },
        { GLUT_KEY_PAGE_UP,   "PAGE_UP"   },
        { GLUT_KEY_PAGE_DOWN, "PAGE_DOWN" },
        { GLUT_KEY_HOME,      "HOME"      },
        { GLUT_KEY_END,       "END"       },
        { GLUT_KEY_INSERT,    "INSERT"    },
        { GLUT_KEY_NUM_LOCK,  "NUM_LOCK"  },
        { GLUT_KEY_BEGIN,     "BEGIN"     },
        { GLUT_KEY_DELETE,    "DELETE"    },
        { GLUT_KEY_SHIFT_L,   "SHIFT_L"   },
        { GLUT_KEY_SHIFT_R,   "SHIFT_R"   },
        { GLUT_KEY_CTRL_L,    "CTRL_L"    },
        { GLUT_KEY_CTRL_R,    "CTRL_R"    },
        { GLUT_KEY_ALT_L,     "ALT_L"     },
        { GLUT_KEY_ALT_R,     "ALT_R"     },
      }
    };
    
    std::ostringstream ostr;

    ostr << '[';

    bool handled(true);
    
    if (b) {
      if        ((keys_function[0].first <= a) &&
                 ((keys_function[0].first + signed(keys_function.size())) > a)) {
        ostr << keys_function[a - keys_function[0].first].second;
      } else if ((keys_special[0].first <= a) &&
                 (keys_special[0].first + signed(keys_special.size()) > a)) {
        ostr << keys_special[a - keys_special[0].first].second;
      } else {
        ostr << "KEY?";
        
        handled = false;
      }
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
    std::string result;
    
    if (GLUT_ACTIVE_ALT   & a) { result += "ALT|";   }
    if (GLUT_ACTIVE_CTRL  & a) { result += "CTRL|";  }
    if (GLUT_ACTIVE_SHIFT & a) { result += "SHIFT|"; }

    if (result.empty()) {
      result = "[NONE]";
    } else {
      result.pop_back();
      
      result = "[" + result + "]";
    }

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

  namespace glut {
    
    // variables, exported
  
    // functions, exported

    std::ostream& operator<<(std::ostream& os, frame_record_t const& a)
    {
      TRACE_NEVER("platform::glut::operator<<(frame_record_t)");

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
    
    std::ostream& operator<<(std::ostream& os, mouse_record_t const& a)
    {
      TRACE_NEVER("platform::glut::operator<<(mouse_record_t)");

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
    
    std::ostream& operator<<(std::ostream& os, keyboard_record_t const& a)
    {
      TRACE_NEVER("platform::glut::operator<<( )");

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
    
  } // namespace glut {
  
} // namespace platform {
