// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  event/test/notify.cpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <event/event/notify.hpp>
#include <shared.hpp>

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

BOOST_AUTO_TEST_CASE(test_event_notify_sync)
{
  using namespace event::test;

  simple e;
  
  event::notify::sync(e);
  
  BOOST_CHECK(true != false);
}

BOOST_AUTO_TEST_CASE(test_event_notify_async)
{
  using namespace event::test;
  
  event::notify::async(simple());
  
  BOOST_CHECK(true != false);
}
