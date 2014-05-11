// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/context.cpp                                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/base/context.hpp"

// includes, system

#include <typeinfo> // typeid usage

// includes, project

#include <support/type_info.hpp>

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

  namespace base {
    
    // variables, exported
  
    // functions, exported

    /* virtual */
    context::~context()
    {
      TRACE("render::base::context::context");
    }
      
    /* virtual */ void
    context::print_on(std::ostream& os) const
    {
      TRACE_NEVER("render::base::context::print_on");

      os << '[' << support::demangle(typeid(*this)) << ']';
    }
    
  } // namespace base {
  
} // namespace render {
