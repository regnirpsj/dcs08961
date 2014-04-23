// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  geometry/test/triangle.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <cmath>                 // std::sqrt<>
#include <glm/gtx/io.hpp>        // glm::operator<<
#include <glm/gtx/transform.hpp> // glm::scale

// includes, project

#include <geometry/triangle.hpp>

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

BOOST_AUTO_TEST_CASE(test_geometry_triangle_ctor)
{
  using namespace geometry;

  triangle const t(glm::vec3(1,2,3), glm::vec3(4,5,6), glm::vec3(7,8,9));
  
  BOOST_CHECK(glm::vec3(1,2,3) == t.p0);
  BOOST_CHECK(glm::vec3(4,5,6) == t.p1);
  BOOST_CHECK(glm::vec3(7,8,9) == t.p2);
}

BOOST_AUTO_TEST_CASE(test_geometry_triangle_area)
{
  using namespace geometry;

  triangle const t(glm::vec3(0,0,0), glm::vec3(2,0,0), glm::vec3(0,2,0));
  
  BOOST_CHECK(std::numeric_limits<float>::epsilon() > std::abs(2.0 - t.area()));
}

BOOST_AUTO_TEST_CASE(test_geometry_triangle_normal)
{
  using namespace geometry;

  triangle const t;
  
  BOOST_CHECK(glm::vec3(0,0,1) == t.normal());
  BOOST_CHECK(glm::length(glm::vec3(0,0,1)) == glm::length(t.normal()));
}

BOOST_AUTO_TEST_CASE(test_geometry_triangle_op_assign_mult)
{
  using namespace geometry;

  triangle t;

  t *= glm::scale(glm::vec3(-1,-1,-1));
  
  BOOST_CHECK(glm::vec3( 0, 0,0) == t.p0);
  BOOST_CHECK(glm::vec3(-1, 0,0) == t.p1);
  BOOST_CHECK(glm::vec3( 0,-1,0) == t.p2);
}

BOOST_AUTO_TEST_CASE(test_geometry_triangle_op_mult)
{
  using namespace geometry;

  glm::mat4 const xform(glm::scale(glm::vec3(-1,-1,-1)));
  
  {
    triangle t(triangle() * xform);
  
    BOOST_CHECK(glm::vec3( 0, 0,0) == t.p0);
    BOOST_CHECK(glm::vec3(-1, 0,0) == t.p1);
    BOOST_CHECK(glm::vec3( 0,-1,0) == t.p2);
    BOOST_CHECK(std::numeric_limits<float>::epsilon() > std::abs(0.5 - t.area()));
  }
  
  {
    triangle t(xform * triangle());
  
    BOOST_CHECK(glm::vec3( 0, 0,0) == t.p0);
    BOOST_CHECK(glm::vec3(-1, 0,0) == t.p1);
    BOOST_CHECK(glm::vec3( 0,-1,0) == t.p2);
    BOOST_CHECK(std::numeric_limits<float>::epsilon() > std::abs(0.5 - t.area()));
  }
}
