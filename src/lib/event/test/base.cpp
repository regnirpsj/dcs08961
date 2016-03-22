// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  event/test/base.cpp                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <iomanip>  // std::fixed, std::right, std::setfill, std::setprecision, std::setw

// includes, project

#include <event/base.hpp>
#include <support/type_info.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class async_evt : public event::async<async_evt> {

  public: explicit async_evt() : event::async<async_evt>() {}
    
  };

  class dummy_evt : public event::base<dummy_evt> {

  public: explicit dummy_evt() : event::base<dummy_evt>(false) {}
    
  };

  class sync_evt : public event::sync<sync_evt> {

  public: explicit sync_evt() : event::sync<sync_evt>() {}
    
  };
  
  // variables, internal
  
  // functions, internal

  void
  print_duration(support::clock::duration d, std::type_info const& t)
  {
    using std::chrono::duration_cast;
    using std::chrono::nanoseconds;
  
    BOOST_MESSAGE(std::setfill(' ') << std::setprecision(1) <<
                  std::fixed << std::right << std::setw(5) <<
                  double(duration_cast<nanoseconds>(d).count()) << "ns" <<
                  '\t' << support::demangle(t));
  }
  
} // namespace {

BOOST_AUTO_TEST_CASE(test_event_base_init_statics)
{
  async_evt aev;
  dummy_evt dev;
  sync_evt  sev;
  
  BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(test_event_base_ctor_async)
{
  support::timer timer;
  
  async_evt aev;

  print_duration(timer.lapse(), typeid(aev));
  
  BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(test_event_base_ctor_dummy)
{
  support::timer timer;
  
  dummy_evt dev;

  print_duration(timer.lapse(), typeid(dev));

  BOOST_CHECK(true);
}

BOOST_AUTO_TEST_CASE(test_event_base_ctor_sync)
{
  support::timer timer;
  
  sync_evt sev;

  print_duration(timer.lapse(), typeid(sev));

  BOOST_CHECK(true);
}
