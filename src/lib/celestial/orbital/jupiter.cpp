// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  celestial/orbital/jupiter.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "celestial/orbital/jupiter.hpp"

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
    jupiter::jupiter(boost::posix_time::ptime const& a, double b)
      : base(a, b,
             { 19.8950,    0.0830853001}, // M
             {100.4542,    2.76854E-05},  // N
             {  5.20256,   0.0},          // a
             {  0.048498,  4.469E-09},    // e
             {  1.3030,   -1.557E-07},    // i
             {273.8777,    1.64505E-05})  // w
    {
      TRACE("celestial::orbital::jupiter::jupiter");
    }
    
  } // namespace orbital {
  
} // namespace celestial {
