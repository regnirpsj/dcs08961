// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/null/stage/draw.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/null/stage/draw.hpp"

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
      draw::draw(context& a)
        : render::base::stage::draw(a, stats::default_stats)
      {
        TRACE("render::null:stage::draw::draw");
      }
      
      /* virtual */
      draw::~draw()
      {
        TRACE("render::null:stage::draw::~draw");
      }

      /* virtual */ void
      draw::do_execute()
      {
        TRACE("render::null:stage::draw::do_execute");
        
        render::base::stage::draw::do_execute();
      }

    } // namespace stage {
    
  } // namespace null {
  
} // namespace render {
