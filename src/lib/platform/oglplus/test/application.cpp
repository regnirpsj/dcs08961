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

#include <memory> // std::unique_ptr<>

// includes, project

#include <platform/glut/application/base.hpp>
#include <platform/glut/window/base.hpp>
#include <platform/oglplus/application.hpp>

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
        window_  (new win(a.argv0, 2))
    {}

    virtual void process_command_line()
    {
      inherited::process_command_line();
    }

  private:

    std::unique_ptr<win> window_;
    
  };

  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_platform_oglplus_application_execute)
{
  using platform::application::command_line;
  using platform::oglplus::application::execute;
  
  int         argc(1);
  char const* argv[] = { "test_platform_oglplus_application_execute" };
  
  BOOST_CHECK(EXIT_SUCCESS == platform::oglplus::application::execute<app>(command_line(argc, argv)));
}
