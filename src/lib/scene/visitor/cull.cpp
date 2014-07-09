// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/visitor/cull.cpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/visitor/cull.hpp"

// includes, system

#include <ostream> // std::ostream

// includes, project

#include <scene/node/geometry.hpp>
#include <scene/node/group.hpp>

#define UKACHULLDCS_USE_TRACE
//#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace scene {

  namespace visitor {

    // variables, exported
  
    // functions, exported

    /* explicit */
    cull::cull(node::camera const& a)
      : dfs    (),
        camera_(a)
    {
      TRACE("scene::visitor::cull::cull");
    }
    
    /* virtual */
    cull::~cull()
    {
      TRACE("scene::visitor::cull::~cull");
    }
    
    /* virtual */ void
    cull::visit(node::geometry&)
    {
      TRACE("scene::visitor::cull::visit(node::geometry)");
    }
    
    /* virtual */ void
    cull::visit(node::group& a)
    {
      TRACE("scene::visitor::cull::visit(node::group)");

      dfs::visit(a);
    }
    
    /* virtual */ void
    cull::print_on(std::ostream& os) const
    {
      TRACE_NEVER("scene::visitor::cull::print_on");

      dfs::print_on(os);
    }
          
    /* virtual */ void
    cull::visit(subject&)
    {
      TRACE("scene::visitor::cull::visit(subject)");
    }
    
  } // namespace visitor {
  
} // namespace scene {

