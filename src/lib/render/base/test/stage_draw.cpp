// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/test/stage_draw.cpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <render/base/context.hpp>
#include <render/base/stage/draw.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class context : public render::base::context {
  };
  
  class draw_stage : public render::base::stage::draw {

  public:

    explicit draw_stage(render::base::context& a)
      : render::base::stage::draw(a)
    {}

  private:

    virtual void do_execute()
    {}
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_render_base_test_stage_draw_ctor)
{
  context          c;
  draw_stage const d(c);
  
  BOOST_CHECK  (true);
  BOOST_MESSAGE(d);
}
