// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/test/application.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

//#include <>

// includes, project

#include <platform/application/multi_instance.hpp>
#include <platform/application/single_instance.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  template <typename T, bool B>
  class app_skeleton : public T {

  public:

    using command_line = platform::application::command_line;
    
    explicit app_skeleton(command_line const& a)
      : T(a)
    {}

    virtual signed run()
    {
      if (B) {
        throw std::runtime_error("run-time error");
      }

      return EXIT_SUCCESS;
    }

  };

  using appmin = app_skeleton<platform::application::multi_instance,  false>;
  using appmit = app_skeleton<platform::application::multi_instance,  true>;
  using appsin = app_skeleton<platform::application::single_instance, false>;
  using appsit = app_skeleton<platform::application::single_instance, true>;  

  // variables, internal

  int         argc(1);
  char const* argv[] = { "dummy" };
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_platform_application_execute)
{
  using platform::application::command_line;
  using platform::application::execute;

  BOOST_CHECK(EXIT_SUCCESS == execute<appmin>(command_line(argc, argv)));
  BOOST_CHECK(EXIT_SUCCESS == execute<appsin>(command_line(argc, argv)));
}

BOOST_AUTO_TEST_CASE(test_platform_application_execute_nothrow)
{
  using platform::application::command_line;
  using platform::application::execute;

  BOOST_CHECK(EXIT_SUCCESS != execute<appmit>(command_line(argc, argv), std::nothrow));
  BOOST_CHECK(EXIT_SUCCESS != execute<appsit>(command_line(argc, argv), std::nothrow));
}

BOOST_AUTO_TEST_CASE(test_platform_application_execute_single_instance_fail)
{
  using platform::application::command_line;
  using platform::application::single_instance;

  class single_inst_fail : public single_instance {

  public:

    explicit single_inst_fail(command_line const& a)
      : single_instance(a) {}

    virtual signed run() { return EXIT_SUCCESS; }

  } instance(command_line(argc, argv));

  using platform::application::execute;

  BOOST_CHECK_THROW(execute<single_inst_fail>(command_line(argc, argv)), std::exception);
}

BOOST_AUTO_TEST_CASE(test_platform_application_execute_single_instance_fail_nothrow)
{
  using platform::application::command_line;
  using platform::application::single_instance;

  class single_inst_fail : public single_instance {

  public:

    explicit single_inst_fail(command_line const& a)
      : single_instance(a) {}

    virtual signed run() { return EXIT_SUCCESS; }

  } instance(command_line(argc, argv));

  using platform::application::execute;

  BOOST_CHECK(EXIT_SUCCESS != execute<single_inst_fail>(command_line(argc, argv), std::nothrow));
}
