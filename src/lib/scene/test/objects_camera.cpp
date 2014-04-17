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
  using namespace scene::object::camera;
  
  frustum const f;
  
  BOOST_CHECK(0.0 == (f.right + f.left));
  BOOST_CHECK(0.0 == (f.top   + f.bottom));
  BOOST_MESSAGE("scene::object::camera::frustum: " << f << '\n');
}

BOOST_AUTO_TEST_CASE(test_scene_object_camera_viewport)
{
  using namespace scene::object::camera;
  
  viewport const v;
  
  BOOST_CHECK(v.width == v.height);
  BOOST_MESSAGE("scene::object::camera::viewport: " << v << '\n');
}

BOOST_AUTO_TEST_CASE(test_scene_object_camera_orthographic)
{
  using namespace scene::object::camera;
  
  orthographic const oc(viewport(1, 1, 1599, 899));
  
  BOOST_CHECK(0.0 == (oc.frustum.get().right + oc.frustum.get().left));
  BOOST_CHECK(0.0 == (oc.frustum.get().top   + oc.frustum.get().bottom));
  BOOST_MESSAGE(oc << '\n');
}

BOOST_AUTO_TEST_CASE(test_scene_object_camera_perspective)
{
  using namespace scene::object::camera;

  float const       angle(45_deg);
  perspective const pc   (angle, viewport(1, 1, 2879, 1799),
                          glm::vec2(frustum().near, 10));
  
  BOOST_CHECK(angle == pc.fovy.get());
  BOOST_MESSAGE(glm::io::precision(4) << pc << '\n');

#if 0
  // expected compile error:
  // passing 'const field::adapter::single<T>' as 'this' argument of
  // 'field::adapter::single<T>::set(const value_type&)' discards qualifiers
  BOOST_CHECK(glm::mat4() == pc.projection.set(glm::mat4()));
  BOOST_MESSAGE(pc << '\n');
#endif
}

BOOST_AUTO_TEST_CASE(test_scene_object_camera_perspective_infty)
{
  using namespace scene::object::camera;

  float const       angle(45_deg);
  perspective const pc   (angle, viewport(1, 1, 2879, 1799),
                          glm::vec2(frustum().near, std::numeric_limits<float>::infinity()));
  
  BOOST_CHECK(angle == pc.fovy.get());
  BOOST_MESSAGE(glm::io::precision(4) << pc << '\n');
}
