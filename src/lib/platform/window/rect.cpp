// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/window/rect.cpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/window/rect.hpp"

// includes, system

#include <ostream> // std::ostream

// includes, project

//#include <>

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

  namespace window {
      
    // variables, exported

    /* static */ signed const rect::dflt_value_system(-1);
    /* static */ rect const   rect::dflt_rect(rect::dflt_value_system,
                                              rect::dflt_value_system,
                                              rect::dflt_value_system,
                                              rect::dflt_value_system);
    
    // functions, exported

    rect::rect(signed a, signed b, signed c, signed d)
      : x(a), y(b), w(c), h(d)
    {
      TRACE("platform::window::rect::rect(signed,signed,signed,signed)");
    }

    /* explicit */
    rect::rect(glm::ivec2 const& a, glm::ivec2 const& b)
      : x(a.x), y(a.y), w(b.x), h(b.y)
    {
      TRACE("platform::window::rect::rect(glm::ivec2,glm::ivec2)");
    }

    void
    rect::swap(rect& a)
    {
      TRACE("platform::window::rect::swap");
      
      std::swap(x, a.x);
      std::swap(y, a.y);
      std::swap(w, a.w);
      std::swap(h, a.h);
    }

    bool
    rect::contains(glm::ivec2 const& a) const
    {
      TRACE("platform::window::rect::contains");

      return (((x <= a.x) && (a.x <= x + w)) &&
              ((y <= a.y) && (a.y <= y + h)));
    }
    
    bool
    operator==(rect const& lhs, rect const& rhs)
    {
      TRACE("platform::window::operator==(rect,rect)");

      return ((lhs.x == rhs.x) &&
              (lhs.y == rhs.y) &&
              (lhs.w == rhs.w) &&
              (lhs.h == rhs.h));
    }

    bool
    operator<(rect const& lhs, rect const& rhs)
    {
      TRACE("platform::window::operator<(rect,rect)");

      return ((lhs.w * lhs.h) < (rhs.w * rhs.h));
    }

    std::ostream&
    operator<<(std::ostream& os, rect const& a)
    {
      TRACE_NEVER("platform::window::operator<<(rect)");

      std::ostream::sentry const cerberus(os);

      if (cerberus) {
        os << "[x:" << a.x << ",y:" << a.y << ",w:" << a.w << ",h:" << a.h << ']';
      }

      return os;
    }
    
  } // namespace window {
  
} // namespace platform {
