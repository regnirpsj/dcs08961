// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  celestial/orbital/sun.hpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_CELESTIAL_ORBITAL_SUN_HPP)

#define UKACHULLDCS_08961_CELESTIAL_ORBITAL_SUN_HPP

// includes, system

// #include <>

// includes, project

#include <celestial/orbital/base.hpp>

namespace celestial {

  namespace orbital {
  
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_CELESTIAL_EXPORT sun : public base {

    public:
      
      explicit sun(boost::posix_time::ptime const& /* date/time */,
                   double                          /* longitude */ = 0.0);

      /**
       * computes distance and true anomaly
       *
       * return glm::vec2(distance, anomaly)
       */
      virtual glm::vec2 distance_and_anomaly() const;

      virtual glm::vec3 coord_ecliptic_rect_geo  () const;
      virtual glm::vec3 coord_equatorial_rect_geo() const;

    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)
  
  } // namespace orbital {
  
} // namespace celestial {

#endif // #if !defined(UKACHULLDCS_08961_CELESTIAL_ORBITAL_SUN_HPP)
