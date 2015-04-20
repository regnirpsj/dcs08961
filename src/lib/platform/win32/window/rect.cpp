// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/win32/window/rect.cpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/win32/window/rect.hpp"

// includes, system

//#include <>

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

  namespace win32 {

    namespace window {
  
      // variables, exported
  
      // functions, exported

      /* explicit */
      rect::rect(RECT const& a)
        : platform::window::rect(a.left, a.top, a.right - a.left, a.bottom - a.top)
      {
        TRACE("platform::win32::window::rect::rect");
      }

      rect::operator RECT () const
      {
        TRACE("platform::win32::window::rect::");

        RECT r;

        r.left   = x;
        r.top    = y;
        r.right  = x + w;
        r.bottom = y + h;
      
        return r;

      }

      rect& rect::operator=(RECT const& rhs)
      {
        TRACE("platform::win32::window::rect::operator=(RECT)");

        rect r(rhs);

        swap(r);

        return *this;

      }

    } // namespace window {

  } // namespace win32 {
  
} // namespace platform {
