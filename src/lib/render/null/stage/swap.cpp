// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/null/stage/swap.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/null/stage/swap.hpp"

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
      swap::swap()
        : render::base::stage::swap(context::dflt, stats::dflt)
      {
        TRACE("render::null:stage::swap::swap");
      }
      
      /* virtual */
      swap::~swap()
      {
        TRACE("render::null:stage::swap::~swap");
      }

      /* virtual */ void
      swap::do_execute()
      {
        TRACE("render::null:stage::swap::do_execute");
        
        render::base::stage::swap::do_execute();
      }
      
    } // namespace stage {
    
  } // namespace null {
  
} // namespace render {
