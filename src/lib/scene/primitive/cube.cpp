// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/primitive/cube.cpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/primitive/cube.hpp"

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
    cube::cube(std::string const& a)
      : node::geometry(a)
    {
      TRACE("scene::primitive::cube::cube");
    }
    
    /* virtual */ void
    cube::accept(visitor::base& v)
    {
      TRACE("scene::primitive::cube::accept");

      v.visit(*this);
    }

  } // namespace primitive {
  
} // namespace scene {
