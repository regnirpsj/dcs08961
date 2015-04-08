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
#include <window/helper.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

  std::string const
  button_to_string(signed a)
  {
    std::string result("[]");

    switch (a) {
    case GLUT_LEFT_BUTTON:   result.insert(1, "LEFT");   break;
    case GLUT_MIDDLE_BUTTON: result.insert(1, "MIDDLE"); break;
    case GLUT_RIGHT_BUTTON:  result.insert(1, "RIGHT");  break;
    default:                 result.insert(1, "NONE");   break;
    }

    return result;
  }

  std::string const
  button_key_state_to_string(signed a)
  {
    std::string result("[]");

    result.insert(1, a ? "  UP" : "DOWN");
    
    return result;
  }
  
  std::string const
  modifier_to_string(signed a)
  {
    std::string result;
    
    if (GLUT_ACTIVE_ALT   & a) { result += "ALT|";   }
    if (GLUT_ACTIVE_CTRL  & a) { result += "CTRL|";  }
    if (GLUT_ACTIVE_SHIFT & a) { result += "SHIFT|"; }

    if (result.empty()) {
      result = "[NONE]";
    } else {
      result.pop_back();
      
      result = "[" + result + "]";
    }

    return result;
  }

  std::string const
  time_stamp_to_string(support::clock::time_point const& a)
  {
    using namespace std::chrono;
    
    std::ostringstream ostr;

    ostr << std::dec
         << std::setw(12)
         << duration_cast<microseconds>(a.time_since_epoch()).count();
    
    return ostr.str();
  }
  
  template <typename T>
  void
  update_queue(std::deque<T>& q, T const& e, unsigned l)
  {
    if (0 < l) {
      q.push_back(e);
      
      if (q.size() > (l + 1)) {
        q.pop_front();
      }
    }
  }
  
} // namespace {

namespace platform {

  namespace glut {

    namespace window {
  
      // variables, exported
  
      // functions, exported

      /* explicit */
      simple::simple(std::string const& a, rect const& b)
        : base            (a, b),
          max_queue_length(*this, "max_queue_length", 3),
          keyboardq_      (),
          mouseq_         ()
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

#if 1
          if (!keyboardq_.empty()) {
            auto const& k(keyboardq_.back());
      
            std::cout << support::trace::prefix() << "platform::glut::window::simple::keyboard: "
                      << static_cast<unsigned char>(k.key - '\0') << ','
                      << modifier_to_string(k.modifier)           << ','
                      << button_key_state_to_string(k.key_up)     << ','
                      << time_stamp_to_string(k.stamp)
                      << '\n';
          }
#endif
        }

        return result;
      }
      
      /* virtual */ bool
      simple::motion(glm::ivec2 const&, bool)
      {
        TRACE("platform::glut::window::simple::motion" + exec_context(this));

#if 1
        if (!mouseq_.empty()) {
          auto const& m(mouseq_.back());
          
          std::cout << support::trace::prefix() << "platform::glut::window::simple::motion: "
                    << button_to_string(m.button)          << ','
                    << button_key_state_to_string(m.state) << ','
                    << modifier_to_string(m.modifier)      << ','
                    << glm::io::width(4)
                    << m.pos                               << ','
                    << time_stamp_to_string(m.stamp)
                    << '\n';
        }
#endif
        
        return false;
      }
      
      /* virtual */ bool
      simple::mouse(signed, signed, glm::ivec2 const&, bool)
      {
        TRACE("platform::glut::window::simple::mouse" + exec_context(this));

#if 1
        if (!mouseq_.empty()) {
          auto const& m(mouseq_.back());
          
          std::cout << support::trace::prefix() << "platform::glut::window::simple::mouse: "
                    << button_to_string(m.button)          << ','
                    << button_key_state_to_string(m.state) << ','
                    << modifier_to_string(m.modifier)      << ','
                    << glm::io::width(4)
                    << m.pos                               << ','
                    << time_stamp_to_string(m.stamp)
                    << '\n';
        }
#endif
        
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

#if 1
        if (!keyboardq_.empty()) {
          auto const& k(keyboardq_.back());
      
          std::cout << support::trace::prefix() << "platform::glut::window::simple::special: "
                    << k.key                                << ','
                    << modifier_to_string(k.modifier)       << ','
                    << button_key_state_to_string(k.key_up) << ','
                    << time_stamp_to_string(k.stamp)
                    << '\n';
        }
#endif
          
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

        if (w) {
          using clock = support::clock;
          
          update_queue(w->keyboardq_,
                       { a, ::glutGetModifiers(), false, clock::now() },
                       *w->max_queue_length);
        }
        
        w->keyboard(a, glm::ivec2(b, c), false);
      }

      /* static */ void
      simple::cb_keyboard_up(unsigned char a, signed b, signed c)
      {
        TRACE("platform::glut::window::simple::cb_keyboard_up");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          using clock = support::clock;
          
          update_queue(w->keyboardq_,
                       { a, ::glutGetModifiers(), true, clock::now() },
                       *w->max_queue_length);
    
          w->keyboard(a, glm::ivec2(b, c), true);
        }
      }
      
      /* static */ void
      simple::cb_mouse(signed a, signed b, signed c, signed d)
      {
        TRACE("platform::glut::window::simple::cb_mouse");
        
        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          using clock = support::clock;
          
          glm::ivec2 const pos(c, d);
          
          update_queue(w->mouseq_,
                       { a, b, ::glutGetModifiers(), pos, clock::now() },
                       *w->max_queue_length);
          
          w->mouse(a, b, pos, false);
        }
      }
      
      /* static */ void
      simple::cb_mouse_motion(signed a, signed b)
      {
        TRACE("platform::glut::window::simple::cb_mouse_motion");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          using clock = support::clock;

          static mouse_info_t const dflt({ -1, false, 0, glm::ivec2(), clock::now() });

          mouse_info_t info(dflt);

          if (!w->mouseq_.empty()) {
            info = w->mouseq_.back();
          }

          info.state = dflt.state;
          info.pos   = glm::ivec2(a, b);
          info.stamp = clock::now();
            
          update_queue(w->mouseq_, info, *w->max_queue_length);
    
          w->motion(info.pos, true);
        }
      }
      
      /* static */ void
      simple::cb_mouse_wheel(signed a, signed b, signed c, signed d)
      {
        TRACE("platform::glut::window::simple::cb_mouse_wheel");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          using clock = support::clock;
          
          glm::ivec2 const pos(c, d);
          
          update_queue(w->mouseq_,
                       { (a * b), false, ::glutGetModifiers(), pos, clock::now() },
                       *w->max_queue_length);
          
          w->mouse(a, b, pos, true);
        }
      }
      
      /* static */ void
      simple::cb_passive_motion(signed a, signed b)
      {
        TRACE("platform::glut::window::simple::cb_passive_motion");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));
        
        if (w) {
          using clock = support::clock;

          static mouse_info_t const dflt({ -1, true, 0, glm::ivec2(), clock::now() });

          mouse_info_t info(dflt);

          if (!w->mouseq_.empty()) {
            info = w->mouseq_.back();
          }

          info.state = dflt.state;
          info.pos   = glm::ivec2(a, b);
          info.stamp = clock::now();
            
          update_queue(w->mouseq_, info, *w->max_queue_length);
    
          w->motion(info.pos, false);
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
          using clock = support::clock;
          
          update_queue(w->keyboardq_,
                       { a, ::glutGetModifiers(), false, clock::now() },
                       *w->max_queue_length);
    
          w->special(a, glm::ivec2(b, c), false);
        }
      }
      
      /* static */ void
      simple::cb_special_up(signed a, signed b, signed c)
      {
        TRACE("platform::glut::window::simple::cb_special_up");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          using clock = support::clock;
          
          update_queue(w->keyboardq_,
                       { a, ::glutGetModifiers(), true, clock::now() },
                       *w->max_queue_length);
    
          w->special(a, glm::ivec2(b, c), true);
        }
      }
      
    } // namespace window {

  } // namespace glut {
  
} // namespace platform {
