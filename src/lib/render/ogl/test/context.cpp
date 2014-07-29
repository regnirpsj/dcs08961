// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/ogl/test/context.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <render/ogl/context.hpp>

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

BOOST_AUTO_TEST_CASE(test_render_ogl_context_ctor)
{
  using namespace render::ogl;

  context c;

  BOOST_CHECK(&c);
  BOOST_MESSAGE(c);
}

BOOST_AUTO_TEST_CASE(test_render_ogl_context_multiple_instances)
{
  using namespace render::ogl;

  context c1;

  BOOST_CHECK(&c1);
  BOOST_MESSAGE("ctx1\n" << c1);

  {
    context c2;

    BOOST_CHECK(&c2);
    BOOST_MESSAGE("ctx2\n" << c2);
  }

  {
    context c3;

    BOOST_CHECK(&c3);
    BOOST_MESSAGE("ctx3\n" << c3);

    {
      context c4;

      BOOST_CHECK(&c4);
      BOOST_MESSAGE("ctx4\n" << c4);
    }

    BOOST_MESSAGE("ctx3\n" << c3);
  }
  
  BOOST_MESSAGE("ctx1\n" << c1);
}
