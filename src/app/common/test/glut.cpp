// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/common/test/glut.cpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#include "../glut.hpp"

// includes, system

#include <GL/freeglut.h> // ::glut*

// includes, project

#include <support/chrono.hpp>

// internal unnamed namespace

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class application : public glut::application {

  public:

    explicit application(int argc, char* argv[])
      : glut::application(argc, argv)
    {
      TRACE("<unnamed>::application::application");
    }
    
    virtual void frame_render_one()
    {
      TRACE("<unnamed>::application::frame_render_one");

      if (max_frames < frameq_.back().counter) {
        ::glutLeaveMainLoop();
      } else {
        support::sleep(std::chrono::milliseconds(125));
      }
    }
    
    virtual void reshape(glm::ivec2 const&)
    {
      TRACE("<unnamed>::application::reshape");
    }

  private:

    static unsigned const max_frames;
    
  };

  /* static */ unsigned const application::max_frames(10);
  
  // variables, internal
  
  // functions, internal

} // namespace {

// functions, exported

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_app_common_glut_application_run)
{
  int   argc(1);
  char* argv[] = { "dummy" };
  
  BOOST_CHECK(EXIT_SUCCESS == glut::execute<application>(argc, argv, std::nothrow));
}
