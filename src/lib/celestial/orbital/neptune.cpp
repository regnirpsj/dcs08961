// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  celestial/orbital/neptune.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "celestial/orbital/neptune.hpp"

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
    neptune::neptune(boost::posix_time::ptime const& a, double b)
      : base(a, b,
             {260.2471,    0.005995147}, // M
             {131.7806,    3.0173E-05},  // N
             { 30.05826,   3.313E-08},   // a
             {  0.008606,  2.15E-09},    // e
             {  1.7700,   -2.55E-07},    // i
             {272.8461,   -6.027E-06})   // w
    {
      TRACE("celestial::orbital::neptune::neptune");
    }
    
  } // namespace orbital {
  
} // namespace celestial {
