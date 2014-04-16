// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/test/node_camera.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <scene/node/camera.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_scene_node_camera_frustum_ctor)
{
  using namespace scene::node;
  
  camera::frustum const f;
  
  BOOST_CHECK(camera::frustum() == f);
  BOOST_MESSAGE(f << '\n');
}

BOOST_AUTO_TEST_CASE(test_scene_node_camera_viewport_ctor)
{
  using namespace scene::node;
  
  camera::viewport const v;
  
  BOOST_CHECK(camera::viewport() == v);
  BOOST_MESSAGE(v << '\n');
}

BOOST_AUTO_TEST_CASE(test_scene_node_camera_orthographic_ctor)
{
  using namespace scene::node;
  
  camera::orthographic const c;
  
  BOOST_CHECK(camera::viewport() == c.viewport());
  BOOST_MESSAGE(c << '\n');
}


BOOST_AUTO_TEST_CASE(test_scene_node_camera_perspective_ctor)
{
  using namespace scene::node;
  
  camera::perspective const c;
  
  BOOST_CHECK(camera::viewport() == c.viewport());
  BOOST_MESSAGE(c << '\n');
}
