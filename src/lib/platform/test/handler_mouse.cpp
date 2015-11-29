// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/test/handler_mouse.cpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <platform/handler/mouse.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class mouse : public platform::handler::mouse::base {

    using inherited = platform::handler::mouse::base;

  public:
    
    explicit mouse(unsigned a)
      : inherited(a)
    {}

    virtual ~mouse()
    {}

    unsigned qsize() const
    { return mouseq_.size(); }

    unsigned qlen_max() const
    { return mouseq_max_len_; }
    
  };
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_platform_handler_mouse_ctor)
{
  mouse const h(4);
  
  BOOST_CHECK(4 == h.qlen_max());
  BOOST_CHECK(0 == h.qsize   ());
}

BOOST_AUTO_TEST_CASE(test_platform_handler_mouse_motion)
{
  mouse h(4);
  
  BOOST_CHECK(4 == h.qlen_max());
  BOOST_CHECK(0 == h.qsize   ());

  for (unsigned i(0); i < h.qlen_max(); ++i) {
    h.motion();
  }

  BOOST_CHECK       (4 == h.qsize());
  BOOST_TEST_MESSAGE(h);
}

BOOST_AUTO_TEST_CASE(test_platform_handler_mouse_press_release)
{
  mouse h(4);
  
  BOOST_CHECK(4 == h.qlen_max());
  BOOST_CHECK(0 == h.qsize   ());

  for (unsigned i(0); i < (h.qlen_max()/2); ++i) {
    using platform::handler::mouse::button;
    
    h.press  (button::left);
    h.release(button::left);
  }

  BOOST_CHECK       (4 == h.qsize());
  BOOST_TEST_MESSAGE(h);
}

BOOST_AUTO_TEST_CASE(test_platform_handler_mouse_scroll)
{
  mouse h(4);
  
  BOOST_CHECK(4 == h.qlen_max());
  BOOST_CHECK(0 == h.qsize   ());

  for (unsigned i(0); i < h.qlen_max(); ++i) {
    using platform::handler::mouse::direction;
    
    h.scroll(1.0, direction::up);
  }

  BOOST_CHECK       (4 == h.qsize());
  BOOST_TEST_MESSAGE(h);
}
