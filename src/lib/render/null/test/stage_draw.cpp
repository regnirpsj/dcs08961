// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/null/test/stage_draw.cpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <render/null/stage/draw.hpp>
#include <scene/nodes.hpp>
#include <scene/object/cameras.hpp>

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

BOOST_AUTO_TEST_CASE(test_render_null_stage_draw_ctor)
{
  using namespace render::null::stage;
  using namespace scene;
  
  draw d(new node::group, new node::camera(new object::camera::orthographic));

  BOOST_CHECK(&d);
  BOOST_MESSAGE(d);
}

BOOST_AUTO_TEST_CASE(test_render_null_stage_draw_ctor_shared_scene)
{
  using namespace render::null::stage;
  using namespace scene;

  node::group*  g(new node::group);
  node::camera* c(new node::camera(new object::camera::orthographic));
  
  draw d1(g, c);
  
  BOOST_CHECK(&d1);
  BOOST_MESSAGE(d1);

  {
    draw d2(g, c);

    BOOST_CHECK(&d2);
    BOOST_MESSAGE(d2);
  }
}

BOOST_AUTO_TEST_CASE(test_render_null_stage_draw_execute)
{
  using namespace render::null::stage;
  using namespace scene;
  
  draw d(new node::group, new node::camera(new object::camera::orthographic));

  BOOST_CHECK(&d);

  d.execute();
  
  BOOST_MESSAGE(d);
}
