// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  celestial/orbital/moon.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "celestial/orbital/moon.hpp"

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
    moon::moon(boost::posix_time::ptime const& a, double b)
      : base(a, b,
             {115.3654, 13.0649929509}, // M
             {125.1228, -0.0529538083}, // N
             { 60.2666,  0.0},          // a
             {  0.0549,  0.0},          // e
             {  5.1454,  0.0},          // i
             {318.0634,  0.1643573223}) // w
    {
      TRACE("celestial::orbital::moon::moon");
    }

  } // namespace orbital {
  
} // namespace celestial {
