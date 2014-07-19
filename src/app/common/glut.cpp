// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/common/glut.cpp                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "glut.hpp"

// includes, system

// needs to be first!!!
#include <GL/glew.h>                 // ::glew*

#include <GL/freeglut.h>             // ::glut*
#include <cstdlib>                   // EXIT_[SUCCESS|FAILURE]
#include <oglplus/config/gl.hpp>     // 
#include <oglplus/error/program.hpp> //
#include <oglplus/error/limit.hpp>   //
#include <stdexcept>                 // std::logic_error

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
// #undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal
  
} // namespace {

namespace glut {
  
  // variables, exported
  
  // functions, exported

  /* static */ signed
  application::exception_handled(int argc, char* argv[])
  {
    TRACE("glut::application::exception_handled");

    signed result(EXIT_FAILURE);
    
    try {
      application::instance()->config(argc, argv);
      
      application::instance()->init();
      {
        result = application::instance()->run();
      }
      application::instance()->fini();
    }

    catch (oglplus::ProgramBuildError& ex) {
      std::cerr << " Program build error (in " << ex.GLFunc() << ", " << ex.ObjectTypeName()
                << ": (" << ex.ObjectName() << ") '" << ex.ObjectDesc() << "'): " << ex.what()
                << ": " << ex.Log() << '\n';
    }

    catch (oglplus::LimitError& ex) {
      std::cerr << " Limit error: (" << ex.Value() << ") exceeds (" << ex.EnumParamName() << " == "
                << ex.Limit() << ") [" << ex.SourceFile() << ":" << ex.SourceLine() << "] " << '\n';
    }

    catch (oglplus::ObjectError& ex) {
      std::cerr << " Object error (in " << ex.GLFunc() << ", " << ex.ObjectTypeName() << ": ("
                << ex.ObjectName() << ") '" << ex.ObjectDesc() << "') [" << ex.SourceFile()
                << ":" << ex.SourceLine() << "]: " << ex.what() << '\n';
    }

    catch (oglplus::Error& ex) {
      std::cerr << " Error (in " << ex.GLFunc() << "') [" << ex.SourceFile() << ":"
                << ex.SourceLine() << "]: " << ex.what() << '\n';
    }

    catch (std::exception& ex) {
      std::cerr << " Error: " << ex.what() << '\n';
    }

    return result;
  }
  
  /* virtual */ void
  application::config(int argc, char* argv[])
  {
    TRACE("glut::application::config");

    support::application::config(argc, argv);
    
    ::glutInit              (&argc, argv);
    ::glutInitDisplayMode   (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
    ::glutInitWindowPosition(window_.position.x, window_.position.y);
    ::glutInitWindowSize    (window_.size.x, window_.size.y);
    ::glutCreateWindow      (window_.title.c_str());
    
    if(GLEW_OK != ::glewInit()) {
      throw std::runtime_error("GLEW initialization error");
    }

    ::glGetError();
  }
  
  /* virtual */ void
  application::init()
  {
    TRACE("glut::application::init");

    support::application::init();
    
    ::glutDisplayFunc      (&application::display_cb);
    ::glutIdleFunc         (&application::idle_cb);
    ::glutKeyboardFunc     (&application::keyboard_cb);
    ::glutMouseFunc        (&application::mouse_cb);
    ::glutMotionFunc       (&application::motion_cb);
    ::glutPassiveMotionFunc(&application::passive_cb);
    ::glutReshapeFunc      (&application::reshape_cb);
    ::glutSpecialFunc      (&application::special_cb);
  }

  /* virtual */ signed
  application::run()
  {
    TRACE("glut::application::run");

    ::glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE,
                    GLUT_ACTION_GLUTMAINLOOP_RETURNS);
    ::glutCloseFunc(&application::close_cb);
    ::glutMainLoop ();
    
    return EXIT_SUCCESS;
  }

  /* virtual */ void
  application::fini()
  {
    TRACE("glut::application::fini");

    support::application::fini();
  }

  /* virtual */ void
  application::print_on(std::ostream& os) const
  {
    TRACE_NEVER("glut::application::print_on");

    support::application::print_on(os);
  }

  /* explicit */
  application::application()
    : support::application(),
      frame_              ({ 0, support::clock::now(), std::chrono::nanoseconds(0) }),
      keyboard_           ({ 0, 0 }),
      mouse_              ({ 0, GLUT_UP, glm::ivec2(-1, -1) }),
      window_             ({ glm::ivec2(-1, -1), glm::ivec2(800, 600), "<default window title>" })
  {
    TRACE("glut::application::application");
  }

  /* virtual */
  application::~application()
  {
    TRACE("glut::application::~application");
  }

  /* virtual */ void
  application::display()
  {
    TRACE("glut::application::display");

    throw std::logic_error("pure virtual function 'glut::application::display' called");
  }

  /* virtual */ void
  application::idle()
  {
    TRACE("glut::application::idle");

    ::glutPostRedisplay();
  }

  /* virtual */ void
  application::keyboard(unsigned char, glm::ivec2 const& p)
  {
    TRACE("glut::application::keyboard");

    mouse_.position = p;
  }

  /* virtual */ void
  application::motion(glm::ivec2 const& p)
  {
    TRACE("glut::application::motion");

    mouse_.position = p;
  }

  /* virtual */ void
  application::mouse(signed btn, signed state, glm::ivec2 const& p)
  {
    TRACE("glut::application::keyboard");

    mouse_.button   = btn;
    mouse_.state    = state;
    mouse_.position = p;
  }
  
  /* virtual */ void
  application::passive(glm::ivec2 const& p)
  {
    TRACE("glut::application::passive");

    mouse_.position = p;
  }

  /* virtual */ void
  application::reshape(glm::ivec2 const&)
  {
    TRACE("glut::application::reshape");

    throw std::logic_error("pure virtual function 'glut::application::reshape' called");
  }

  /* virtual */ void
  application::special(signed, glm::ivec2 const& p)
  {
    TRACE("glut::application::special");

    mouse_.position = p;
  }
  
  /* static */ void
  application::close_cb()
  {
    TRACE("glut::application::close_cb");

    application::instance()->fini();
  }

  /* static */ void
  application::display_cb()
  {
    TRACE("glut::application::display_cb");

    static_cast<application*>(application::instance())->display();
  }

  /* static */ void
  application::idle_cb()
  {
    TRACE("glut::application::idle_cb");

    static_cast<application*>(application::instance())->idle();
  }

  /* static */ void
  application::keyboard_cb(unsigned char key, signed x, signed y)
  {
    TRACE("glut::application::keyboard_cb");

    static_cast<application*>(application::instance())->keyboard(key, glm::ivec2(x, y));
  }

  /* static */ void
  application::motion_cb(signed x, signed y)
  {
    TRACE("glut::application::motion_cb");

    static_cast<application*>(application::instance())->motion(glm::ivec2(x, y));
  }

  /* static */ void
  application::mouse_cb(signed btn, signed state, signed x, signed y)
  {
    TRACE("glut::application::mouse_cb");

    static_cast<application*>(application::instance())->mouse(btn, state, glm::ivec2(x, y));
  }
  
  /* static */ void
  application::passive_cb(signed x, signed y)
  {
    TRACE("glut::application::passive_cb");

    static_cast<application*>(application::instance())->passive(glm::ivec2(x, y));
  }

  /* static */ void
  application::reshape_cb(signed w, signed h)
  {
    TRACE("glut::application::reshape_cb");

    static_cast<application*>(application::instance())->reshape(glm::ivec2(w, h));
  }

  /* static */ void
  application::special_cb(signed key, signed x, signed y)
  {
    TRACE("glut::application::special_cb");

    static_cast<application*>(application::instance())->special(key, glm::ivec2(x, y));
  }
  
} // namespace glut {
