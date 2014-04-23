// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  geometry/test/lattice.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/glm.hpp>    // glm::vec3
#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <geometry/lattice.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

#if !defined(_MSC_VER) || (_MSC_VER > 1700)
  constexpr unsigned const dflt[3] = { 5, 3, 2 };
#else
            unsigned const dflt[3] = { 5, 3, 2 };
#endif
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_geometry_lattice_ctor)
{
  using namespace geometry;

  typedef lattice<glm::vec3, dflt[0], dflt[1], dflt[2]> ltype;

  glm::vec3 const v(0,1,2);
  ltype const     l(v);
  
  BOOST_CHECK(v == l.at(0,0,0));
  BOOST_MESSAGE(glm::io::precision(1) << glm::io::width(4) << l);
}

BOOST_AUTO_TEST_CASE(test_geometry_lattice_at)
{
  using namespace geometry;

  typedef lattice<glm::vec3, dflt[0], dflt[1], dflt[2]> ltype;
  
  {
    ltype const l;
    
    BOOST_CHECK(ltype::value_type() == l.at(0,0,0));
  }

  {
    glm::vec3 const v(1,-1,1);
    ltype           l;

    l.at(0,0,0) = v;
    
    BOOST_CHECK(v == l.at(0,0,0));
  }
}
