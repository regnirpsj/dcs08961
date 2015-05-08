// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/state/base.cpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/state/base.hpp"

// includes, system

//#include <>

// includes, project

#include <render/context.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace render {

  namespace state {
    
    // variables, exported
  
    // functions, exported

    /* virtual */
    base::~base()
    {
      TRACE("render::state::base::~base");
    }
    
    /* virtual */ void
    base::print_on(std::ostream& os) const
    {
      TRACE_NEVER("render::state::base::print_on");

      field::container::print_on(os);

      os << "\b,"
         << ctx_
         << ']';
    }

    /* explicit */
    base::base(context& a)
      : field::container   (),
        support::refcounted(),
        active             (*this, "active", true),
        name               (*this, "name",   "[render::state::base]"),
        ctx_               (a)
    {
      TRACE("render::state::base::base");
    }
    
  } // namespace state {
  
} // namespace render {
