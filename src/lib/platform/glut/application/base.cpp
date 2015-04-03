// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glut/application/base.cpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/glut/application/base.hpp"

// includes, system

// needs to be first!!!
#include <GL/glew.h> // glew*

#include <GL/freeglut.h> // ::glut*
#include <cstdlib>       // EXIT_SUCCESS
#include <ostream>       // std::ostream

// includes, project

#include <platform/glut/window/manager.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

  int         dummy_argc(1);
  char const* dummy_argv[1] = { "dummy" };
  
  // functions, internal

} // namespace {

namespace platform {

  namespace glut {
  
    namespace application {
      
      // variables, exported
  
      // functions, exported

      /* virtual */ signed
      base::run()
      {
        TRACE("platform::glut::application::base::run");

        signed result(EXIT_FAILURE);
      
        if (0 != window::manager::count()) {
          ::glutMainLoop();

          result = EXIT_SUCCESS;
        }
      
        return result;
      }

      /* virtual */ void
      base::print_on(std::ostream& os) const
      {
        TRACE_NEVER("platform::glut::application::base::print_on");
      
        platform::application::single_instance::print_on(os);
      }    

      /* explicit */
      base::base(platform::application::command_line const& a)
        : platform::application::single_instance(a)
      {
        TRACE("platform::glut::application::base::base");

        ::glutInit           (&dummy_argc, const_cast<char**>(dummy_argv));
        ::glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH|GLUT_STENCIL);

        // maybe needs to go into 'run'?
        ::glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,
                        GLUT_ACTION_GLUTMAINLOOP_RETURNS);
      }
      
    } // namespace application {
    
  } // namespace glut {
  
} // namespace platform {
