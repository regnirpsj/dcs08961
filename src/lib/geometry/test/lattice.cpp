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
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_geometry_lattice_ctor)
{
  using namespace geometry;

  lattice<glm::vec3, 4, 3, 2> const l;
  
  BOOST_CHECK(true);
  BOOST_MESSAGE(l << '\n');
}
