// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/test/primitive_sphere.cpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <scene/primitive/sphere.hpp>

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

BOOST_AUTO_TEST_CASE(test_scene_primitive_sphere_ctor)
{
  using namespace scene::primitive;
  
  sphere const c;
  
  BOOST_CHECK(true);
  BOOST_MESSAGE(c << '\n');
}

BOOST_AUTO_TEST_CASE(test_scene_primitive_sphere_subdiv)
{
  using namespace scene::primitive;
  
  sphere c;

  BOOST_MESSAGE(c << '\n');
  
  for (unsigned i(4); i < 11; ++i) {
    c.subdivision = i;
  
    BOOST_CHECK(i == *c.subdivision);
  }
}
