// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/win32/window/manager.cpp                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/win32/window/manager.hpp"

// includes, system

//#include <>

// includes, project

#include <platform/win32/window/base.hpp>

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

      /* static */ unsigned
      manager::count()
      {
        TRACE("platform::win32::window::manager::count");

        return platform::window::manager::count(type::win32);
      }

      /* static */ base*
      manager::get(signed a)
      {
        TRACE_NEVER("platform::win32::window::manager::get");

        return static_cast<base*>(platform::window::manager::get(type::win32, a));
      }

      /* static */ std::vector<signed>
      manager::all()
      {
        TRACE_NEVER("platform::win32::window::manager::all");

        return platform::window::manager::all(type::win32);
      }
      
      /* static */ bool
      manager::add(signed a, base* b)
      {
        TRACE("platform::win32::window::manager::add");

        return platform::window::manager::add(type::win32, a, b);
      }

      /* static */ bool
      manager::sub(base* a)
      {
        TRACE("platform::win32::window::manager::sub(base*)");

        return platform::window::manager::sub(type::win32, a);
      }

      /* static */ bool
      manager::sub(signed a)
      {
        TRACE("platform::win32::window::manager::sub(signed)");

        return platform::window::manager::sub(type::win32, a);
      }
  
    } // namespace window {

  } // namespace win32 {
  
} // namespace platform {
