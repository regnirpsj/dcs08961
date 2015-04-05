// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glut/window/helper.cpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "window/helper.hpp"

// includes, system

#include <sstream> // std::ostringstream

// includes, project

// #include <>

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

  namespace glut {

    namespace window {
  
      // variables, exported
  
      // functions, exported

      std::string
      exec_context(void const* ptr)
      {
        std::ostringstream ostr;

        ostr <<" (@" << ptr << ')';

        return ostr.str();
      }
      
    } // namespace window {

  } // namespace glut {
  
} // namespace platform {
