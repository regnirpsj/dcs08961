// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/test/objects_camera.cpp                                                   */
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

BOOST_AUTO_TEST_CASE(test_scene_object_camera_frustum)
{
  scene::object::camera::frustum const f;
  
  BOOST_CHECK(true);
  BOOST_MESSAGE("scene::object::camera::frustum: " << f << '\n');
}

BOOST_AUTO_TEST_CASE(test_scene_object_camera_viewport)
{
  scene::object::camera::viewport const v;
  
  BOOST_CHECK(true);
  BOOST_MESSAGE("scene::object::camera::viewport: " << v << '\n');
}

BOOST_AUTO_TEST_CASE(test_scene_object_camera_orthographic)
{
  scene::object::camera::orthographic const oc;
  
  BOOST_CHECK(true);
  BOOST_MESSAGE(oc << '\n');
}

BOOST_AUTO_TEST_CASE(test_scene_object_camera_perspective)
{
  scene::object::camera::perspective const pc;
  
  BOOST_CHECK(true);
  BOOST_MESSAGE(pc << '\n');
}
