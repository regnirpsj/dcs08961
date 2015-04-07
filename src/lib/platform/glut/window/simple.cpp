// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glut/window/simple.cpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/glut/window/simple.hpp"

// includes, system

// needs to be first!!!
#include <GL/glew.h>      // gl*

#include <GL/freeglut.h>  // ::glut*
#include <glm/gtx/io.hpp> // glm::operator<< (field::container::print_on)
#include <stdexcept>      // std::logic_error

// includes, project

#include <platform/glut/window/manager.hpp>
#include <window/helper.hpp>

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

      /* explicit */
      simple::simple(std::string const& a, rect const& b)
        : base(a, b)
      {
        TRACE("platform::glut::window::simple::simple" + exec_context(this));

        ::glutKeyboardFunc     (&simple::cb_keyboard);
        //::glutKeyboardUpFunc   (&simple::cb_keyboard_up);
        ::glutMotionFunc       (&simple::cb_mouse_motion);
        ::glutMouseFunc        (&simple::cb_mouse);
        ::glutMouseWheelFunc   (&simple::cb_mouse_wheel);
        ::glutPassiveMotionFunc(&simple::cb_passive_motion);
        ::glutReshapeFunc      (&simple::cb_reshape);
        ::glutSpecialFunc      (&simple::cb_special);
        //::glutSpecialUpFunc    (&simple::cb_special_up);
      }

      /* virtual */ void
      simple::frame_render_one()
      {
        TRACE("platform::glut::window::simple::frame_render_one" + exec_context(this));

        throw std::logic_error("pure virtual function "
                               "'platform::glut::window::simple::frame_render_one' called");
      }

      /* virtual */ void
      simple::frame_render_post()
      {
        TRACE_NEVER("platform::glut::window::simple::frame_render_post" + exec_context(this));

        if (window::manager::count()) {
          ::glutSwapBuffers();
        }
      }
      
      /* virtual */ void
      simple::frame_render_pre()
      {
        TRACE_NEVER("platform::glut::window::simple::frame_render_pre" + exec_context(this));

        if (window::manager::count()) {
          ::glClearColor(0.95f, 0.95f, 0.95f, 0.0f);
          ::glClearDepth(1.0f);
          ::glClear     (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }
      }
      
      /* virtual */ bool
      simple::keyboard(unsigned char key, glm::ivec2 const&, bool)
      {
        TRACE("platform::glut::window::simple::keyboard" + exec_context(this));

        bool result(false);
        
        if (window::manager::count()) {
          switch (key) {
          case 0x1B: // ESC
            {
              close();

              result = true;
            }
            break;

          case 'f': // fullscreen toggle
            {
              ::glutFullScreenToggle   ();
              ::glutPostWindowRedisplay(id.get());

              result = true;
            }
            break;
          
          default:
            break;
          }
        }

        return result;
      }
      
      /* virtual */ bool
      simple::motion(glm::ivec2 const&, bool)
      {
        TRACE("platform::glut::window::simple::motion" + exec_context(this));

        return false;
      }
      
      /* virtual */ bool
      simple::mouse(signed, signed, glm::ivec2 const&, bool)
      {
        TRACE("platform::glut::window::simple::mouse" + exec_context(this));

        return false;
      }

      /* virtual */ void
      simple::reshape(glm::ivec2 const&)
      {
        TRACE("platform::glut::window::simple::reshape" + exec_context(this));
      }

      /* virtual */ bool
      simple::special(signed, glm::ivec2 const&, bool)
      {
        TRACE("platform::glut::window::simple::special" + exec_context(this));
        
        return false;
      }

      /* virtual */ void
      simple::display()
      {
        TRACE("platform::glut::window::simple::display" + exec_context(this));

        frame_render_pre ();
        frame_render_one ();
        frame_render_post();
      }

      /* static */ void
      simple::cb_keyboard(unsigned char a, signed b, signed c)
      {
        TRACE("platform::glut::window::simple::cb_keyboard");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        // update_queue(w->keyboardq_, { a, ::glutGetModifiers() }, w->queue_max_);
    
        w->keyboard(a, glm::ivec2(b, c), false);
      }

      /* static */ void
      simple::cb_keyboard_up(unsigned char a, signed b, signed c)
      {
        TRACE("platform::glut::window::simple::cb_keyboard_up");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          // update_queue(w->keyboardq_, { a, ::glutGetModifiers() }, w->queue_max_);
    
          w->keyboard(a, glm::ivec2(b, c), true);
        }
      }
      
      /* static */ void
      simple::cb_mouse(signed a, signed b, signed c, signed d)
      {
        TRACE("platform::glut::window::simple::cb_mouse");
        
        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          // update_queue(w->mouseq_, { a, b,  glm::ivec2(x, y) }, w->queue_max_);
    
          w->mouse(a, b, glm::ivec2(c, d), false);
        }
      }
      
      /* static */ void
      simple::cb_mouse_motion(signed a, signed b)
      {
        TRACE("platform::glut::window::simple::cb_mouse_motion");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          // update_queue(w->mouseq_, { a, b,  glm::ivec2(x, y) }, w->queue_max_);
    
          w->motion(glm::ivec2(a, b), true);
        }
      }
      
      /* static */ void
      simple::cb_mouse_wheel(signed a, signed b, signed c, signed d)
      {
        TRACE("platform::glut::window::simple::cb_mouse_wheel");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          // update_queue(w->mouseq_, { a, b,  glm::ivec2(x, y) }, w->queue_max_);
    
          w->mouse(a, b, glm::ivec2(c, d), true);
        }
      }
      
      /* static */ void
      simple::cb_passive_motion(signed a, signed b)
      {
        TRACE("platform::glut::window::simple::cb_passive_motion");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          // update_queue(w->mouseq_, { b, s,  glm::ivec2(x, y) }, w->queue_max_);
    
          w->motion(glm::ivec2(a, b), false);
        }
      }
      
      /* static */ void
      simple::cb_reshape(signed a, signed b)
      {
        TRACE("platform::glut::window::simple::cb_reshape");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          glm::ivec2 const size(a, b);
    
          if (!glutGet(GLUT_FULL_SCREEN)) {
            w->position = glm::ivec2(::glutGet(GLUT_WINDOW_X), ::glutGet(GLUT_WINDOW_Y));
            w->size     = size;
          }
    
          w->reshape(size);
        }
      }
      
      /* static */ void
      simple::cb_special(signed a, signed b, signed c)
      {
        TRACE("platform::glut::window::simple::cb_special");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          // update_queue(w->keyboardq_, { a, ::glutGetModifiers() }, w->queue_max_);
    
          w->special(a, glm::ivec2(b, c), false);
        }
      }
      
      /* static */ void
      simple::cb_special_up(signed a, signed b, signed c)
      {
        TRACE("platform::glut::window::simple::cb_special_up");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          // update_queue(w->keyboardq_, { a, ::glutGetModifiers() }, w->queue_max_);
    
          w->special(a, glm::ivec2(b, c), true);
        }
      }
      
    } // namespace window {

  } // namespace glut {
  
} // namespace platform {
