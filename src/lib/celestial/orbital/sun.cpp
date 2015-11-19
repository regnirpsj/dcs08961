// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  celestial/orbital/sun.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "celestial/orbital/sun.hpp"

// includes, system

#include <cmath>                  // std::* math
#include <glm/gtc/constants.hpp>  // glm::pi<>

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

  double
  rev(double a)
  {
    return a - std::floor(a / glm::two_pi<double>()) * glm::two_pi<double>();
  }
  
} // namespace {

namespace celestial {

  namespace orbital {
  
    // variables, exported
  
    // functions, exported

    /* explicit */
    sun::sun(boost::posix_time::ptime const& a, double b)
      : base(a, b,
             {356.0470,    0.9856002585}, // M
             {  0.0,       0.0},          // N
             {  1.0,       0.0},          // a
             {  0.016709, -1.151E-09},    // e
             {  0.0,       0.0},          // i
             {282.9404,    4.70935E-5})   // w
    {
      TRACE("celestial::orbital::sun::sun");
    }

    /* virtual */ glm::vec2
    sun::distance_and_anomaly() const
    {
      TRACE("celestial::orbital::sun::distance_and_anomaly");
      
      double const E (M + e * std::sin(M) * (1.0 + e * std::cos(M)));
      double const xv(std::cos(E) - e);
      double const yv(std::sin(E) * std::sqrt(1.0 - (e * e)));
    
      return glm::vec2(std::atan2(yv, xv),                // r
                       std::sqrt((xv * xv) + (yv * yv))); // v
    }

    /* virtual */ glm::vec3
    sun::coord_ecliptic_rect_geo() const
    {
      TRACE("celestial::orbital::sun::coord_ecliptic_rect_geo");
      
      glm::vec2 const rv  (distance_and_anomaly());
      double const    slon(rev(rv.y + w));
      
      return glm::vec3(rv.x * std::cos(slon),
                       rv.x * std::sin(slon),
                       0.0);
    }
    
    /* virtual */ glm::vec3
    sun::coord_equatorial_rect_geo() const
    {
      TRACE("celestial::orbital::sun::coord_equatorial_rect_geo");
      
      glm::vec3 const coord_ecl(coord_ecliptic_rect_geo());
      
      return glm::vec3(coord_ecl.x,
                       coord_ecl.y * std::cos(ecl),
                       coord_ecl.y * std::sin(ecl));
    }

  } // namespace orbital {
  
} // namespace celestial {
