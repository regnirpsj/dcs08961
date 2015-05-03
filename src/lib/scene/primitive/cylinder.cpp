// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
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

  void
  make_cylinder(unsigned                                    /* sides */,
                scene::node::geometry::attribute_list_type& /* attr_list */,
                scene::node::geometry::index_list_type&     /* index_list */)
  {
    TRACE("scene::primitive::cylinder::<unnamed>::make_cylinder");
  }
  
} // namespace {

namespace scene {

  namespace primitive {
    
    // variables, exported
    
    // functions, exported

    /* explicit */
    cylinder::cylinder(unsigned a)
      : node::geometry(),
        sides         (*this, "sides", a)
    {
      TRACE("scene::primitive::cylinder::cylinder");
      
      sides.touch();
    }
    
    /* virtual */ void
    cylinder::accept(visitor::base& v)
    {
      TRACE("scene::primitive::cylinder::accept");

      v.visit(*this);
    }

    /* virtual */ void
    cylinder::do_changed(field::base& f)
    {
      TRACE("scene::primitive::cylinder::do_changed");
      
      if (&f == &sides) {
        make_cylinder(*sides, attribute_list_, index_list_);
        
        compute_bounds();
        compute_tangents();
      }

      else {
        node::geometry::do_changed(f);
      }
    }
    
  } // namespace primitive {
  
} // namespace scene {
