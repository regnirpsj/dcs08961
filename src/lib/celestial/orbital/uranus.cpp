// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  celestial/orbital/uranus.cpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "celestial/orbital/uranus.hpp"

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
    uranus::uranus(boost::posix_time::ptime const& a, double b)
      : base(a, b,
             {142.5905,   0.011725806}, // M
             { 74.0005,   1.3978E-05},  // N
             { 19.18171, -1.55E-08},    // a
             {  0.047318, 7.45E-09},    // e
             {  0.7733,   1.9E-08},     // i
             { 96.6612,   3.0565E-05})  // w
    {
      TRACE("celestial::orbital::uranus::uranus");
    }

  } // namespace orbital {
  
} // namespace celestial {
