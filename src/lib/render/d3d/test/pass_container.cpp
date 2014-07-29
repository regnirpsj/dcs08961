// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/d3d/test/pass_container.cpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <render/d3d/pass/container.hpp>

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

BOOST_AUTO_TEST_CASE(test_render_d3d_pass_container_ctor_dflt)
{
  using namespace render::d3d::pass;

  container c;

  BOOST_CHECK(c.size() == 0);
  BOOST_MESSAGE(c);
}

BOOST_AUTO_TEST_CASE(test_render_d3d_pass_container_ctor_init)
{
  using namespace render::d3d::pass;

  container c({ new container(), new container(), });

  BOOST_CHECK(c.size() == 2);
  BOOST_MESSAGE(c);
}

BOOST_AUTO_TEST_CASE(test_render_d3d_pass_container_add)
{
  using namespace render::d3d::pass;

  container c;

  BOOST_CHECK(c.size() == 0);
  BOOST_CHECK(c.add(new container()));
  BOOST_CHECK(c.size() == 1);
  BOOST_MESSAGE(c);
}

BOOST_AUTO_TEST_CASE(test_render_d3d_pass_container_sub)
{
  using namespace render::d3d::pass;

  container* a(new container);
  container  c({ a, a });

  BOOST_CHECK(c.size() == 1);
  BOOST_CHECK(c.sub(a));
  BOOST_CHECK(c.size() == 0);
  BOOST_MESSAGE(c);
}
