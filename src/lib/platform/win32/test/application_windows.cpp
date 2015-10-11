// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/win32/test/application_windows.cpp                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<
#include <memory>         // std::unique_ptr<>
#include <windows.h>

// includes, project

#include <platform/win32/application/windows.hpp>
#include <platform/win32/window/simple.hpp>
#include <platform/window/manager.hpp>
#include <support/chrono.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class app : public platform::win32::application::windows {

    using inherited = platform::win32::application::windows;
    using win_type  = platform::win32::window::simple;
    
  public:

    explicit app(platform::application::command_line const& a)
      : inherited(a),
        window_  (new win_type(a.argv0))
    {
      TRACE("<unnamed>::app::app");
    }

    virtual void process_command_line()
    {
      TRACE("<unnamed>::app::process_command_line");
      
      inherited::process_command_line();

#if 0
      std::cout << "<unnamed>::app::process_command_line: "
                << '\n'
                << "window::manager: ";
      platform::window::manager::print_on(std::cout);
      std::cout << '\n'
                << "window         : "
                << *window_
                << '\n';
#endif
    }

  private:

    std::unique_ptr<win_type> window_;

    virtual void update()
    {
      TRACE_NEVER("<unnamed>::app::update");

      using namespace support;
      using namespace std::chrono;

      static clock::time_point start(support::clock::now());

      if (milliseconds(250) < (support::clock::now() - start)) {
        ::PostQuitMessage(0);
      }
    }
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_platform_win32_application_windows_ctor)
{
  using platform::application::command_line;
  using platform::application::execute;

  int         argc(1);
  char const* argv[] = { "test_platform_win32_application_windows_ctor" };
  
  BOOST_CHECK(EXIT_SUCCESS == execute<app>(command_line(argc, argv)));
}

BOOST_AUTO_TEST_CASE(test_platform_win32_application_windows_help)
{
  using platform::application::command_line;
  using platform::application::execute;

  int         argc(2);
  char const* argv[] = { "test_platform_win32_application_windows_help", "-h" };
  
  BOOST_CHECK_THROW(execute<app>(command_line(argc, argv)), std::system_error);
}

BOOST_AUTO_TEST_CASE(test_platform_win32_application_windows_files)
{
  using platform::application::command_line;
  using platform::application::execute;

  int         argc(2);
  char const* argv[] = { "test_platform_win32_application_windows_files", "-v" };
  
  BOOST_CHECK(EXIT_SUCCESS == execute<app>(command_line(argc, argv)));
}
