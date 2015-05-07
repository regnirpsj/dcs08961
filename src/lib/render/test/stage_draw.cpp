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

#include <memory> // std::unique_ptr<>

// includes, project

#include <render/context.hpp>
#include <render/stage/draw.hpp>
#include <render/stats/cpu.hpp>
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
      : render::stage::draw(a),
        stats_exec_        (new render::stats::cpu(ctx_)),
        stats_resz_        (new render::stats::cpu(ctx_))
    {
      TRACE("<unnamed>::draw_stage::draw_stage");

      stats_execute = stats_exec_.get();
      stats_resize  = stats_resz_.get();
    }

  private:

    std::unique_ptr<render::stats::base> stats_exec_;
    std::unique_ptr<render::stats::base> stats_resz_;
    
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

  BOOST_MESSAGE(std::fixed
                << "resize:"
                << std::setw(9) << std::setprecision(2)
                << *((*d.stats_resize)->fetch().get()));
  
  for (unsigned i(0); i < 9; ++i) {
    d.execute();
    BOOST_MESSAGE(std::fixed
                  << "exec" << std::setfill('0') << std::setw(2) << (i+1) << ':'
                  << std::setfill(' ') << std::setw(9) << std::setprecision(2)
                  << *((*d.stats_execute)->fetch().get()));
  }
  
  // BOOST_MESSAGE(d);
}
