// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/mesh.cpp                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/node/mesh.hpp"

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

  namespace node {
    
    // variables, exported
    
    // functions, exported

    /* explicit */
    mesh::mesh(attribute_list_type const& a, index_list_type const& b)
      : geometry()
    {
      TRACE("scene::node::mesh::mesh");

      attribute_list_ = a;
      index_list_     = b;

      compute_bounds();
      compute_normals();
      compute_tangents();
    }
    
    /* virtual */ void
    mesh::accept(visitor::base& v)
    {
      TRACE("scene::node::mesh::accept");

      v.visit(*this);
    }

    void
    mesh::compute_normals()
    {
      TRACE("scene::node::mesh::accept");
    }
    
  } // namespace node {
  
} // namespace scene {
