// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/shader/geometry.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/shader/geometry.hpp"

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

  namespace shader {
    
    // variables, exported
  
    // functions, exported

    /* virtual */
    geometry::~geometry()
    {
      TRACE("render::shader::geometry::~geometry");
    }

    /* explicit */
    geometry::geometry(device::context& a)
      : base(a)
    {
      TRACE("render::shader::geometry::geometry");
    }
    
  } // namespace shader {
  
} // namespace render {
