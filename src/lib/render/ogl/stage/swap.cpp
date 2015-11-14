// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/ogl/stage/swap.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/ogl/stage/swap.hpp"

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
      swap::swap(ogl::context& a)
        : render::stage::swap(a)
      {
        TRACE("render::ogl::stage::swap::swap");
      }
      
      /* virtual */
      swap::~swap()
      {
        TRACE("render::ogl::stage::swap::~swap");
      }
      
      /* virtual */ void
      swap::do_execute(render::swap::context&)
      {
        TRACE("render::ogl::stage::swap::do_execute");
      }
      
    } // namespace stage {
        
  } // namespace ogl {
    
} // namespace render {
