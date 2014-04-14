// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/primitive/octahedron.cpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/primitive/octahedron.hpp"

// includes, system

//#include <>

// includes, project

#include <scene/visitor/base.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace scene {

  namespace primitive {
    
    // variables, exported
    
    // functions, exported

    /* explicit */
    octahedron::octahedron()
      : node::geometry()
    {
      TRACE("scene::primitive::octahedron::octahedron");
    }
    
    /* virtual */ void
    octahedron::accept(visitor::base& v)
    {
      TRACE("scene::primitive::octahedron::accept");

      v.visit(*this);
    }
    
  } // namespace primitive {
  
} // namespace scene {
