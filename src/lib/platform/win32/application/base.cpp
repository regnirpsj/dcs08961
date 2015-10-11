// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/win32/application/base.cpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/win32/application/base.hpp"

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
  
  namespace win32 {
    
    namespace application {
      
      // variables, exported
      
      // functions, exported
      
      /* explicit */
      base::base(platform::application::command_line const& a)
        : platform::application::single_instance(a)
      {
        TRACE("platform::win32::application::base");
      }
      
    } // namespace application {
    
  } // namespace win32 {
  
} // namespace platform {
