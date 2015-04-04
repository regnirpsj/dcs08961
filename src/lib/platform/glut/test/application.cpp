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

#include <system_error> // std::system_error

// includes, project

#include <platform/glut/application/base.hpp>
#include <platform/glut/window/base.hpp>
#include <support/io_utils.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class win : public platform::glut::window::base {

    using inherited = platform::glut::window::base;
    
  public:

    explicit win(std::string const& a, unsigned b)
      : inherited(a),
        frames_  (b)
    {}
    
    virtual void frame_render_one()
    {
      --frames_;
      
      if (0 == frames_) {
        keyboard(0x1B, glm::ivec2(-1, -1));
      }
    }
    
  private:

    unsigned frames_;
    
  };
  
  class app : public platform::glut::application::base {

    using inherited = platform::glut::application::base;
    
  public:

    explicit app(platform::application::command_line const& a)
      : inherited(a),
        window_  (a.argv0, 2)
    {}

    virtual void process_command_line()
    {
      inherited::process_command_line();

      if (!input_files_.empty()) {
        using support::ostream::operator<<;
        
        std::cerr << "<unnamed>::app::process_command_line: [files:" << input_files_ << "]\n";
      }
    }

  private:

    win window_;
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_platform_glut_application_ctor)
{
  using platform::application::command_line;
  using platform::application::execute;

  int         argc(1);
  char const* argv[] = { "test_platform_glut_application_fail" };
  
  BOOST_CHECK(EXIT_SUCCESS == execute<app>(command_line(argc, argv)));
}

BOOST_AUTO_TEST_CASE(test_platform_glut_application_help)
{
  using platform::application::command_line;
  using platform::application::execute;

  int         argc(2);
  char const* argv[] = { "test_platform_glut_application_help", "-h" };
  
  BOOST_CHECK_THROW(execute<app>(command_line(argc, argv)), std::system_error);
}

BOOST_AUTO_TEST_CASE(test_platform_glut_application_files)
{
  using platform::application::command_line;
  using platform::application::execute;

  int         argc(4);
  char const* argv[] = { "test_platform_glut_application_files", "-f", "file0", "file1" };
  
  BOOST_CHECK(EXIT_SUCCESS == execute<app>(command_line(argc, argv)));
}
