// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/null/stage/clear.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/null/stage/clear.hpp"

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
      clear::clear()
        : render::base::stage::clear(context::dflt, stats::dflt)
      {
        TRACE("render::null:stage::clear::clear");
      }
      
      /* virtual */
      clear::~clear()
      {
        TRACE("render::null:stage::clear::~clear");
      }

      /* virtual */ void
      clear::do_execute()
      {
        TRACE("render::null:stage::clear::do_execute");
        
        render::base::stage::clear::do_execute();
      }

    } // namespace stage {
    
  } // namespace null {
  
} // namespace render {
