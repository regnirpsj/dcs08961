// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/null/stage/setup.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/null/stage/setup.hpp"

// includes, system

//#include <>

// includes, project

#include <render/null/context.hpp>
#include <statistics.hpp>

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

  namespace null {

    namespace stage {
      
      // variables, exported
  
      // functions, exported

      /* explicit */
      setup::setup()
        : render::base::stage::setup(context::dflt, stats::dflt)
      {
        TRACE("render::null:stage::setup::setup");
      }
      
      /* virtual */
      setup::~setup()
      {
        TRACE("render::null:stage::setup::~setup");
      }

      /* virtual */ void
      setup::do_execute()
      {
        TRACE("render::null:stage::setup::do_execute");
        
        render::base::stage::setup::do_execute();
      }
      
    } // namespace stage {
    
  } // namespace null {
  
} // namespace render {
