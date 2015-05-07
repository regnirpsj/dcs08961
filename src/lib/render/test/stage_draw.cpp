// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/test/stage_draw.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <render/context.hpp>
#include <render/stage/draw.hpp>
#include <scene/node/camera.hpp>
#include <scene/node/group.hpp>
#include <scene/object/camera/perspective.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  
  class draw_stage : public render::stage::draw {

  public:

    explicit draw_stage(render::context& a)
      : render::stage::draw(a)
    {
      TRACE("<unnamed>::draw_stage::draw_stage");
    }

  private:

    virtual void do_execute()
    {
      TRACE("<unnamed>::draw_stage::do_execute");
    }
    
  };

  class context : public render::context {
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_render_base_test_stage_draw_ctor)
{
  context    c;
  draw_stage d(c);

  {
    using namespace scene;
    
    d.camera = new node::camera(new object::camera::perspective);
    d.scene  = new node::group;
  }
  
  BOOST_CHECK  (nullptr != d.camera.get());
  BOOST_CHECK  (nullptr != d.scene. get());
  BOOST_MESSAGE(d);
}

BOOST_AUTO_TEST_CASE(test_render_base_test_stage_draw_execute)
{
  context    c;
  draw_stage d(c);

  {
    using namespace scene;
    
    d.camera = new node::camera(new object::camera::perspective);
    d.scene  = new node::group;
  }
  
  BOOST_CHECK  (nullptr != d.camera.get());
  BOOST_CHECK  (nullptr != d.scene. get());

  d.resize (glm::ivec2(10, 10));
  d.execute();
  
  BOOST_MESSAGE(d);
}
