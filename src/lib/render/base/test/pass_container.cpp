// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/test/pass_container.cpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <render/base/context.hpp>
#include <render/base/pass/container.hpp>
#include <render/base/stage/null.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class context : public render::base::context {
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_render_base_test_pass_container_ctor)
{
  context c;
  
  using namespace render::base;
  
  pass::container p(c);

  p.stages += new stage::null(c);
  p.stages += new stage::null(c);
  
  BOOST_CHECK  (2 == p.stages->size());
  BOOST_MESSAGE(p);
}
