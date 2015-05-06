// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/test/stage_clear.cpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <render/base/context.hpp>
#include <render/base/stage/clear.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class context : public render::base::context {
  };
  
  class clear_stage : public render::base::stage::clear {

  public:

    explicit clear_stage(render::base::context& a)
      : render::base::stage::clear(a)
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

BOOST_AUTO_TEST_CASE(test_render_base_test_stage_clear_ctor)
{
  context           c;
  clear_stage const s(c);
  
  BOOST_CHECK  (true);
  BOOST_MESSAGE(s);
}
