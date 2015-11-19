// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  celestial/orbital/mercury.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "celestial/orbital/mercury.hpp"

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
    mercury::mercury(boost::posix_time::ptime const& a, double b)
      : base(a, b,
             {168.6562,   4.0923344368}, // M
             { 48.3313,   3.24587E-05},  // N
             {  0.387098, 0.0},          // a
             {  0.205635, 5.59E-10},     // e
             {  7.0047,   5.00E-08},     // i
             { 29.1241,   1.01444E-05})  // w
    {
      TRACE("celestial::orbital::mercury::mercury");
    }

  } // namespace orbital {
  
} // namespace celestial {
