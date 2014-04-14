// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/primitive/cylinder.cpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/primitive/cylinder.hpp"

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
    cylinder::cylinder()
      : node::geometry()
    {
      TRACE("scene::primitive::cylinder::cylinder");
    }
    
    /* virtual */ void
    cylinder::accept(visitor::base& v)
    {
      TRACE("scene::primitive::cylinder::accept");

      v.visit(*this);
    }
    
  } // namespace primitive {
  
} // namespace scene {
