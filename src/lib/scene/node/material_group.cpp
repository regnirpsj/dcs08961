// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/material_group.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/node/material_group.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

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
    material_group::material_group(std::string const& a, object::material::rep const& b)
      : group   (a),
        material(*this, "material", new object::material(a, b))
    {
      TRACE("scene::node::global_light::global_light");
    }
    
    /* virtual */ void
    material_group::accept(visitor::base& v)
    {
      TRACE("scene::node::global_light::accept");

      v.visit(*this);
    }
    
  } // namespace node {
  
} // namespace scene {
