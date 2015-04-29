// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/test/handler_frame.cpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <array> // std::array<>

// includes, project

#include <platform/handler/frame.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class frame : public platform::handler::frame::base {

    using inherited = platform::handler::frame::base;

  public:
    
    explicit frame(unsigned a)
      : inherited(a)
    {}

    virtual ~frame()
    {}

    unsigned qsize() const
    { return frameq_.size(); }

    unsigned qlen_max() const
    { return frameq_max_len_; }
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_platform_handler_frame_ctor)
{
  frame const h(4);
  
  BOOST_CHECK(4 == h.qlen_max());
  BOOST_CHECK(0 == h.qsize   ());
}

BOOST_AUTO_TEST_CASE(test_platform_handler_frame_update)
{
  static std::array<support::clock::duration const, 5> const delay = {
    {
      std::chrono::microseconds(987),
      std::chrono::microseconds(610),
      std::chrono::microseconds(377),
      std::chrono::microseconds(233),
      std::chrono::microseconds(144),      
    }
  };
  static unsigned imax(3);
  static unsigned qmax((imax-1) * delay.size());
  
  frame h(qmax);
  
  BOOST_CHECK(qmax == h.qlen_max());
  BOOST_CHECK(0    == h.qsize   ());

  for (unsigned i(0); i < imax; ++i) {
    for (auto d : delay) {
      support::sleep(d);
      h.update();
    }
  }
  
  BOOST_CHECK  (qmax == h.qsize());
  BOOST_MESSAGE(h);
}
