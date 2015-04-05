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
#include <platform/window/manager.hpp>
#include <platform/glut/window/simple.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class win : public platform::glut::window::simple {

    using inherited = platform::glut::window::simple;
    
  public:

    explicit win(std::string const& a, rect const& b = inherited::dflt_rect, unsigned c = 1)
      : inherited(a, b),
        frames_  (c)
    {
#if 0
      std::cout << "window::manager: ";
      platform::window::manager::print_on(std::cout);
      std::cout << '\n';
#endif
    }
    
    virtual void frame_render_one()
    {
      --frames_;
      
      if (0 == frames_) {
        close();
      }
    }
    
  private:

    unsigned frames_;
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_platform_glut_window_simple_no_application)
{
  using namespace platform::glut;
  
  std::unique_ptr<window::base> w(nullptr);
  
  BOOST_CHECK_THROW(w.reset(new win("test_platform_glut_window_simple_no_application")),
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
        window_          (new win(a.argv0, window::base::rect(100, 100, 800, 800), 5))
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
        window1_          (new win(a.argv0 + "1", window::base::rect(100, 100, 800, 600), 10)),
        window2_          (new win(a.argv0 + "2", window::base::rect(910, 100, 800, 600),  5))
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
