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
  scene::object::light_source::rep const lr;
  
  BOOST_CHECK(false == lr.active);
  BOOST_MESSAGE("object_light_source_rep:" << lr << '\n');
}

BOOST_AUTO_TEST_CASE(object_directional_light)
{
  scene::object::directional_light const l("directional_light");
  
  BOOST_CHECK(false == l.active);
  BOOST_MESSAGE(l << '\n');
}

BOOST_AUTO_TEST_CASE(object_positional_light)
{
  scene::object::positional_light const l("positional_light");
  
  BOOST_CHECK(false == l.active);
  BOOST_MESSAGE(l << '\n');
}

BOOST_AUTO_TEST_CASE(object_spot_light)
{
  scene::object::spot_light const l("spot_light");
  
  BOOST_CHECK(false == l.active);
  BOOST_MESSAGE(l << '\n');
}

BOOST_AUTO_TEST_CASE(object_area_light)
{
  scene::object::area_light const l("area_light");
  
  BOOST_CHECK(false == l.active);
  BOOST_MESSAGE(l << '\n');
}
