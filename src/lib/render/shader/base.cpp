// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/shader/base.cpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/shader/base.hpp"

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

  namespace shader {
    
    // variables, exported
  
    // functions, exported

    /* virtual */
    base::~base()
    {
      TRACE("render::shader::base::~base");
    }
    
    void
    base::activate()
    {
      TRACE("render::shader::base::activate");

      if (*active) {
        do_activate();
      }
    }
    
    /* virtual */ void
    base::print_on(std::ostream& os) const
    {
      TRACE_NEVER("render::shader::base::print_on");

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
        name                     (*this, "name",   "[render::shader::base]"),
        ctx_                     (a)
    {
      TRACE("render::shader::base::base");
    }

    /* virtual */ void
    base::do_activate()
    {
      TRACE("render::shader::base::do_activate");

      throw std::logic_error("pure virtual function 'render::shader::base::do_activate' called");
    }
    
  } // namespace shader {
  
} // namespace render {
