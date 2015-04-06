// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glut/window/manager.cpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/glut/window/manager.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<< (field::container::print_on)

// includes, project

#include <platform/glut/window/base.hpp>

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

  namespace glut {

    namespace window {
  
      // variables, exported
  
      // functions, exported

      /* static */ unsigned
      manager::count()
      {
        TRACE("platform::glut::window::manager::count");

        return platform::window::manager::count(type::glut);
      }

      /* static */ base*
      manager::get(signed a)
      {
        TRACE_NEVER("platform::glut::window::manager::get");

        return static_cast<base*>(platform::window::manager::get(type::glut, a));
      }

      /* static */ std::vector<signed>
      manager::all()
      {
        TRACE_NEVER("platform::glut::window::manager::all");

        return platform::window::manager::all(type::glut);
      }
      
      /* static */ bool
      manager::add(signed a, base* b)
      {
        TRACE("platform::glut::window::manager::add");

        return platform::window::manager::add(type::glut, a, b);
      }

      /* static */ bool
      manager::sub(base* a)
      {
        TRACE("platform::glut::window::manager::sub(base*)");

        return platform::window::manager::sub(type::glut, a);
      }

      /* static */ bool
      manager::sub(signed a)
      {
        TRACE("platform::glut::window::manager::sub(signed)");

        return platform::window::manager::sub(type::glut, a);
      }
  
    } // namespace window {

  } // namespace glut {
  
} // namespace platform {
