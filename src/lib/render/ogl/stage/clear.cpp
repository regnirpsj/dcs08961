// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/ogl/stage/clear.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/ogl/stage/clear.hpp"

// includes, system

#include <GL/glew.h> // ::gl*

// includes, project

#include <render/ogl/context.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace render {

  namespace ogl {

    namespace stage {
      
      // variables, exported
  
      // functions, exported

      /* explicit */
      clear::clear(ogl::context& a)
        : render::stage::clear(a)
      {
        TRACE("render::ogl::stage::clear::clear");
      }
      
      /* virtual */
      clear::~clear()
      {
        TRACE("render::ogl::stage::clear::~clear");
      }
      
      /* virtual */ void
      clear::do_execute()
      {
        TRACE("render::ogl::stage::clear::do_execute");

        ::GLbitfield clear_mask(0);

        if (*color) {
          ::glClearColor(color_value->r, color_value->g, color_value->b, color_value->a);

          clear_mask |= GL_COLOR_BUFFER_BIT;
        }

        if (*depth) {
          ::glClearDepth(*depth_value);
          
          clear_mask |= GL_DEPTH_BUFFER_BIT;
        }

        if (*stencil) {
          ::glClearStencil(*stencil_value);
          
          clear_mask |= GL_STENCIL_BUFFER_BIT;
        }

        if (clear_mask) {
          ::glClear(clear_mask);
        }
      }
      
    } // namespace stage {
        
  } // namespace ogl {
    
} // namespace render {
