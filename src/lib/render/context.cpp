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
    
  // variables, exported
  
  // functions, exported

  /* virtual */
  context::~context()
  {
    TRACE("render::context::~context");
  }
    
  /* virtual */ void
  context::print_on(std::ostream& os) const
  {
    TRACE_NEVER("render::context::print_on");

    boost::io::ios_all_saver const ias(os);
    
    os << "[render::context@" << std::hex << this << ']';
  }

  /* explicit */
  context::context()
    : boost::noncopyable(),
      support::printable()
  {
    TRACE("render::context::context");
  }
  
} // namespace render {
