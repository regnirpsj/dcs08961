// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  celestial/orbital/moon.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_CELESTIAL_ORBITAL_MOON_HPP)

#define UKACHULLDCS_08961_CELESTIAL_ORBITAL_MOON_HPP

// includes, system

// #include <>

// includes, project

#include <celestial/orbital/base.hpp>

namespace celestial {

  namespace orbital {
  
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_CELESTIAL_EXPORT moon : public base {

    public:
      
      explicit moon(boost::posix_time::ptime const& /* date/time */,
                    double                          /* longitude */ = 0.0);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)
  
  } // namespace orbital {
  
} // namespace celestial {

#endif // #if !defined(UKACHULLDCS_08961_CELESTIAL_ORBITAL_MOON_HPP)
