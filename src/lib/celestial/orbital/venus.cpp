// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  celestial/orbital/venus.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "celestial/orbital/venus.hpp"

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

namespace celestial {

  namespace orbital {
  
    // variables, exported
  
    // functions, exported
    
    /* explicit */
    venus::venus(boost::posix_time::ptime const& a, double b)
      : base(a, b,
             {48.0052,    1.6021302244}, // M
             {76.6799,    2.46590E-5},   // N
             { 0.723330,  0.0},          // a
             { 0.006773, -1.302E-9},     // e
             { 3.3946,    2.75E-8},      // i
             {54.8910,    1.38374E-5})   // w
    {
      TRACE("celestial::orbital::venus::venus");
    }

  } // namespace orbital {
  
} // namespace celestial {
