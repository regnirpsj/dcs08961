// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/ogl/stage/setup.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/ogl/stage/setup.hpp"

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
      setup::setup(ogl::context& a)
        : render::stage::setup(a)
      {
        TRACE("render::ogl::stage::setup::setup");
      }
      
      /* virtual */
      setup::~setup()
      {
        TRACE("render::ogl::stage::setup::~setup");
      }
      
      /* virtual */ void
      setup::do_execute()
      {
        TRACE("render::ogl::stage::setup::do_execute");
      }

      /* virtual */ void
      setup::do_resize(glm::ivec2 const&)
      {
        TRACE("render::ogl::stage::setup::do_resize");
      }
      
    } // namespace stage {
        
  } // namespace ogl {
    
} // namespace render {
