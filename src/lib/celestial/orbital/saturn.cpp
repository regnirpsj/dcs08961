// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  celestial/orbital/saturn.cpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "celestial/orbital/saturn.hpp"

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
    saturn::saturn(boost::posix_time::ptime const& a, double b)
      : base(a, b,
             {316.9670,    0.0334442282}, // M
             {113.6634,    2.38980E-05},  // N
             {  9.55475,   0.0},          // a
             {  0.055546, -9.499E-09},    // e
             {  2.4886,   -1.081E-07},    // i
             {339.3939,    2.97661E-05})  // w
    {
      TRACE("celestial::orbital::saturn::saturn");
    }

  } // namespace orbital {
  
} // namespace celestial {
