// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  plaform/oglplus/test/application.cpp                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<
#include <memory>         // std::unique_ptr<>

// includes, project

#include <platform/glut/application/base.hpp>
#include <platform/oglplus/application.hpp>
#include <support/io_utils.hpp>
#include <window.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class app : public platform::glut::application::base {

    using inherited = platform::glut::application::base;
    
  public:

    explicit app(platform::application::command_line const& a)
      : inherited(a),
        window_  (new platform::glut::window::test::window(a.argv0))
    {
      TRACE("<unnamed>::app::app");
    }

    virtual void process_command_line()
    {
      TRACE("<unnamed>::app::process_command_line");
      
      inherited::process_command_line();

      window_->print_state();
    }

  private:

    std::unique_ptr<platform::glut::window::test::window> window_;
    
  };

  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_platform_oglplus_application_execute)
{
  using platform::application::command_line;
  
  int         argc(1);
  char const* argv[] = { "test_platform_oglplus_application_execute" };
  
  BOOST_CHECK(EXIT_SUCCESS ==
              platform::oglplus::application::execute<app>(command_line(argc, argv)));
}

BOOST_AUTO_TEST_CASE(test_platform_oglplus_application_execute_nothrow)
{
  using platform::application::command_line;
  
  int         argc(1);
  char const* argv[] = { "test_platform_oglplus_application_execute_nothrow" };
  
  BOOST_CHECK(EXIT_SUCCESS ==
              platform::oglplus::application::execute<app>(command_line(argc, argv), std::nothrow));
}
