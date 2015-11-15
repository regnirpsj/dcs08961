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

  namespace context {
      
    // variables, exported
  
    // functions, exported

    /* virtual */
    base::~base()
    {
      TRACE("render::context::base::~base");
    }
    
    /* virtual */ void
    base::print_on(std::ostream& os) const
    {
      TRACE_NEVER("render::context::base::print_on");

      boost::io::ios_all_saver const ias(os);
    
      os << "[render::context::base@" << std::hex << this << ']';
    }

    /* explicit */
    base::base()
      : support::printable       (),
        support::refcounted<base>()
    {
      TRACE("render::context::base::base");
    }

    /* virtual */
    device::~device()
    {
      TRACE("render::context::device::~device");
    }
    
    /* virtual */ void
    device::print_on(std::ostream& os) const
    {
      TRACE_NEVER("render::context::device::print_on");

      boost::io::ios_all_saver const ias(os);
    
      os << "[render::context::device@" << std::hex << this << ']';
    }

    /* explicit */
    device::device()
      : base()
    {
      TRACE("render::context::device::device");
    }

    /* virtual */
    swap::~swap()
    {
      TRACE("render::context::swap::~swap");
    }
    
    /* virtual */ void
    swap::print_on(std::ostream& os) const
    {
      TRACE_NEVER("render::context::swap::print_on");

      boost::io::ios_all_saver const ias(os);
    
      os << "[render::context::swap@" << std::hex << this << ']';
    }

    /* explicit */
    swap::swap()
      : base()
    {
      TRACE("render::context::swap::swap");
    }

  } // namespace context {

} // namespace render {
