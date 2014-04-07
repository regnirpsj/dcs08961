// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  support/test/chrono.cpp                                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <array>
#include <iomanip>

// includes, project

#include <support/chrono.hpp>
#include <support/chrono_io.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  // variables, internal
  
  // functions, internal

} // namespace {

// functions, exported

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_clock)
{
  using namespace support;
  
  BOOST_CHECK(true == clock::is_monotonic);
  BOOST_TEST_MESSAGE("clock monotonic: "
                     << std::boolalpha
                     << clock::is_monotonic);
  
  using std::chrono::duration_fmt;
  using std::chrono::prefix;
  using std::chrono::symbol;
  
  BOOST_TEST_MESSAGE("clock resolution: "
                     << duration_fmt(symbol) << clock::resolution);
}

BOOST_AUTO_TEST_CASE(test_timer)
{
  using namespace support;
  using namespace std::chrono;
  
  timer const t;
  
  clock::duration const d1(t.lapse());
  {
    sleep(milliseconds(100));
  }
  clock::duration const d2(t.lapse());

  BOOST_CHECK(d2 >= d1);
}

BOOST_AUTO_TEST_CASE(test_sleep)
{
  using namespace support;
  using namespace std::chrono;

  std::array<clock::duration, 18> const duration_list = {
    {
      nanoseconds (  1),
      nanoseconds (  5),
      nanoseconds ( 10),
      nanoseconds ( 50),
      nanoseconds (100),
      nanoseconds (500),
      
      microseconds(  1),
      microseconds(  5),
      microseconds( 10),
      microseconds( 50),
      microseconds(100),
      microseconds(500),
      
      milliseconds(  1),
      milliseconds(  5),
      milliseconds( 10),
      milliseconds( 50),
      milliseconds(100),
      milliseconds(500),
    }
  };

  timer const t;

  typedef duration<double> dsec;

  BOOST_MESSAGE(duration_fmt(symbol));
  
  for (auto d : duration_list) {
    BOOST_TEST_MESSAGE(std::string(10, '-') << "start testing "
                       << std::fixed << std::right << std::setfill(' ')
                       << duration_cast<dsec>(d));
    
    for (unsigned loop(0); loop < 3; ++loop) {
      clock::duration const start(t.lapse());
      {
        sleep(d);
      }
      clock::duration const stop(t.lapse());
      
      BOOST_CHECK(d < (stop - start));
      
      BOOST_TEST_MESSAGE("slept for " << std::fixed << std::right << std::setfill(' ')
                         << duration_cast<dsec>(stop - start));
    }

    BOOST_TEST_MESSAGE(std::string(10, '-') << "stop testing "
                       << std::fixed << std::right << std::setfill(' ')
                       << duration_cast<dsec>(d)
                       << " (" << std::fixed << d << ')');
  }
}
