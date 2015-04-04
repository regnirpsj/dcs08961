// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/window/base.cpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/window/base.hpp"

// includes, system

#include <sstream> // std::ostringstream

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

namespace platform {

  namespace window {
  
    // variables, exported
  
    // functions, exported

    /* virtual */
    base::~base()
    {
      TRACE("platform::window::base::~base");
    }
    
    /* virtual */ void
    base::print_on(std::ostream& os) const
    {
      TRACE_NEVER(platform::window::base::print_on);

      os << "[title:'" << title_ << "']";
    }

    /* explicit */
    base::base(std::string const& a, rect const&)
      : boost::noncopyable(),
        support::printable(),
        title_            (a)
    {
      TRACE("platform::window::base::base");
    }
    
  } // namespace window {
  
} // namespace platform {
