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

#include <glm/gtx/io.hpp> // glm::operator<< (field::container::print_on)
#include <memory>         // std::uinque_ptr<>

// includes, project

#include <platform/glut/application/base.hpp>
#include <window.hpp>

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

BOOST_AUTO_TEST_CASE(test_platform_glut_window_simple_fail)
{
  using namespace platform::glut;
  
  std::unique_ptr<window::base> w(nullptr);
  
  BOOST_CHECK_THROW(w.reset(new window::test::window("test_platform_glut_window_simple_fail")),
                    std::runtime_error);
}

BOOST_AUTO_TEST_CASE(test_platform_glut_window_simple_single)
{
  using namespace platform::glut;
  using platform::application::command_line;
  
  class app : public application::base {

  public:

    explicit app(command_line const& a)
      : application::base(a),
        window_          (new window::test::window(a.argv0,
                                                   window::base::rect(100, 100, 800, 600),
                                                   window::test::window::dflt_duration * 2))
    {}

  private:

    std::unique_ptr<window::base> window_;
    
  };
  
  using platform::application::execute;

  int         argc(1);
  char const* argv[] = { "test_platform_glut_window_simple_single" };
  
  BOOST_CHECK(EXIT_SUCCESS == execute<app>(command_line(argc, argv)));
}

BOOST_AUTO_TEST_CASE(test_platform_glut_window_simple_multi)
{
  using namespace platform::glut;
  using platform::application::command_line;
  
  class app : public application::base {

  public:

    explicit app(command_line const& a)
      : application::base(a),
        window1_          (new window::test::window(a.argv0 + "1",
                                                    window::base::rect(100, 100, 800, 600),
                                                    window::test::window::dflt_duration * 2)),
        window2_          (new window::test::window(a.argv0 + "2",
                                                    window::base::rect(910, 100, 800, 600),
                                                    window::test::window::dflt_duration * 1))
    {}

  private:

    std::unique_ptr<window::base> window1_;
    std::unique_ptr<window::base> window2_;
  };
  
  using platform::application::execute;

  int         argc(1);
  char const* argv[] = { "test_platform_glut_window_simple_multi" };
  
  BOOST_CHECK(EXIT_SUCCESS == execute<app>(command_line(argc, argv)));
}
