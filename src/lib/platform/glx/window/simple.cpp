// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glx/window/simple.cpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/glx/window/simple.hpp"

// includes, system

//#include <>

// includes, project

#include <platform/glx/window/manager.hpp>

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

  namespace glx {

    namespace window {
  
      // variables, exported
  
      // functions, exported
      
      /* explicit */
      simple::simple(std::string const& a, rect const& b, std::string const& c,
                     attribute_list const& d)
        : base(a, b, c, d)
      {
        TRACE("platform::glx::window::simple::simple");
      }

      /* virtual */ void
      simple::frame_render_one()
      {
        TRACE("platform::glx::window::simple::frame_render_one");

        throw std::logic_error("pure virtual function "
                               "'platform::glx::window::simple::frame_render_one' called");
      }

      /* virtual */ void
      simple::frame_render_post()
      {
        TRACE_NEVER("platform::glx::window::simple::frame_render_post");

        if (window::manager::count()) {
          ::glXSwapBuffers(display_, window_);
        }
      }
      
      /* virtual */ void
      simple::frame_render_pre()
      {
        TRACE_NEVER("platform::glx::window::simple::frame_render_pre");

        ::glXMakeCurrent(display_, None, nullptr);
      }

      /* virtual */ void
      simple::display()
      {
        TRACE("platform::glx::window::simple::display");

        if (window::manager::count()) {
          frame_render_pre ();
          frame_render_one ();
          frame_render_post();
        }
      }
      
    } // namespace window {
    
  } // namespace glx {
    
} // namespace platform {
