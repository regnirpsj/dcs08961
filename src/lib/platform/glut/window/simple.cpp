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
      simple::dflt_keyboard_handler::dflt_keyboard_handler(simple& a)
        : inherited(1),
          window_  (a)
      {
        TRACE("platform::glut::window::simple::dflt_keyboard_handler::dflt_keyboard_handler" +
              exec_context(&window_));
      }

      /* virtual */ bool
      simple::dflt_keyboard_handler::press(key::ascii a, uint8_t b,
                                           glm::ivec2 const& c, time_point const& d)
      {
        TRACE("platform::glut::window::simple::dflt_keyboard_handler::press" +
              exec_context(&window_));

        bool result(inherited::press(a, b, c, d));
        
        if (window::manager::count()) {
          
#if defined(UKACHULLDCS_GLUT_WINDOW_SIMPLE_DEBUG)
          {
            std::cout << support::trace::prefix()
                      << "platform::glut::window::simple::dflt_keyboard_handler::press: "
                      << keyboardq_.back()
                      << '\n';
          }
#endif
          
          switch (a) {
          case key::ascii::ESC:
            {
              window_.close();

              result |= true;
            }
            break;

          case key::ascii::f:
            {
              ::glutFullScreenToggle   ();
              ::glutPostWindowRedisplay(window_.id.get());

              result |= true;
            }
            break;
              
          default:
            break;
          }
        }
        
        return result;
      }
      
      /* explicit */
      simple::simple(std::string const& a, rect const& b)
        : base                  (a, b),
          keyboard_handler      (*this, "keyboard_handler"),
          mouse_handler         (*this, "mouse_handler"),
          dflt_keyboard_handler_(new dflt_keyboard_handler(*this))
      {
        TRACE("platform::glut::window::simple::simple" + exec_context(this));
        
        keyboard_handler += dflt_keyboard_handler_.get();
        
        ::glutReshapeFunc(&simple::cb_reshape);
      }

      /* virtual */ void
      simple::do_changed(field::base& f)
      {
        TRACE("platform::glut::window::simple::do_changed" + exec_context(this));

        if      (&f == &keyboard_handler) {
          adjust_keyboard_handler_callbacks();
        }

        else if (&f == &mouse_handler) {
          adjust_mouse_handler_callbacks();
        }

        else {
          base::do_changed(f);
        }
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
      
      /* virtual */ void
      simple::reshape(glm::ivec2 const&)
      {
        TRACE("platform::glut::window::simple::reshape" + exec_context(this));
      }
      
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
          
          support::clock::time_point const now(support::clock::now());
          glm::ivec2 const                 pos(b, c);
          
          for (auto kh: w->keyboard_handler.get()) {
            kh->press(key::ascii(a), key::modifier(::glutGetModifiers()), pos, now);
          }
        }
      }
      
      /* static */ void
      simple::cb_keyboard_up(unsigned char a, signed b, signed c)
      {
        TRACE("platform::glut::window::simple::cb_keyboard_up");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          using key = platform::handler::keyboard::key;

          support::clock::time_point const now(support::clock::now());
          glm::ivec2 const                 pos(b, c);
          
          for (auto kh: w->keyboard_handler.get()) {
            kh->release(key::ascii(a), key::modifier(::glutGetModifiers()), pos, now);
          }
        }
      }
      
      /* static */ void
      simple::cb_mouse(signed a, signed b, signed c, signed d)
      {
        TRACE("platform::glut::window::simple::cb_mouse");
        
        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          using key    = platform::handler::keyboard::key;
          using button = platform::handler::mouse::button;

          support::clock::time_point const now(support::clock::now());
          glm::ivec2 const                 pos(c, d);
          
          for (auto mh: w->mouse_handler.get()) {
            if (b) {
              mh->press  (button(a), key::modifier(::glutGetModifiers()), pos, now);
            } else {
              mh->release(button(a), key::modifier(::glutGetModifiers()), pos, now);
            }
          }
        }
      }
      
      /* static */ void
      simple::cb_mouse_motion(signed a, signed b)
      {
        TRACE("platform::glut::window::simple::cb_mouse_motion");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          using key    = platform::handler::keyboard::key;
          using button = platform::handler::mouse::button;

          support::clock::time_point const now(support::clock::now());
          glm::ivec2 const                 pos(a, b);
          
          for (auto mh: w->mouse_handler.get()) {
            mh->press(button::none, key::modifier(::glutGetModifiers()), pos, now);
          }
        }
      }
      
      /* static */ void
      simple::cb_mouse_wheel(signed /* wheel */, signed b, signed c, signed d)
      {
        TRACE("platform::glut::window::simple::cb_mouse_wheel");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          using key       = platform::handler::keyboard::key;
          using direction = platform::handler::mouse::direction;

          support::clock::time_point const now(support::clock::now());
          glm::ivec2 const                 pos(c, d);
          
          for (auto mh: w->mouse_handler.get()) {
            mh->scroll(1.0, direction(b), key::modifier(::glutGetModifiers()), pos, now);
          }
        }
      }
      
      /* static */ void
      simple::cb_passive_motion(signed a, signed b)
      {
        TRACE("platform::glut::window::simple::cb_passive_motion");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));
        
        if (w) {
          using key = platform::handler::keyboard::key;

          support::clock::time_point const now(support::clock::now());
          glm::ivec2 const                 pos(a, b);
          
          for (auto mh: w->mouse_handler.get()) {
            mh->motion(key::modifier(::glutGetModifiers()), pos, now);
          }
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
          
          support::clock::time_point const now(support::clock::now());
          glm::ivec2 const                 pos(b, c);
          
          for (auto kh: w->keyboard_handler.get()) {
            kh->press(key::code(a), key::modifier(::glutGetModifiers()), pos, now);
          }
        }
      }
      
      /* static */ void
      simple::cb_special_up(signed a, signed b, signed c)
      {
        TRACE("platform::glut::window::simple::cb_special_up");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          using key = platform::handler::keyboard::key;
          
          support::clock::time_point const now(support::clock::now());
          glm::ivec2 const                 pos(b, c);
          
          for (auto kh: w->keyboard_handler.get()) {
            kh->release(key::code(a), key::modifier(::glutGetModifiers()), pos, now);
          }
        }
      }

      void
      simple::adjust_keyboard_handler_callbacks()
      {
        TRACE("platform::glut::window::simple::adjust_keyboard_handler_callbacks");

        if (!keyboard_handler->empty()) {
          ::glutKeyboardFunc  (&simple::cb_keyboard);
          ::glutKeyboardUpFunc(&simple::cb_keyboard_up);
          ::glutSpecialFunc   (&simple::cb_special);
          ::glutSpecialUpFunc (&simple::cb_special_up);
        } else {
          ::glutKeyboardFunc  (nullptr);
          ::glutKeyboardUpFunc(nullptr);
          ::glutSpecialFunc   (nullptr);
          ::glutSpecialUpFunc (nullptr);
        }
      }
      
      void
      simple::adjust_mouse_handler_callbacks()
      {
        TRACE("platform::glut::window::simple::adjust_mouse_handler_callbacks");

        if (!mouse_handler->empty()) {
          ::glutMotionFunc       (&simple::cb_mouse_motion);
          ::glutMouseFunc        (&simple::cb_mouse);
          ::glutMouseWheelFunc   (&simple::cb_mouse_wheel);
          ::glutPassiveMotionFunc(&simple::cb_passive_motion);
        } else {
          ::glutMotionFunc       (nullptr);
          ::glutMouseFunc        (nullptr);
          ::glutMouseWheelFunc   (nullptr);
          ::glutPassiveMotionFunc(nullptr);
        }
      }
      
    } // namespace window {

  } // namespace glut {
  
} // namespace platform {
