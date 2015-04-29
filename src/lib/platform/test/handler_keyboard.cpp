// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/test/handler_keyboard.cpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <platform/handler/keyboard.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class kbd : public platform::handler::keyboard::base {

    using inherited = platform::handler::keyboard::base;
    using key       = platform::handler::keyboard::key;
    
  public:

    explicit kbd(unsigned a)
      : inherited(a)
    {}

    virtual ~kbd()
    {}
    
    unsigned qsize() const
    { return keyboardq_.size(); }

    unsigned qlen_max() const
    { return keyboardq_max_len_; }
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_platform_handler_keyboard_ctor)
{
  kbd const h(4);
  
  BOOST_CHECK(4 == h.qlen_max());
  BOOST_CHECK(0 == h.qsize   ());
}

BOOST_AUTO_TEST_CASE(test_platform_handler_keyboard_ascii)
{
  kbd h(4);
  
  BOOST_CHECK(4 == h.qlen_max());
  BOOST_CHECK(0 == h.qsize   ());

  using key = platform::handler::keyboard::key;
  
  h.press  (key::ascii::one);
  h.release(key::ascii::two);
  h.press  (key::ascii::three);
  h.release(key::ascii::four);

  BOOST_CHECK  (4 == h.qsize());
  BOOST_MESSAGE(h);
}

BOOST_AUTO_TEST_CASE(test_platform_handler_keyboard_code)
{
  kbd h(4);
  
  BOOST_CHECK(4 == h.qlen_max());
  BOOST_CHECK(0 == h.qsize   ());

  using key = platform::handler::keyboard::key;
  
  h.press  (key::code::F1);
  h.release(key::code::F2);
  h.press  (key::code::F3);
  h.release(key::code::F4);

  BOOST_CHECK  (4 == h.qsize());
  BOOST_MESSAGE(h);
}
