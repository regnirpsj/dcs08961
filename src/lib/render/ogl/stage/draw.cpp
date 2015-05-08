// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/ogl/stage/draw.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/ogl/stage/draw.hpp"

// includes, system

//#include <>

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
      draw::draw(ogl::context& a)
        : render::stage::draw(a)
      {
        TRACE("render::ogl::stage::draw::draw");
      }
      
      /* virtual */
      draw::~draw()
      {
        TRACE("render::ogl::stage::draw::~draw");
      }
      
      /* virtual */ void
      draw::do_execute()
      {
        TRACE("render::ogl::stage::draw::do_execute");
      }
      
    } // namespace stage {
        
  } // namespace ogl {
    
} // namespace render {
