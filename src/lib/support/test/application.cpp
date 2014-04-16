// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  support/test/application.cpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <support/application.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class application : public support::application {

  public:

    virtual ~application()
    {}

    virtual signed run()
    {
      return 0;
    }
    
  } instance;
  
  // variables, internal
  
  // functions, internal

} // namespace {

// functions, exported

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_support_application_instance)
{
  BOOST_CHECK(application::instance());
}

BOOST_AUTO_TEST_CASE(test_support_application_run)
{
  BOOST_CHECK(0 == application::instance()->run());
}
