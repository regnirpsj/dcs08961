// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/posix/test/appication.cpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <platform/posix/application/base.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

  int         argc(1);
  char const* argv[] = { "dummy" };
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_platform_posix_application_execute)
{
  using platform::application::command_line;

  class app : public platform::posix::application::base {

    using inherited = platform::posix::application::base;
    
  public:

    explicit app(command_line const& a)
      : inherited(a) {}

    virtual signed run() { return EXIT_SUCCESS; }

  };

  using platform::application::execute;
  
  BOOST_CHECK(EXIT_SUCCESS == execute<app>(command_line(argc, argv)));
}
