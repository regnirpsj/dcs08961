// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  celestial/orbital/base.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_CELESTIAL_ORBITAL_BASE_HPP)

#define UKACHULLDCS_08961_CELESTIAL_ORBITAL_BASE_HPP

// includes, system

#include <boost/date_time/posix_time/posix_time.hpp> // boost::posix_time::ptime
#include <glm/glm.hpp>                               // glm::radians<>
#include <utility>                                   // std::pair<>

// includes, project

#include <celestial/export.h>
#include <support/printable.hpp>

namespace celestial {

  namespace orbital {
  
    // types, exported (class, enum, struct, union, typedef)

    /**
     * see [http://stjarnhimlen.se/comp/ppcomp.html]
     */
    class DCS08961_CELESTIAL_EXPORT base : public support::printable {

    public:
      
      double const d; // d.hms since 2000 Jan 0.0 UT
      
      double const M; // mean anomaly (0 at perihelion; increases uniformly with time)
      double const N; // longitude of the ascending node
      double const a; // semi-major axis, or mean distance from Sun
      double const e; // eccentricity (0=circle, 0-1=ellipse, 1=parabola)
      double const i; // inclination to the ecliptic (plane of the Earth's orbit)
      double const w; // argument of perihelion

      double const ecl; // obliquity of the ecliptic, i.e. "tilt" of the earth's axis of rotation
      
      /**
       * computes distance and true anomaly
       *
       * return glm::vec2(distance, anomaly)
       */
      virtual glm::vec2 distance_and_anomaly() const;

      virtual glm::vec3 coord_ecliptic_rect_geo() const;
      virtual glm::vec3 coord_equatorial_rect_geo() const;
      
      virtual void print_on(std::ostream&) const;
      
    protected:

      using constant_pair = std::pair<double, double>;
      
      explicit base(boost::posix_time::ptime const& /* date/time */,
                    double                          /* longitude */,
                    constant_pair const&            /* M         */,
                    constant_pair const&            /* N         */,
                    constant_pair const&            /* a         */,
                    constant_pair const&            /* e         */,
                    constant_pair const&            /* i         */,
                    constant_pair const&            /* w         */);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)
    
  } // namespace orbital {
  
} // namespace celestial {

#endif // #if !defined(UKACHULLDCS_08961_CELESTIAL_ORBITAL_BASE_HPP)
