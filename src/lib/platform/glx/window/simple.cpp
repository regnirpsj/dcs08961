// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glx/window/simple.cpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/glx/window/simple.hpp"

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

  namespace glx {

    namespace window {
  
      // variables, exported
  
      // functions, exported
      
      /* explicit */
      simple::simple(std::string const& a, rect const& b, std::string const& c,
                     attribute_list const& d)
        : base(a, b, c, d)
      {
        TRACE("platform::glx::window::simple::simple");
      }
      
    } // namespace window {
    
  } // namespace glx {
    
} // namespace platform {
