// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/state/raster.cpp                                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/state/raster.hpp"

// includes, system

//#include <>

// includes, project

//#include <>

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

  namespace state {
    
    // variables, exported
  
    // functions, exported

    /* virtual */
    raster::~raster()
    {
      TRACE("render::state::raster::~raster");
    }    

    /* explicit */
    raster::raster(context::device& a)
      : base(a)
    {
      TRACE("render::state::raster::raster");
    }
    
  } // namespace state {
  
} // namespace render {
