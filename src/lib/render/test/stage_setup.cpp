// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/test/stage_setup.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <render/context.hpp>
#include <render/stage/setup.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class context : public render::context {
  };
  
  class setup_stage : public render::stage::setup {

  public:

    explicit setup_stage(render::context& a)
      : render::stage::setup(a)
    {}

  private:

    virtual void do_execute()
    {}

    virtual void do_resize(glm::ivec2 const&)
    {}
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_render_base_test_stage_setup_ctor)
{
  context           c;
  setup_stage const s(c);
  
  BOOST_CHECK  (true);
  BOOST_MESSAGE(s);
}
