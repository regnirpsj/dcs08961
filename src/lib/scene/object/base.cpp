// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/base.cpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/object/base.hpp"

// includes, system

#include <ostream> // std::ostream

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

namespace scene {

  namespace object {
    
    // variables, exported
  
    // functions, exported

    /* virtual */
    base::~base()
    {
      TRACE("scene::object::base::~base");
    }
    
    /* virtual */ void
    base::print_on(std::ostream& os) const
    {
      TRACE_NEVER("scene::object::base::print_on");

      os << '[';
      
      field::container::print_on(os);

      os << ','
         << "rc:" << use_count()
         << ']';
    }
    
    /* explicit */
    base::base()
      : field::container         (),
        support::refcounted<base>(),
        name                     (*this, "name", "")
    {
      TRACE("scene::object::base::base");
    }
    
    /* virtual */ void
    base::do_changed(field::base& f)
    {
      TRACE("scene::object::base::do_changed");

      if (&f == &name) {
        // nothing to do
      }

      else {
        field::container::do_changed(f);
      }
    }
    
  } // namespace object {
  
} // namespace scene {
