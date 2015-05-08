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
      }
      
    } // namespace stage {
        
  } // namespace ogl {
    
} // namespace render {
