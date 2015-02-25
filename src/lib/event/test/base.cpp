// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  event/test/base.cpp                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <event/event/base.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class simple : public event::base {

  public:

    virtual void notify()
    {
      TRACE("<unnamed>::simple::notify");
    }
    
  };
  
  // variables, internal
  
  // functions, internal

  event::base::time_stamp_type
  get_time()
  {
    return support::clock::now();
  }
  
} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_event_base_time_source)
{
  typedef event::base::time_source_function_type tsft;
  
  tsft ts_old(simple::time_source());
  tsft ts_new(&get_time);

  BOOST_CHECK(ts_old);
  BOOST_CHECK(ts_new);
  BOOST_CHECK(ts_old.target<tsft>() == simple::time_source(ts_new).target<tsft>());
  BOOST_CHECK(ts_new.target<tsft>() == simple::time_source()      .target<tsft>());
}

BOOST_AUTO_TEST_CASE(test_event_base_ctor_dflt)
{
  simple const e;

  BOOST_CHECK  (support::clock::now() > e.time_stamp());
  BOOST_MESSAGE("<unnamed>::simple:" << e);
}

BOOST_AUTO_TEST_CASE(test_event_base_ctor_cpy)
{
  simple const e1;
  simple const e2(e1);

  BOOST_CHECK  (e2.time_stamp() == e1.time_stamp());
  BOOST_MESSAGE("<unnamed>::simple:" << e1 << ',' << e2);
}

BOOST_AUTO_TEST_CASE(test_event_base_stamp)
{
  simple const e;

  BOOST_CHECK  (support::clock::now() > e.time_stamp());
  BOOST_MESSAGE("<unnamed>::simple:" << e);
}
