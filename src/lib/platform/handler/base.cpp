// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/handler/base.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/handler/base.hpp"

// includes, system

//#include <>

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

  namespace handler {
  
    // variables, exported

    /* static */ unsigned const base::dflt_queue_max_length(3);
    
    // functions, exported

    /* virtual */
    base::~base()
    {
      TRACE("platform::handler::base::~base");
    }

    /* explicit */
    base::base()
    {
      TRACE("platform::handler::base::base");
    }
    
  } // namespace handler {
  
} // namespace platform {
