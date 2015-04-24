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

  std::vector<platform::glut::window::manager::id_type> ids_list;
  bool                                                  ids_changed(false);
  
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

        return platform::window::manager::count(window_type::glut);
      }

      /* static */ base*
      manager::get(id_type a)
      {
        TRACE_NEVER("platform::glut::window::manager::get");

        return static_cast<base*>(platform::window::manager::get(window_type::glut, a));
      }

      /* static */ std::vector<manager::id_type> const&
      manager::all()
      {
        TRACE_NEVER("platform::glut::window::manager::all");

        if (ids_changed) {
          ids_list    = platform::window::manager::all(window_type::glut);
          ids_changed = false;
        }
        
        return ids_list;
      }
      
      /* static */ bool
      manager::add(id_type a, base* b)
      {
        TRACE("platform::glut::window::manager::add");

        ids_changed = true;
        
        return platform::window::manager::add(window_type::glut, a, b);
      }

      /* static */ bool
      manager::sub(base* a)
      {
        TRACE("platform::glut::window::manager::sub(base*)");

        ids_changed = true;
        
        return platform::window::manager::sub(window_type::glut, a);
      }

      /* static */ bool
      manager::sub(id_type a)
      {
        TRACE("platform::glut::window::manager::sub(id_type)");

        ids_changed = true;
        
        return platform::window::manager::sub(window_type::glut, a);
      }
  
    } // namespace window {

  } // namespace glut {
  
} // namespace platform {
