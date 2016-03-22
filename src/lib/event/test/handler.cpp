// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  event/test/handler.cpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <event/base.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class async_evt : public event::async<async_evt> {

  public: explicit async_evt() : event::async<async_evt>() {}
    
  };
  
  class sync_evt : public event::sync<sync_evt> {

  public: explicit sync_evt() : event::sync<sync_evt>() {}
    
  };
  
  class async_hndlr : public async_evt::handler {

  public:

    virtual void handle_event(async_evt const&);
    
  };

  class sync_hndlr : public sync_evt::handler {

  public:
    
    virtual void handle_event(sync_evt const&);
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_event_handler_dummy)
{
  BOOST_CHECK(true);
}
