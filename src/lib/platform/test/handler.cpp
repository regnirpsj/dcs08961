// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/test/handler.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <platform/window/handler.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

  unsigned const max_queue_len(3);
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_platform_window_handler_keyboard)
{
  using namespace platform::window;

  handler::keyboard::base h(max_queue_len);
  
  BOOST_CHECK(&h);
  
  unsigned loop(2 * max_queue_len);

  while (--loop) {
    glm::ivec2 const                 pos;
    support::clock::time_point const now(support::clock::now());
    
    using namespace platform::window::handler::keyboard;

    if (0 == loop % 2) {
      BOOST_CHECK(!h.press  (record{ key::asterisk, key::down, key::ModNone, pos, now }));
    } else {
      BOOST_CHECK(!h.release(record{ key::asterisk, key::up,   key::ModNone, pos, now }));
    }
  }
}

BOOST_AUTO_TEST_CASE(test_platform_window_handler_mouse)
{
  using namespace platform::window;

  handler::mouse::base h(max_queue_len);
  
  BOOST_CHECK(&h);
  
  unsigned loop(2 * max_queue_len);

  while (--loop) {
    glm::ivec2 const                 pos;
    support::clock::time_point const now(support::clock::now());
    
    using namespace platform::window::handler::mouse;
    using platform::window::handler::keyboard::key;
    
    switch (loop % 3) {
    case 0:
      BOOST_CHECK(!h.release(record{ button::left, state::down, direction::none, key::ModNone, pos, now }));
      break;

    case 2:
      BOOST_CHECK(!h.press  (record{ button::left, state::down, direction::none, key::ModNone, pos, now }));
      break;

    default:
      BOOST_CHECK(!h.motion (record{ button::left, state::down, direction::none, key::ModNone, pos, now }));
      break;
    }
  }
}

BOOST_AUTO_TEST_CASE(test_platform_window_handler_touch)
{
  using namespace platform::window;

  handler::touch::base h(max_queue_len);
  
  BOOST_CHECK(&h);
  
  unsigned loop(2 * max_queue_len);

  while (--loop) {
    glm::ivec2 const                 pos;
    support::clock::time_point const now(support::clock::now());
    
    using namespace platform::window::handler::touch;
    using platform::window::handler::keyboard::key;
    
    switch (loop % 3) {
    case 0:
      BOOST_CHECK(!h.release(record{ record::position_list_type(5, pos), now }));
      break;

    case 2:
      BOOST_CHECK(!h.press  (record{ record::position_list_type(5, pos), now }));
      break;

    default:
      BOOST_CHECK(!h.motion (record{ record::position_list_type(5, pos), now }));
      break;
    }
  }
}
