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

// needs to be first!!!
#include <GL/glew.h>      // gl*

#include <GL/freeglut.h>  // ::glut*
#include <glm/gtx/io.hpp> // glm::operator<< (field::container::print_on)
#include <memory>         // std::unique_ptr<>
#include <system_error>   // std::system_error

// includes, project

#include <platform/glut/application/base.hpp>
#include <platform/glut/window/base.hpp>
#include <platform/window/manager.hpp>
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
      : inherited(a, rect(100, 100, 100, 100)),
        frames_  (b)
    {
      TRACE("<unnamed>::win::win");
    }
    
    virtual void display()
    {
      TRACE("<unnamed>::win::display");

      {
        ::glClearColor(0.95f, 0.95f, 0.95f, 0.0f);
        ::glClearDepth(1.0f);
        ::glClear     (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        ::glutSwapBuffers();
      }
      
      --frames_;
      
      if (0 == frames_) {
        close();
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
        window_  (new win(a.argv0, 2))
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

    std::unique_ptr<win> window_;
    
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
  char const* argv[] = { "test_platform_glut_application_ctor" };
  
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

  int         argc(2);
  char const* argv[] = { "test_platform_glut_application_files", "-v" };
  
  BOOST_CHECK(EXIT_SUCCESS == execute<app>(command_line(argc, argv)));
}
