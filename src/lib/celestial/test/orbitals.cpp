// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  celestial/orbital/test/orbitals.cpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <boost/date_time/posix_time/posix_time.hpp> // boost::posix_time::ptime
#include <boost/io/ios_state.hpp>                    // boost::io::ios_flags_saver
#include <glm/gtx/io.hpp>                            // glm::operator<<

// includes, project

#include <celestial/orbitals.hpp>

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal

  boost::posix_time::ptime const dtime(// boost::posix_time::second_clock::local_time().date(),
                                       boost::gregorian::date(2000, 1, 1),
                                       boost::posix_time::hours(0));
  
  // functions, internal

  void
  print_orbital(celestial::orbital::base const& o)
  {
    boost::io::ios_flags_saver const ifs(std::cout);
    
    BOOST_MESSAGE(o << " @"
                  << glm::io::precision(2) << glm::io::width(1+2+1+2)
                  << o.distance_and_anomaly() << ':'
                  << glm::io::precision(2) << glm::io::width(1+1+1+2)
                  << o.coord_ecliptic_rect_geo() << ':'
                  << o.coord_equatorial_rect_geo());
  }
  
} // namespace {
  
// variables, exported

// functions, exported

BOOST_AUTO_TEST_CASE(test_celestial_orbital_moon)
{
  celestial::orbital::moon const m(dtime, 0.0);
  
  BOOST_CHECK(60.2666 == m.a);
  BOOST_CHECK(0.0549  == m.e);
  BOOST_CHECK(5.1454  == m.i);

  print_orbital(m);
}

BOOST_AUTO_TEST_CASE(test_celestial_orbital_sun)
{
  celestial::orbital::sun const s(dtime, 0.0);

  BOOST_CHECK(0.0 == s.N);
  BOOST_CHECK(1.0 == s.a);
  BOOST_CHECK(0.0 == s.i);

  print_orbital(s);
}

BOOST_AUTO_TEST_CASE(test_celestial_orbital_mercury)
{
  celestial::orbital::mercury const m(dtime, 0.0);

  BOOST_CHECK(0.387098 == m.a);

  print_orbital(m);
}

BOOST_AUTO_TEST_CASE(test_celestial_orbital_venus)
{
  celestial::orbital::venus const v(dtime, 0.0);

  BOOST_CHECK(0.723330 == v.a);

  print_orbital(v);
}

BOOST_AUTO_TEST_CASE(test_celestial_orbital_mars)
{
  celestial::orbital::mars const m(dtime, 0.0);

  BOOST_CHECK(1.523688 == m.a);

  print_orbital(m);
}

BOOST_AUTO_TEST_CASE(test_celestial_orbital_jupiter)
{
  celestial::orbital::jupiter const j(dtime, 0.0);

  BOOST_CHECK(5.20256 == j.a);

  print_orbital(j);
}

BOOST_AUTO_TEST_CASE(test_celestial_orbital_saturn)
{
  celestial::orbital::saturn const s(dtime, 0.0);

  BOOST_CHECK(9.55475 == s.a);

  print_orbital(s);
}

BOOST_AUTO_TEST_CASE(test_celestial_orbital_uranus)
{
  celestial::orbital::uranus const u(dtime, 0.0);

  BOOST_CHECK(true);

  print_orbital(u);
}

BOOST_AUTO_TEST_CASE(test_celestial_orbital_neptune)
{
  celestial::orbital::neptune const n(dtime, 0.0);

  BOOST_CHECK(true);

  print_orbital(n);
}
