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

#include <stdexcept> // std::logic_error

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
    base::apply() const
    {
      TRACE("render::state::base::apply");

      if (*active) {
        do_apply();
      }
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
    base::base(context::device& a)
      : field::container         (),
        support::refcounted<base>(),
        active                   (*this, "active", true),
        name                     (*this, "name",   "[render::state::base]"),
        ctx_                     (a)
    {
      TRACE("render::state::base::base");
    }

    /* virtual */ void
    base::do_apply() const
    {
      TRACE("render::state::base::do_apply");
      
      throw std::logic_error("pure virtual function 'render::state::base::do_apply' called");
    }
    
  } // namespace state {
  
} // namespace render {
