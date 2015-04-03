// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glut/test/window_simple.cpp                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <memory> // std::uinque_ptr<>

// includes, project

#include <platform/glut/application/base.hpp>
#include <platform/glut/window/simple.hpp>

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

BOOST_AUTO_TEST_CASE(test_platform_glut_window_simple_1)
{
  using namespace platform::glut;
  using platform::application::command_line;
  
  class app : public application::base {

  public:

    explicit app(command_line const& a)
      : application::base(a),
        window_          (new window::simple("dummy"))
    {}

  private:

    std::unique_ptr<window::base> window_;
    
  };
  
  using platform::application::execute;
  
  BOOST_CHECK(EXIT_SUCCESS == execute<app>(command_line(argc, argv)));
}

BOOST_AUTO_TEST_CASE(test_platform_glut_window_simple_2)
{
  using namespace platform::glut;
  using platform::application::command_line;
  
  class app : public application::base {

  public:

    explicit app(command_line const& a)
      : application::base(a),
        window1_          (new window::simple("dummy1")),
        window2_          (new window::simple("dummy2"))
    {}

  private:

    std::unique_ptr<window::base> window1_;
    std::unique_ptr<window::base> window2_;
  };
  
  using platform::application::execute;
  
  BOOST_CHECK(EXIT_SUCCESS == execute<app>(command_line(argc, argv)));
}
