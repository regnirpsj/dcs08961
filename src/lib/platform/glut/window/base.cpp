// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glut/window/base.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/glut/window/base.hpp"

// includes, system

// needs to be first!!!
#include <GL/glew.h>     // GLEWContext, ::glew*

#include <GL/freeglut.h> // ::glut*
#include <iomanip>       // std::setfill, std::setw
#include <iostream>      // std::cerr
#include <stdexcept>     // std::logic_error

// includes, project

#include <platform/glut/window/manager.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace platform {

  namespace glut {

    namespace window {
  
      // variables, exported
  
      // functions, exported

      /* static */ void
      base::flush_gl_errors(std::ostream& os)
      {
        TRACE("platform::glut::window::base::flush_gl_errors");

        unsigned error(::glGetError());

        if (GL_NO_ERROR != error) {
          do {
            os << "GL error: "
               << ::glewGetErrorString(error)
               << " ("
               <<                                                  error << "|0x"
               << std::hex << std::setfill('0') << std::setw(4) << error
               << ")\n";
          } while (GL_NO_ERROR != (error = ::glGetError()));
        }
      }

      /* virtual */
      base::~base()
      {
        TRACE("platform::glut::window::base::~base");

        manager::sub(state_.id);
      }
      
      /* virtual */ void
      base::print_on(std::ostream&) const
      {
        TRACE_NEVER("platform::glut::window::base::print_on");
      }

      namespace {

        std::string
        exec_context(void const* ptr)
        {
          return std::string(" (@"
                             + std::to_string(reinterpret_cast<unsigned long const>(ptr))
                             + ')');
        }
        
      }
      
      /* explicit */
      base::base(std::string const& a)
        : platform::window::base(a),
          state_                ({-1, false, glm::ivec2(90,40), glm::ivec2(1440,900), false })
      {
        TRACE("platform::glut::window::base::base" + exec_context(this));

        ::glutInitWindowPosition(state_.pos.x,  state_.pos.y);
        ::glutInitWindowSize    (state_.size.x, state_.size.y);
    
        if (0 >= (state_.id = ::glutCreateWindow(title_.c_str()))) {
          throw std::runtime_error("GLUT initialization error");
        }
        
        // glewExperimental = true;
    
        if (GLEW_OK != ::glewInit()) {
          throw std::runtime_error("GLEW initialization error");
        }

        flush_gl_errors(std::cerr);

        ::glutDisplayFunc (&base::cb_display);
        ::glutIdleFunc    (&base::cb_idle);
        ::glutKeyboardFunc(&base::cb_keyboard);
        ::glutMouseFunc   (&base::cb_mouse);
        ::glutReshapeFunc (&base::cb_reshape);
        ::glutSpecialFunc (&base::cb_special);

        manager::add(state_.id, this);
      }

      /* virtual */ void
      base::frame_render_one()
      {
        TRACE("platform::glut::window::base::frame_render_one");

        throw std::logic_error("pure virtual function "
                               "'platform::glut::window::base::frame_render_one' called");
      }

      /* virtual */ void
      base::frame_render_post()
      {
        TRACE_NEVER("platform::glut::window::base::frame_render_post");

        ::glutSwapBuffers();
      }

      /* virtual */ void
      base::frame_render_pre()
      {
        TRACE_NEVER("platform::glut::window::base::frame_render_pre");
      }

      /* virtual */ void
      base::idle()
      {
        TRACE_NEVER("platform::glut::window::base::idle");

        ::glutPostRedisplay();
      }

      /* virtual */ void
      base::keyboard(unsigned char key, glm::ivec2 const&)
      {
        TRACE("platform::glut::window::base::keyboard" + exec_context(this));

        switch (key) {
        case 0x1B: // ESC
          ::glutLeaveMainLoop();
          break;

        case 'f': // fullscreen toggle
          {
            (state_.fullscreen = !state_.fullscreen)
              ? ::glutFullScreen()
              : ::glutLeaveFullScreen();
          }
          break;

        case 's':
          {
            state_.show_stats = !state_.show_stats;
          }
          break;
          
        default:
          break;
        }
      }

      /* virtual */ void
      base::mouse(signed, signed, glm::ivec2 const&)
      {
        TRACE("platform::glut::window::base::mouse");
      }

      /* virtual */ void
      base::reshape(glm::ivec2 const&)
      {
        TRACE("platform::glut::window::base::reshape" + exec_context(this));
      }

      /* virtual */ void
      base::special(signed, glm::ivec2 const&)
      {
        TRACE("platform::glut::window::base::special");
      }

      /* virtual */ void
      base::display()
      {
        TRACE_NEVER("platform::glut::window::base::display");

        frame_render_pre ();
        frame_render_one ();
        frame_render_post();
      }
    
      /* static */ void
      base::cb_display()
      {
        TRACE_NEVER("platform::glut::window::base::cb_display");

        base* win(static_cast<base*>(manager::get(::glutGetWindow())));

        win->display();
      }

      /* static */ void
      base::cb_idle()
      {
        TRACE_NEVER("platform::glut::window::base::cb_idle");

        base* win(static_cast<base*>(manager::get(::glutGetWindow())));

        win->idle();
      }

      /* static */ void
      base::cb_keyboard(unsigned char k, signed x, signed y)
      {
        TRACE("platform::glut::window::base::cb_keyboard");

        base* win(static_cast<base*>(manager::get(::glutGetWindow())));

        // update_queue(win->keyboardq_, { k, ::glutGetModifiers() }, win->queue_max_);
    
        win->keyboard(k, glm::ivec2(x, y));
      }
      
      /* static */ void
      base::cb_mouse(signed b, signed s, signed x, signed y)
      {
        TRACE("platform::glut::window::base::cb_mouse");

        base* win(static_cast<base*>(manager::get(::glutGetWindow())));

        // update_queue(win->mouseq_, { b, s,  glm::ivec2(x, y) }, win->queue_max_);
    
        win->mouse(b, s, glm::ivec2(x, y));
      }

      /* static */ void
      base::cb_reshape(signed w, signed h)
      {
        TRACE("platform::glut::window::base::cb_reshape");

        base* win(static_cast<base*>(manager::get(::glutGetWindow())));

        glm::ivec2 const size(w, h);
    
        if (!win->state_.fullscreen) {
          win->state_.pos  = glm::ivec2(::glutGet(GLUT_WINDOW_X), ::glutGet(GLUT_WINDOW_Y));
          win->state_.size = size;
        }
    
        win->reshape(size);
      }

      /* static */ void
      base::cb_special(signed k, signed x, signed y)
      {
        TRACE("platform::glut::window::base::cb_special");

        base* win(static_cast<base*>(manager::get(::glutGetWindow())));

        // update_queue(win->keyboardq_, { key, ::glutGetModifiers() }, win->queue_max_);
    
        win->special(k, glm::ivec2(x, y));
      }
      
    } // namespace window {

  } // namespace glut {
  
} // namespace platform {
