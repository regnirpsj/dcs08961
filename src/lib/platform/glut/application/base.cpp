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

      /* static */ bool
      base::initialized()
      {
        TRACE("platform::glut::application::initialized");
      
        return platform::application::single_instance::initialized();
      }
      
      /* virtual */
      base::~base()
      {
        TRACE("platform::glut::application::base::~base");

        ::glutExit();
      }
      
      /* virtual */ signed
      base::run()
      {
        TRACE("platform::glut::application::base::run");

        signed result(EXIT_SUCCESS);
      
        if (!window::manager::count()) {
          result = EXIT_FAILURE;
        } else {
          do {
            for (auto id : window::manager::all()) {
              ::glutPostWindowRedisplay(id);
            }
            
#if 0
            {
              std::cout << "platform::glut::application::base::run: ";
              platform::window::manager::print_on(std::cout);
              std::cout << '\n';
            }
#endif
            
            ::glutMainLoopEvent();
          } while (0 != window::manager::count());
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
        : platform::application::single_instance(a),
          input_files_                          ()
      {
        TRACE("platform::glut::application::base::base");

        {
          namespace bpo = boost::program_options;
          
          bpo::options_description od("Command-Line Options");

          od.add_options()
            ("file,f",
             bpo::value(&input_files_)->composing(),
             "input file(s)\n"
             "positional arguments are accumulated as input files");

          command_line_.descriptions.add(od);
          command_line_.positionals .add("file", -1);
        }

        ::glutInit           (&dummy_argc, const_cast<char**>(dummy_argv));
        ::glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH|GLUT_STENCIL);
        ::glutSetOption      (GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
      }
      
    } // namespace application {
    
  } // namespace glut {
  
} // namespace platform {
