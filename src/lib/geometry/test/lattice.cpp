// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
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

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1800))
  constexpr
#endif
  unsigned const dflt[3] = { 5, 3, 2 };
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_geometry_lattice_ctor)
{
  using ltype = geometry::lattice<glm::vec3, dflt[0], dflt[1], dflt[2]>;

  glm::vec3 const v(0,1,2);
  ltype const     l(v);
  
  BOOST_CHECK  (v == l.at(0,0,0));
}

BOOST_AUTO_TEST_CASE(test_geometry_lattice_print_on)
{
  using ltype = geometry::lattice<glm::vec3, 1, 2, 3>;

  ltype const l;
  
  BOOST_CHECK  (true);
  BOOST_MESSAGE(glm::io::precision(1) << glm::io::width(3) << l);
}

BOOST_AUTO_TEST_CASE(test_geometry_lattice_at)
{
  using ltype = geometry::lattice<glm::vec3, dflt[0], dflt[1], dflt[2]>;

  {
    ltype const l;
    
    BOOST_CHECK  (ltype::value_type() == l.at(0,0,0));
  }

  {
    glm::vec3 const v(1,-1,1);
    ltype           l;
    
    l.at(0,0,0) = v;
    
    BOOST_CHECK  (v == l.at(0,0,0));
  }

  {
    ltype l;
  
    BOOST_CHECK_THROW(l.at(dflt[0], dflt[1], dflt[2]), std::range_error);
  }

  {
    ltype const l;

    BOOST_CHECK_THROW(l.at(dflt[0], dflt[1], dflt[2]), std::range_error);
  }
}
