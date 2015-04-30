// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glut/window/simple.hpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_GLUT_WINDOW_SIMPLE_HPP)

#define UKACHULLDCS_08961_PLATFORM_GLUT_WINDOW_SIMPLE_HPP

// includes, system

#include <deque>  // std::deque<>
#include <memory> // std::unique_ptr<>

// includes, project

#include <platform/glut/window/base.hpp>
#include <platform/handler/keyboard.hpp>
#include <platform/handler/mouse.hpp>

namespace platform {  

  namespace glut {

    namespace window {
  
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_PLATFORM_EXPORT simple : public base {

      public:

        field::value::multi<platform::handler::keyboard::base*> keyboard_handler;
        field::value::multi<platform::handler::mouse::base*>    mouse_handler;
        
      protected:
    
        explicit simple(std::string const& /* title */,
                        rect const&        /* rect  */               = rect::dflt_rect,
                        bool               /* enable dflt_handler */ = true);

        virtual void do_changed(field::base&);
        
        virtual void frame_render_one () =0;
        virtual void frame_render_post();
        virtual void frame_render_pre ();
        
        virtual void reshape (glm::ivec2 const& /* (w,h) */);
        
      private:

        class dflt_handler : public platform::handler::keyboard::base,
                             public platform::handler::mouse::base {

        public:

          using kbd_base   = platform::handler::keyboard::base;
          using mouse_base = platform::handler::mouse::base;
          
          explicit dflt_handler(simple&);

          using time_point = support::clock::time_point;
          using key        = platform::handler::keyboard::key;
          
          virtual bool press  (key::ascii        /* ascii    */,
                               uint8_t           /* modifier */ = key::modifier::None,
                               glm::ivec2 const& /* ptr pos  */ = glm::ivec2(),
                               time_point const& /* stamp    */ = support::clock::now());
          
          virtual bool press  (key::code         /* code     */,
                               uint8_t           /* modifier */ = key::modifier::None,
                               glm::ivec2 const& /* ptr pos  */ = glm::ivec2(),
                               time_point const& /* stamp    */ = support::clock::now());
          
          virtual bool release(key::ascii        /* ascii    */,
                               uint8_t           /* modifier */ = key::modifier::None,
                               glm::ivec2 const& /* ptr pos  */ = glm::ivec2(),
                               time_point const& /* stamp    */ = support::clock::now());
          
          virtual bool release(key::code         /* code    */,
                               uint8_t           /* modifier */ = key::modifier::None,
                               glm::ivec2 const& /* ptr pos  */ = glm::ivec2(),
                               time_point const& /* stamp    */ = support::clock::now());

          using button    = platform::handler::mouse::button;
          using direction = platform::handler::mouse::direction;
          
          virtual bool motion (uint8_t           /* modifier */ = key::modifier::None,
                               glm::ivec2 const& /* ptr pos  */ = glm::ivec2(),
                               time_point const& /* stamp    */ = support::clock::now());
        
          virtual bool press  (button            /* button   */,
                               uint8_t           /* modifier */ = key::modifier::None,
                               glm::ivec2 const& /* ptr pos  */ = glm::ivec2(),
                               time_point const& /* stamp    */ = support::clock::now());        
        
          virtual bool release(button            /* button   */,
                               uint8_t           /* modifier */ = key::modifier::None,
                               glm::ivec2 const& /* ptr pos  */ = glm::ivec2(),
                               time_point const& /* stamp    */ = support::clock::now());

          virtual bool scroll (float             /* value    */,
                               direction         /* dir      */,
                               uint8_t           /* modifier */ = key::modifier::None,
                               glm::ivec2 const& /* ptr pos  */ = glm::ivec2(),
                               time_point const& /* stamp    */ = support::clock::now());

          virtual void print_on(std::ostream&) const;
          
        private:

          simple& window_;
          
        };
        
        std::unique_ptr<platform::handler::base> dflt_handler_;
        
        // calling order:
        //   frame_render_pre()
        //   frame_render_one()
        //   frame_render_post()
        virtual void display();
        
        static void cb_keyboard      (unsigned char, signed, signed);  // -> kbd hndlr
        static void cb_keyboard_up   (unsigned char, signed, signed);  // -> kbd hndlr
        static void cb_mouse         (signed, signed, signed, signed); // -> mouse hndlr
        static void cb_mouse_motion  (signed, signed);                 // -> mouse hndlr
        static void cb_mouse_wheel   (signed, signed, signed, signed); // -> mouse hndlr
        static void cb_passive_motion(signed, signed);                 // -> mouse hndlr
        static void cb_reshape       (signed, signed);                 // -> reshape
        static void cb_special       (signed, signed, signed);         // -> kbd hndlr
        static void cb_special_up    (signed, signed, signed);         // -> kbd hndlr

        void adjust_keyboard_handler_callbacks();
        void adjust_mouse_handler_callbacks   ();
        
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
  
    } // namespace window {

  } // namespace glut {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_GLUT_WINDOW_SIMPLE_HPP)
