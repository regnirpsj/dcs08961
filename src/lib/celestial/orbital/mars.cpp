// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  celestial/orbital/mars.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "celestial/orbital/mars.hpp"

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
    mars::mars(boost::posix_time::ptime const& a, double b)
      : base(a, b,
             { 18.6021,    0.5240207766}, // M
             { 49.5574,    2.11081E-05},  // N
             {  1.523688,  0.0},          // a
             {  0.093405,  2.516E-09},    // e
             {  1.8497,   -1.78E-08},     // i
             {286.5016,    2.92961E-05})  // w
    {
      TRACE("celestial::orbital::mars::mars");
    }

  } // namespace orbital {
  
} // namespace celestial {
