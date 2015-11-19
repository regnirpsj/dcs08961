// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  celestial/orbital/base.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "celestial/orbital/base.hpp"

// includes, system

#include <boost/io/ios_state.hpp> // boost::io::ios_flags_saver
#include <cmath>                  // std::* math
#include <iomanip>                // std::fixed, std::setfill, std::setw, std::setprecision
#include <ostream>                // std::ostream

// includes, project

#include <glm/gtx/utilities.hpp> // glm::sgn<>, glm::rev<>
#include <support/type_info.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal
  
  double
  adjusted_time_from_gmt(boost::posix_time::ptime const& dtime)
  {
    double const y(dtime.date().year());
    double const m(dtime.date().month());

    double result(367 * y);

    result -= 7 * (y + (m + 9) / 12) / 4;
    result += (275 * m) / 9;
    result += dtime.date().day();
    result -= 730530 + 0.0972222221;
    
    struct tm const pt_tm(boost::posix_time::to_tm(dtime));

    result += (pt_tm.tm_hour + (pt_tm.tm_min / 60.0) + (pt_tm.tm_sec / 3600.0)) / 24.0;

    return result;
  }

  double
  adjusted_time_from_local(boost::posix_time::ptime const& dtime, double lon)
  {
    double const tz(glm::sgn(lon) * std::floor(std::abs(lon) / glm::radians(15.0)));

    return adjusted_time_from_gmt(dtime - boost::posix_time::hours(tz));
  }
  
} // namespace {

namespace celestial {

  namespace orbital {
  
    // variables, exported

    // functions, exported

    /* virtual */ glm::vec2
    base::distance_and_anomaly() const
    {
      TRACE("celestial::orbital::base::distance_and_anomaly");
      
      double E0(M + e * std::sin(M) * (1.0 + e * std::cos(M)));
      double E1(E0 - (E0 - e * std::sin(E0) - M) / (1.0 - e * std::cos(E0)));

      while (glm::radians(0.001) < std::abs(E0 - E1)) {
        E0 = E1;
        E1 = E0 - (E0 - e * std::sin(E0) - M) / (1.0 - e * std::cos(E0));
      }

      double const xv(a * (std::cos(E1) - e));
      double const yv(a * std::sqrt(1.0 - (e * e)) * std::sin(E1));
      
      return glm::vec2(glm::rev(std::atan2(yv, xv)),           // r
                       std::sqrt((xv * xv) + (yv * yv))); // v
    }
    
    /* virtual */ glm::vec3
    base::coord_ecliptic_rect_geo() const
    {
      TRACE("celestial::orbital::base::coord_ecliptic_rect_geo");
      
      glm::vec2 const rv(distance_and_anomaly());
      double const    xh(rv.x * (std::cos(N) * std::cos(rv.y+w) -
                                 std::sin(N) * std::sin(rv.y+w) * std::cos(i)));
      double const    yh(rv.x * (std::sin(N) * std::cos(rv.y+w) +
                                 std::cos(N) * std::sin(rv.y+w) * std::cos(i)));
      double const    zh(rv.x * std::sin(rv.y+w) * std::sin(i));
    
      return glm::vec3(xh, yh, zh);
    }
    
    /* virtual */ glm::vec3
    base::coord_equatorial_rect_geo() const
    {
      TRACE("celestial::orbital::base::coord_equatorial_rect_geo");
      
      return coord_ecliptic_rect_geo();
    }

    /* virtual */ void
    base::print_on(std::ostream& os) const
    {
      TRACE_NEVER("celestial::orbital::base::print_on");

      static unsigned const precision   (3);
      static unsigned const value_width (1 + 4 + 1 + precision); // sign + value + '.' + remainder

      std::string const name(support::demangle(typeid(*this)));
      
      boost::io::ios_flags_saver const ifs(os);
      {
        os << '['
           << name
           << std::string(std::max(std::string::size_type(0), 27 - name.length()), ' ')
           << ':'
           << std::fixed << std::setprecision(precision)
           << "d:" << std::right << std::setfill(' ') << std::setw(value_width) << d << ','
           << "M:" << std::right << std::setfill(' ') << std::setw(value_width) << M << ','
           << "N:" << std::right << std::setfill(' ') << std::setw(value_width) << N << ','
           << "a:" << std::right << std::setfill(' ') << std::setw(value_width) << a << ','
           << "e:" << std::right << std::setfill(' ') << std::setw(value_width) << e << ','
           << "i:" << std::right << std::setfill(' ') << std::setw(value_width) << i << ','
           << "w:" << std::right << std::setfill(' ') << std::setw(value_width) << w
           << ']';
      }
    }
    
    /* explicit */
    base::base(boost::posix_time::ptime const& a, double b,
               constant_pair const& mp, constant_pair const& np, constant_pair const& ap,
               constant_pair const& ep, constant_pair const& ip, constant_pair const& wp)
      : d  (adjusted_time_from_local(a, b)),
        M  (mp.first + (mp.second * d)),
        N  (np.first + (np.second * d)),
        a  (ap.first + (ap.second * d)),
        e  (ep.first + (ep.second * d)),
        i  (ip.first + (ip.second * d)),
        w  (wp.first + (wp.second * d)),
        ecl(glm::radians(23.4393) - (glm::radians(3.563E-7) * d))
    {
      TRACE("celestial::orbital::base::base");
    }
    
  } // namespace orbital {
  
} // namespace celestial {
