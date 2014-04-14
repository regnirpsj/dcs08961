// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/select.cpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/node/select.hpp"

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
    select::select()
      : group(),
        index(*this, "index", 0)
    {
      TRACE("scene::node::select::select");
    }
    
    /* virtual */ void
    select::accept(visitor::base& v)
    {
      TRACE("scene::node::select::accept");

      v.visit(*this);
    }

    /* virtual */ void
    select::do_changed(field::base& f)
    {
      TRACE("scene::object::select::do_changed");

      if (&f == &index) {
        // nothing to do
      }

      else {
        group::do_changed(f);
      }
    }
    
  } // namespace node {
  
} // namespace scene {
