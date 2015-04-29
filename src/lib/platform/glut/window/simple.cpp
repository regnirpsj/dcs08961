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
#include <sstream>        // std::ostringstream
#include <stdexcept>      // std::logic_error

// includes, project

#include <platform/glut/window/manager.hpp>
#include <platform/handler/keyboard.hpp>
#include <platform/handler/mouse.hpp>
#include <window/helper.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

#define UKACHULLDCS_GLUT_WINDOW_SIMPLE_DEBUG
#undef UKACHULLDCS_GLUT_WINDOW_SIMPLE_DEBUG

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
      simple::simple(std::string const& a, rect const& b,
                     handler::frame::base* c, handler::keyboard::base* d, handler::mouse::base* e)
        : base            (a, b),
          max_queue_length(*this, "max_queue_length", 0),
          hndlr_frame_    (c),
          hndlr_kbd_      (d),
          hndlr_mouse_    (e)
      {
        TRACE("platform::glut::window::simple::simple" + exec_context(this));

        if (hndlr_kbd_) {
          ::glutKeyboardFunc  (&simple::cb_keyboard);
          ::glutKeyboardUpFunc(&simple::cb_keyboard_up);
          ::glutSpecialFunc   (&simple::cb_special);
          ::glutSpecialUpFunc (&simple::cb_special_up);
        }

        if (hndlr_mouse_) {
          ::glutMotionFunc       (&simple::cb_mouse_motion);
          ::glutMouseFunc        (&simple::cb_mouse);
          ::glutMouseWheelFunc   (&simple::cb_mouse_wheel);
          ::glutPassiveMotionFunc(&simple::cb_passive_motion);
        }
        
        ::glutReshapeFunc(&simple::cb_reshape);
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
      }

#if 0
      /* virtual */ bool
      simple::keyboard(unsigned char key, glm::ivec2 const&, bool pressed)
      {
        TRACE("platform::glut::window::simple::keyboard" + exec_context(this));

        bool result(false);
        
        if (window::manager::count()) {
#if defined(UKACHULLDCS_GLUT_WINDOW_SIMPLE_DEBUG)
          if (!keyboardq_.empty()) {
            std::cout << support::trace::prefix() << "platform::glut::window::simple::keyboard: "
                      << keyboardq_.back()
                      << '\n';
          }
#endif

          if (pressed) {
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
        }
        
        return result;
      }

      /* virtual */ bool
      simple::motion(glm::ivec2 const&, bool)
      {
        TRACE("platform::glut::window::simple::motion" + exec_context(this));

#if defined(UKACHULLDCS_GLUT_WINDOW_SIMPLE_DEBUG)
        if (!mouseq_.empty()) {
          std::cout << support::trace::prefix() << "platform::glut::window::simple::motion: "
                    << mouseq_.back()
                    << '\n';
        }
#endif
        
        return false;
      }
      
      /* virtual */ bool
      simple::mouse(signed, signed, glm::ivec2 const&, bool)
      {
        TRACE("platform::glut::window::simple::mouse" + exec_context(this));

#if defined(UKACHULLDCS_GLUT_WINDOW_SIMPLE_DEBUG)
        if (!mouseq_.empty()) {
          std::cout << support::trace::prefix() << "platform::glut::window::simple::mouse: "
                    << mouseq_.back()
                    << '\n';
        }
#endif
        
        return false;
      }
#endif // #if 0
      
      /* virtual */ void
      simple::reshape(glm::ivec2 const&)
      {
        TRACE("platform::glut::window::simple::reshape" + exec_context(this));
      }

#if 0
      /* virtual */ bool
      simple::special(signed, glm::ivec2 const&, bool)
      {
        TRACE("platform::glut::window::simple::special" + exec_context(this));

#if defined(UKACHULLDCS_GLUT_WINDOW_SIMPLE_DEBUG)
        if (!keyboardq_.empty()) {
          std::cout << support::trace::prefix() << "platform::glut::window::simple::special: "
                    << keyboardq_.back()
                    << '\n';
        }
#endif
          
        return false;
      }
#endif // #if 0
      
      /* virtual */ void
      simple::display()
      {
        TRACE("platform::glut::window::simple::display" + exec_context(this));

        if (window::manager::count()) {
          frame_render_pre ();
          frame_render_one ();
          frame_render_post();
        }
      }
      
      /* static */ void
      simple::cb_keyboard(unsigned char a, signed b, signed c)
      {
        TRACE("platform::glut::window::simple::cb_keyboard");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          using key = platform::handler::keyboard::key;
          
          w->hndlr_kbd_->press(key::ascii(a),
                               key::modifier(::glutGetModifiers()),
                               glm::ivec2(b, c));
        }
      }
      
      /* static */ void
      simple::cb_keyboard_up(unsigned char a, signed b, signed c)
      {
        TRACE("platform::glut::window::simple::cb_keyboard_up");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          using key = platform::handler::keyboard::key;
          
          w->hndlr_kbd_->release(key::ascii(a),
                                 key::modifier(::glutGetModifiers()),
                                 glm::ivec2(b, c));
        }
      }
      
      /* static */ void
      simple::cb_mouse(signed a, signed b, signed c, signed d)
      {
        TRACE("platform::glut::window::simple::cb_mouse");
        
        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          using key = platform::handler::keyboard::key;
          using namespace platform::handler::mouse;

          if (b) {
            w->hndlr_mouse_->press  (button(a),
                                     key::modifier(::glutGetModifiers()),
                                     glm::ivec2(c, d));
          } else {
            w->hndlr_mouse_->release(button(a),
                                     key::modifier(::glutGetModifiers()),
                                     glm::ivec2(c, d));
          }
        }
      }
      
      /* static */ void
      simple::cb_mouse_motion(signed a, signed b)
      {
        TRACE("platform::glut::window::simple::cb_mouse_motion");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          using key = platform::handler::keyboard::key;
          using namespace platform::handler::mouse;
          
          w->hndlr_mouse_->motion(key::modifier(::glutGetModifiers()), glm::ivec2(a, b));
        }
      }
      
      /* static */ void
      simple::cb_mouse_wheel(signed /* wheel */, signed b, signed c, signed d)
      {
        TRACE("platform::glut::window::simple::cb_mouse_wheel");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          using key = platform::handler::keyboard::key;
          using namespace platform::handler::mouse;
          
          w->hndlr_mouse_->scroll(1.0, direction(b),
                                  key::modifier(::glutGetModifiers()), glm::ivec2(c, d));
        }
      }
      
      /* static */ void
      simple::cb_passive_motion(signed a, signed b)
      {
        TRACE("platform::glut::window::simple::cb_passive_motion");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));
        
        if (w) {
          using key = platform::handler::keyboard::key;
          using namespace platform::handler::mouse;
          
          w->hndlr_mouse_->motion(key::modifier(::glutGetModifiers()), glm::ivec2(a, b));
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
          using key = platform::handler::keyboard::key;
          
          w->hndlr_kbd_->press(key::code(a),
                               key::modifier(::glutGetModifiers()),
                               glm::ivec2(b, c));
        }
      }
      
      /* static */ void
      simple::cb_special_up(signed a, signed b, signed c)
      {
        TRACE("platform::glut::window::simple::cb_special_up");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          using key = platform::handler::keyboard::key;
          
          w->hndlr_kbd_->release(key::code(a),
                                 key::modifier(::glutGetModifiers()),
                                 glm::ivec2(b, c));
        }
      }
      
    } // namespace window {

  } // namespace glut {
  
} // namespace platform {
