// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/test/window.cpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <render/context.hpp>
#include <render/pass/container.hpp>
#include <render/stage/null.hpp>
#include <render/window.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class context : public render::context {
  };

  class window : public render::window {
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_render_base_test_window_ctor)
{
  context c;

  using container = render::pass::container;
  
  container* p(new container(c));

  {
    using null = render::stage::null;
    
    p->stages += new null(c);
    p->stages += new null(c);

    BOOST_CHECK(2 == p->stages->size());
  }
  
  window w;

  w.passes += p;
  
  BOOST_CHECK  (1 == w.passes->size());
  BOOST_MESSAGE(w);
}
