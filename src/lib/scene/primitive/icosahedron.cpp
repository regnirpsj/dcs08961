// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/primitive/icosahedron.cpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/primitive/icosahedron.hpp"

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

  void
  make_icosahedron(scene::node::geometry::attribute_list_type& /* attr_list */,
                   scene::node::geometry::index_list_type&     /* index_list */)
  {
    TRACE("scene::primitive::icosahedron::<unnamed>::make_icosahedron");
  }
  
} // namespace {

namespace scene {

  namespace primitive {
    
    // variables, exported
    
    // functions, exported

    /* explicit */
    icosahedron::icosahedron()
      : node::geometry()
    {
      TRACE("scene::primitive::icosahedron::icosahedron");

      make_icosahedron(attribute_list_, index_list_);
      
      compute_bounds();
      compute_tangents();
    }
    
    /* virtual */ void
    icosahedron::accept(visitor::base& v)
    {
      TRACE("scene::primitive::icosahedron::accept");

      v.visit(*this);
    }
    
  } // namespace primitive {
  
} // namespace scene {
