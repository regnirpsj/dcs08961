// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/test/window.cpp                                                     */
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
#include <render/base/window.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class context : public render::base::context {
  };

  class window : public render::base::window {
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_render_base_test_window_ctor)
{
  context c;

  using container = render::base::pass::container;
  
  container* p(new container(c));

  {
    using null = render::base::stage::null;
    
    p->stages += new null(c);
    p->stages += new null(c);

    BOOST_CHECK(2 == p->stages->size());
  }
  
  window w;

  w.passes += p;
  
  BOOST_CHECK  (1 == w.passes->size());
  BOOST_MESSAGE(w);
}
