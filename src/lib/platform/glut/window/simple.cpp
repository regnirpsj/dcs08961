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

#include <array>          // std::array<>

// needs to be first!!!
#include <GL/glew.h>      // gl*

#include <GL/freeglut.h>  // ::glut*
#include <glm/gtx/io.hpp> // glm::operator<< (field::container::print_on)
#include <sstream>        // std::ostringstream
#include <stdexcept>      // std::logic_error
#include <utility>        // std::make_pair<>

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

  class convert {

  public:
    
    using key = platform::handler::keyboard::key;
    
    static key::ascii to_key_ascii(unsigned char a)
    {
      key::ascii result(key::ascii::NUL);

      if (uint8_t(key::ascii::DEL) >= a) {
        result = key::ascii(a);
      }

      return result;
    }

    static key::code to_key_code(signed a)
    {
      static std::array<std::pair<signed const, key::code const>, 13> const fkeys = {
        {
          std::make_pair(0x00,               key::code::Invalid),
          std::make_pair(GLUT_KEY_F1,        key::code::F1),
          std::make_pair(GLUT_KEY_F2,        key::code::F2),
          std::make_pair(GLUT_KEY_F3,        key::code::F3),
          std::make_pair(GLUT_KEY_F4,        key::code::F4),
          std::make_pair(GLUT_KEY_F5,        key::code::F5),
          std::make_pair(GLUT_KEY_F6,        key::code::F6),
          std::make_pair(GLUT_KEY_F7,        key::code::F7),
          std::make_pair(GLUT_KEY_F8,        key::code::F8),
          std::make_pair(GLUT_KEY_F9,        key::code::F9),
          std::make_pair(GLUT_KEY_F10,       key::code::F10),
          std::make_pair(GLUT_KEY_F11,       key::code::F11),
          std::make_pair(GLUT_KEY_F12,       key::code::F12),
        }
      };

      static std::array<std::pair<signed const, key::code const>, 18> const ckeys = {
        {
          std::make_pair(GLUT_KEY_LEFT,      key::code::Left),
          std::make_pair(GLUT_KEY_UP,        key::code::Up),
          std::make_pair(GLUT_KEY_RIGHT,     key::code::Right),
          std::make_pair(GLUT_KEY_DOWN,      key::code::Down),
          std::make_pair(GLUT_KEY_PAGE_UP,   key::code::PageUp),
          std::make_pair(GLUT_KEY_PAGE_DOWN, key::code::PageDown),
          std::make_pair(GLUT_KEY_HOME,      key::code::Home),
          std::make_pair(GLUT_KEY_END,       key::code::End),
          std::make_pair(GLUT_KEY_INSERT,    key::code::Insert),
          std::make_pair(GLUT_KEY_NUM_LOCK,  key::code::NumLock),
          std::make_pair(GLUT_KEY_BEGIN,     key::code::Begin),
          std::make_pair(GLUT_KEY_DELETE,    key::code::Delete),
          std::make_pair(GLUT_KEY_SHIFT_L,   key::code::ShiftLeft),
          std::make_pair(GLUT_KEY_SHIFT_R,   key::code::ShiftRight),
          std::make_pair(GLUT_KEY_CTRL_L,    key::code::CtrlLeft),
          std::make_pair(GLUT_KEY_CTRL_R,    key::code::CtrlRight),
          std::make_pair(GLUT_KEY_ALT_L,     key::code::AltLeft),
          std::make_pair(GLUT_KEY_ALT_R,     key::code::AltRight),
        }
      };

      key::code result(key::code::Invalid);

      if        ((fkeys.front().first < a) && (fkeys.back().first >= a)) {
        result = fkeys[a].second;
      } else if ((ckeys.front().first <= a) && (ckeys.back().first >= a)) {
        result = ckeys[a - ckeys.front().first].second;
      }

      return result;
    }

    static uint8_t to_key_modifier(signed a)
    {
      static std::array<std::pair<signed const, key::modifier const>, 3> const modifier = {
        {
          std::make_pair(GLUT_ACTIVE_ALT,   key::modifier::Alt),
          std::make_pair(GLUT_ACTIVE_CTRL,  key::modifier::Ctrl),
          std::make_pair(GLUT_ACTIVE_SHIFT, key::modifier::Shift),
        }
      };
      
      uint8_t result(key::modifier::None);

      if (0 < a) {
        for (auto m : modifier) {
          if (m.first & a) {
            result |= m.second;
          }
        }
      }
      
      return result;
    }
    
    using mouse_button    = platform::handler::mouse::button;
    using wheel_direction = platform::handler::mouse::direction;

    static mouse_button to_mouse_button(signed a)
    {
      static std::array<std::pair<signed const, mouse_button const>, 9> const buttons = {
        {
          std::make_pair(GLUT_LEFT_BUTTON,   mouse_button::left),
          std::make_pair(GLUT_MIDDLE_BUTTON, mouse_button::middle),
          std::make_pair(GLUT_RIGHT_BUTTON,  mouse_button::right),
          std::make_pair(3,                  mouse_button::wheel),
          std::make_pair(4,                  mouse_button::aux5),
          std::make_pair(5,                  mouse_button::aux6),
          std::make_pair(6,                  mouse_button::aux7),
          std::make_pair(7,                  mouse_button::aux8),
          std::make_pair(8,                  mouse_button::aux9),
        }
      };
      
      mouse_button result(mouse_button::none);

      if ((buttons.front().first <= a) && (buttons.back().first >= a)) {
        result = buttons[a].second;
      } else {
        result = mouse_button(a);
      }
        
      return result;
    }
      
    static wheel_direction to_wheel_direction(signed a, signed)
    {
      wheel_direction result(wheel_direction::none);

      switch (a) {
      case 3: result = wheel_direction::down;  break;
      case 4: result = wheel_direction::up;    break;
      case 5: result = wheel_direction::left;  break;
      case 6: result = wheel_direction::right; break;
      }
      
      return result;
    }
    
  };
  
  // variables, internal
  
  // functions, internal
  
} // namespace {

namespace platform {

  namespace glut {

    namespace window {
  
      // variables, exported
  
      // functions, exported

      /* explicit */
      simple::dflt_handler::dflt_handler(simple& a)
        : platform::handler::keyboard::base(1),
          platform::handler::mouse::base   (1),
          window_                          (a)
      {
        TRACE("platform::glut::window::simple::dflt_handler::dflt_handler" +
              exec_context(&window_));
      }

      /* virtual */ bool
      simple::dflt_handler::press(key::ascii a, uint8_t b,
                                  glm::ivec2 const& c, time_point const& d)
      {
        TRACE("platform::glut::window::simple::dflt_handler::press(key::ascii)" +
              exec_context(&window_));

        bool result(kbd_base::press(a, b, c, d));

#if defined(UKACHULLDCS_GLUT_WINDOW_SIMPLE_DEBUG)
        std::cout << support::trace::prefix()
                  << "platform::glut::window::simple::dflt_handler::press(key::ascii):\t"
                  << keyboardq_.back()
                  << '\n';
#endif
          
        if (window::manager::count()) {          
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

      /* virtual */ bool
      simple::dflt_handler::press(key::code a, uint8_t b,
                                  glm::ivec2 const& c, time_point const& d)
      {
        TRACE("platform::glut::window::simple::dflt_handler::press(key::code)" +
              exec_context(&window_));

        bool const result(kbd_base::press(a, b, c, d));
          
#if defined(UKACHULLDCS_GLUT_WINDOW_SIMPLE_DEBUG)
        std::cout << support::trace::prefix()
                  << "platform::glut::window::simple::dflt_handler::press(key::code):\t"
                  << keyboardq_.back()
                  << '\n';
#endif          
        
        return result;
      }

      /* virtual */ bool
      simple::dflt_handler::release(key::ascii a, uint8_t b,
                                    glm::ivec2 const& c, time_point const& d)
      {
        TRACE("platform::glut::window::simple::dflt_handler::release(key::ascii)" +
              exec_context(&window_));

        bool const result(kbd_base::release(a, b, c, d));
          
#if defined(UKACHULLDCS_GLUT_WINDOW_SIMPLE_DEBUG)
        std::cout << support::trace::prefix()
                  << "platform::glut::window::simple::dflt_handler::release(key::ascii):\t"
                  << keyboardq_.back()
                  << '\n';
#endif          
        
        return result;
      }
      
      /* virtual */ bool
      simple::dflt_handler::release(key::code a, uint8_t b,
                                    glm::ivec2 const& c, time_point const& d)
      {
        TRACE("platform::glut::window::simple::dflt_handler::release(key::code)" +
              exec_context(&window_));

        bool const result(kbd_base::release(a, b, c, d));
          
#if defined(UKACHULLDCS_GLUT_WINDOW_SIMPLE_DEBUG)
        std::cout << support::trace::prefix()
                  << "platform::glut::window::simple::dflt_handler::release(key::code):\t"
                  << keyboardq_.back()
                  << '\n';
#endif          
        
        return result;
      }

      /* virtual */ bool
      simple::dflt_handler::motion(uint8_t a,
                                   glm::ivec2 const& b, time_point const& c)
      {
        TRACE("platform::glut::window::simple::dflt_handler::motion" +
              exec_context(&window_));

        bool const result(mouse_base::motion(a, b, c));
          
#if defined(UKACHULLDCS_GLUT_WINDOW_SIMPLE_DEBUG)
        std::cout << support::trace::prefix()
                  << "platform::glut::window::simple::dflt_handler::motion:\t\t"
                  << mouseq_.back()
                  << '\n';
#endif          
        
        return result;
      }
        
      /* virtual */ bool
      simple::dflt_handler::press(button a, uint8_t b,
                                  glm::ivec2 const& c, time_point const& d)
      {
        TRACE("platform::glut::window::simple::dflt_handler::press(button)" +
              exec_context(&window_));

        bool const result(mouse_base::press(a, b, c, d));
          
#if defined(UKACHULLDCS_GLUT_WINDOW_SIMPLE_DEBUG)
        std::cout << support::trace::prefix()
                  << "platform::glut::window::simple::dflt_handler::press(button):\t\t"
                  << mouseq_.back()
                  << '\n';
#endif          
        
        return result;
      }
        
      /* virtual */ bool
      simple::dflt_handler::release(button a, uint8_t b,
                                    glm::ivec2 const& c, time_point const& d)
      {
        TRACE("platform::glut::window::simple::dflt_handler::release(button)" +
              exec_context(&window_));

        bool const result(mouse_base::release(a, b, c, d));
          
#if defined(UKACHULLDCS_GLUT_WINDOW_SIMPLE_DEBUG)
        std::cout << support::trace::prefix()
                  << "platform::glut::window::simple::dflt_handler::release(button):\t"
                  << mouseq_.back()
                  << '\n';
#endif          
        
        return result;
      }
      
      /* virtual */ bool
      simple::dflt_handler::scroll(float a, direction b, uint8_t c,
                                   glm::ivec2 const& d, time_point const& e)
      {
        TRACE("platform::glut::window::simple::dflt_handler::scroll" +
              exec_context(&window_));

        bool const result(mouse_base::scroll(a, b, c, d, e));
          
#if defined(UKACHULLDCS_GLUT_WINDOW_SIMPLE_DEBUG)
        std::cout << support::trace::prefix()
                  << "platform::glut::window::simple::dflt_handler::scroll:\t\t"
                  << mouseq_.back()
                  << '\n';
#endif          
        
        return result;
      }

      /* virtual */ void
      simple::dflt_handler::print_on(std::ostream& os) const
      {
        TRACE_NEVER("platform::glut::window::simple::dflt_handler::print_on" +
                    exec_context(&window_));

        os << '[';
        
        kbd_base::print_on  (os);
        mouse_base::print_on(os);

        os << ']';
      }
      
      /* explicit */
      simple::simple(std::string const& a, rect const& b, bool c)
        : base            (a, b),
          keyboard_handler(*this, "keyboard_handler"),
          mouse_handler   (*this, "mouse_handler"),
          dflt_handler_   (nullptr)
      {
        TRACE("platform::glut::window::simple::simple" + exec_context(this));

        ::glutReshapeFunc(&simple::cb_reshape);
        
        if (c) {
          dflt_handler_.reset(new dflt_handler(*this));

          using namespace platform::handler;
          
          keyboard_handler += dynamic_cast<keyboard::base*>(dflt_handler_.get());
          mouse_handler    += dynamic_cast<mouse::base*>   (dflt_handler_.get());
        }
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
          support::clock::time_point const now(support::clock::now());
          glm::ivec2 const                 pos(b, c);
          
          for (auto kh: w->keyboard_handler.get()) {
            kh->press(convert::to_key_ascii   (a),
                      convert::to_key_modifier(::glutGetModifiers()),
                      pos, now);
          }
        }
      }
      
      /* static */ void
      simple::cb_keyboard_up(unsigned char a, signed b, signed c)
      {
        TRACE("platform::glut::window::simple::cb_keyboard_up");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          support::clock::time_point const now(support::clock::now());
          glm::ivec2 const                 pos(b, c);
          
          for (auto kh: w->keyboard_handler.get()) {
            kh->release(convert::to_key_ascii   (a),
                        convert::to_key_modifier(::glutGetModifiers()),
                        pos, now);
          }
        }
      }
      
      /* static */ void
      simple::cb_mouse(signed a, signed b, signed c, signed d)
      {
        TRACE("platform::glut::window::simple::cb_mouse");
        
        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          using button = platform::handler::mouse::button;

          support::clock::time_point const now(support::clock::now());
          glm::ivec2 const                 pos(c, d);
          uint8_t const                    mod(convert::to_key_modifier(::glutGetModifiers()));
          button const                     btn(convert::to_mouse_button(a));
          
          for (auto mh: w->mouse_handler.get()) {
            switch (b) {
            case GLUT_DOWN: mh->press  (btn, mod, pos, now); break;
            case GLUT_UP:   mh->release(btn, mod, pos, now); break;
            default:                                         break;
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
          using button = platform::handler::mouse::button;

          support::clock::time_point const now(support::clock::now());
          glm::ivec2 const                 pos(a, b);
          
          for (auto mh: w->mouse_handler.get()) {
            mh->press(button::last, convert::to_key_modifier(::glutGetModifiers()), pos, now);
          }
        }
      }
      
      /* static */ void
      simple::cb_mouse_wheel(signed a, signed b, signed c, signed d)
      {
        TRACE("platform::glut::window::simple::cb_mouse_wheel");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          support::clock::time_point const now(support::clock::now());
          glm::ivec2 const                 pos(c, d);
          
          for (auto mh: w->mouse_handler.get()) {
            mh->scroll(1.0,
                       convert::to_wheel_direction(a, b),
                       convert::to_key_modifier   (::glutGetModifiers()),
                       pos, now);
          }
        }
      }
      
      /* static */ void
      simple::cb_passive_motion(signed a, signed b)
      {
        TRACE("platform::glut::window::simple::cb_passive_motion");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));
        
        if (w) {
          support::clock::time_point const now(support::clock::now());
          glm::ivec2 const                 pos(a, b);
          
          for (auto mh: w->mouse_handler.get()) {
            mh->motion(convert::to_key_modifier(::glutGetModifiers()), pos, now);
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
          support::clock::time_point const now(support::clock::now());
          glm::ivec2 const                 pos(b, c);
          
          for (auto kh: w->keyboard_handler.get()) {
            kh->press(convert::to_key_code    (a),
                      convert::to_key_modifier(::glutGetModifiers()),
                      pos, now);
          }
        }
      }
      
      /* static */ void
      simple::cb_special_up(signed a, signed b, signed c)
      {
        TRACE("platform::glut::window::simple::cb_special_up");

        simple* w(static_cast<simple*>(window::manager::get(::glutGetWindow())));

        if (w) {
          support::clock::time_point const now(support::clock::now());
          glm::ivec2 const                 pos(b, c);
          
          for (auto kh: w->keyboard_handler.get()) {
            kh->release(convert::to_key_code    (a),
                        convert::to_key_modifier(::glutGetModifiers()),
                        pos, now);
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
          ::glutSpecialUpFunc (nullptr);
          ::glutSpecialFunc   (nullptr);
          ::glutKeyboardUpFunc(nullptr);
          ::glutKeyboardFunc  (nullptr);
        }
      }
      
      void
      simple::adjust_mouse_handler_callbacks()
      {
        TRACE("platform::glut::window::simple::adjust_mouse_handler_callbacks");

        if (!mouse_handler->empty()) {
          ::glutMotionFunc       (&simple::cb_mouse_motion);
          ::glutMouseFunc        (&simple::cb_mouse);
          // ::glutMouseWheelFunc   (&simple::cb_mouse_wheel);
          ::glutPassiveMotionFunc(&simple::cb_passive_motion);
        } else {
          
          ::glutPassiveMotionFunc(nullptr);
          // ::glutMouseWheelFunc   (nullptr);
          ::glutMouseFunc        (nullptr);
          ::glutMotionFunc       (nullptr);
        }
      }
      
    } // namespace window {

  } // namespace glut {
  
} // namespace platform {
