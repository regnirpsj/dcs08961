// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/test/handler_touch.cpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <array> // std::array<>

// includes, project

#include <platform/handler/touch.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class touch : public platform::handler::touch::base {

    using inherited = platform::handler::touch::base;

  public:
    
    explicit touch(unsigned a)
      : inherited(a)
    {}

    virtual ~touch()
    {}

    unsigned qsize() const
    { return touchq_.size(); }

    unsigned qlen_max() const
    { return touchq_max_len_; }
    
  };
  
  // variables, internal

  std::array<glm::ivec2 const, 10> const fingers = {
    {
      glm::ivec2(3, 0), glm::ivec2(5, 2), glm::ivec2(4, 3), glm::ivec2(3, 3), glm::ivec2(2, 2),
      glm::ivec2(6, 0), glm::ivec2(5, 2), glm::ivec2(6, 3), glm::ivec2(7, 3), glm::ivec2(8, 2),
    }
  };
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_platform_handler_touch_ctor)
{
  touch const h(4);
  
  BOOST_CHECK(4 == h.qlen_max());
  BOOST_CHECK(0 == h.qsize   ());
}

BOOST_AUTO_TEST_CASE(test_platform_handler_touch_motion)
{
  touch h(4);
  
  BOOST_CHECK(4 == h.qlen_max());
  BOOST_CHECK(0 == h.qsize   ());

  for (unsigned i(0); i < h.qlen_max(); ++i) {
    using position_list_type = platform::handler::touch::base::position_list_type;
    
    h.motion(position_list_type(fingers.begin(), fingers.end()));
  }

  BOOST_CHECK  (4 == h.qsize());
  BOOST_MESSAGE(h);
}

BOOST_AUTO_TEST_CASE(test_platform_handler_touch_press_release)
{
  touch h(4);
  
  BOOST_CHECK(4 == h.qlen_max());
  BOOST_CHECK(0 == h.qsize   ());

  for (unsigned i(0); i < (h.qlen_max()/2); ++i) {
    using position_list_type = platform::handler::touch::base::position_list_type;
    
    h.press  (position_list_type(fingers.begin(), fingers.end()));
    h.release(position_list_type(fingers.begin(), fingers.end()));
  }

  BOOST_CHECK  (4 == h.qsize());
  BOOST_MESSAGE(h);
}
