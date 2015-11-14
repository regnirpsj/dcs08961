// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/context.cpp                                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/context.hpp"

// includes, system

#include <boost/io/ios_state.hpp> // boost::io::ios_all_saver

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

namespace render {

  namespace device {
      
    // variables, exported
  
    // functions, exported

    /* virtual */
    context::~context()
    {
      TRACE("render::device::context::~context");
    }
    
    /* virtual */ void
    context::print_on(std::ostream& os) const
    {
      TRACE_NEVER("render::device::context::print_on");

      boost::io::ios_all_saver const ias(os);
    
      os << "[render::device::context@" << std::hex << this << ']';
    }

    /* explicit */
    context::context()
      : support::printable(),
        support::refcounted<context>()
    {
      TRACE("render::device::context::context");
    }

  } // namespace device {
  
  namespace swap {
      
    // variables, exported
  
    // functions, exported

    /* virtual */
    context::~context()
    {
      TRACE("render::swap::context::~context");
    }
    
    /* virtual */ void
    context::print_on(std::ostream& os) const
    {
      TRACE_NEVER("render::swap::context::print_on");

      boost::io::ios_all_saver const ias(os);
    
      os << "[render::swap::context@" << std::hex << this << ']';
    }

    /* explicit */
    context::context()
      : support::printable(),
        support::refcounted<context>()
    {
      TRACE("render::swap::context::context");
    }

  } // namespace swap {

} // namespace render {
