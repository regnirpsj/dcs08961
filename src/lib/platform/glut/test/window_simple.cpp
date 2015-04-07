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
#include <iomanip>        // std::
#include <memory>         // std::uinque_ptr<>
#include <sstream>        // std::ostringstream

// includes, project

#include <platform/glut/application/base.hpp>
#include <platform/window/manager.hpp>
#include <platform/glut/window/simple.hpp>
#include <support/chrono_io.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class win : public platform::glut::window::simple {

    using duration  = support::clock::duration;
    using inherited = platform::glut::window::simple;
    using timer     = support::timer;
    
  public:

    explicit win(std::string const& a,
                 rect const&        b = inherited::dflt_rect,
                 duration const&    c = std::chrono::seconds(1))
      : inherited  (a, b),
        duration_  (c),
        timer_     (),
        title_orig_(*title)
    {
      TRACE("<unnamed>::win::win");
      
      print_state();
    }
    
    virtual void frame_render_one()
    {
      TRACE("<unnamed>::win::frame_render_one");
      
      duration const now(timer_.lapse());

      if (duration_ < now) {
        close();
      } else {
        namespace sc = std::chrono;
        
        std::ostringstream ostr;

        ostr << title_orig_
             << " ["
             << std::fixed << std::right << std::setfill(' ') << sc::duration_fmt(sc::symbol)
             << sc::duration_cast<sc::duration<double>>(duration_ - now)
             << ']';

        title = ostr.str();
      
        print_state();
      }
    }
    
  private:
    
    duration const    duration_;
    timer             timer_;
    std::string const title_orig_;
    
    void
    print_state()
    {
#if 0
      std::cout << "<unnamed>::win::print_state: "
                << '\n'
                << "window::manager: ";
      platform::window::manager::print_on(std::cout);
      std::cout << '\n'
                << "window         : "
                << *this
                << '\n';
#endif
    }
    
  };
  
  // variables, internal
  
  support::clock::duration const window_duration(std::chrono::seconds(2));
  
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
        window_          (new win(a.argv0,
                                  window::base::rect(100, 100, 800, 600),
                                  window_duration))
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
        window1_          (new win(a.argv0 + "1",
                                   window::base::rect(100, 100, 800, 600),
                                   window_duration / 2)),
        window2_          (new win(a.argv0 + "2",
                                   window::base::rect(910, 100, 800, 600),
                                   window_duration / 1))
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
