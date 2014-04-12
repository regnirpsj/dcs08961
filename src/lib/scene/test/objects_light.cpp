// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/test/container.cpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <scene/objects.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(object_light_source_rep)
{
  scene::object::light::base::rep const lr;
  
  BOOST_CHECK(false == lr.active);
  BOOST_MESSAGE("object_light_source_rep:" << lr << '\n');
}

BOOST_AUTO_TEST_CASE(object_directional_light)
{
  scene::object::light::directional const l("directional_light");
  
  BOOST_CHECK(false == l.active);
  BOOST_MESSAGE(l << '\n');
}

BOOST_AUTO_TEST_CASE(object_positional_light)
{
  scene::object::light::positional const l("positional_light");
  
  BOOST_CHECK(false == l.active);
  BOOST_MESSAGE(l << '\n');
}

BOOST_AUTO_TEST_CASE(object_spot_light)
{
  scene::object::light::spot const l("spot_light");
  
  BOOST_CHECK(false == l.active);
  BOOST_MESSAGE(l << '\n');
}

BOOST_AUTO_TEST_CASE(object_area_light)
{
  scene::object::light::area l("area_light");

  l.exponent.set(1);
  l.cutoff.  set(12.5);
  
  l.size.    set(glm::uvec2(1, 2));
  l.samples. set(glm::uvec2(1, 4));

  l.size.    set(glm::uvec2(2, 1));
  l.samples. set(glm::uvec2(4, 1));

  l.size.    set(glm::uvec2(2, 2));
  l.samples. set(glm::uvec2(4, 4));

  l.size.    set(glm::uvec2( 6, 3));
  l.samples. set(glm::uvec2(10, 5));
  
  BOOST_CHECK(false == l.active);
  BOOST_MESSAGE(l << '\n');
}
