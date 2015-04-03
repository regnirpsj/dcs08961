// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glut/test/application.cpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

// #include <>

// includes, project

#include <platform/glut/application/base.hpp>

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

BOOST_AUTO_TEST_CASE_EXPECTED_FAILURES(test_platform_glut_application_fail, 1);

BOOST_AUTO_TEST_CASE(test_platform_glut_application_fail)
{
  class app : public platform::glut::application::base {

  public:

    explicit app(platform::application::command_line const& a)
      : platform::glut::application::base(a)
    {}
    
  };
  
  using platform::application::command_line;
  using platform::application::execute;

  BOOST_CHECK(EXIT_SUCCESS == execute<app>(command_line(argc, argv)));
}
