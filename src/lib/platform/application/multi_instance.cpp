// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/application/multi_instance.cpp                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/application/multi_instance.hpp"

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

  namespace application {
  
    // variables, exported
  
    // functions, exported

    /* explicit */
    multi_instance::multi_instance(command_line const& a)
      : base(a)
    {
      TRACE("platform::application::multi_instance::multi_instance");
    }

    /* virtual */
    multi_instance::~multi_instance()
    {
      TRACE("platform::application::multi_instance::~multi_instance");
    }

  } // namespace application {
  
} // namespace platform {
