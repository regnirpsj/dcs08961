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

#include <deque> // std::deque<>

// includes, project

#include <platform/glut/window/base.hpp>

namespace platform {
  
  namespace handler {

    namespace frame {

      class base;
      
    } // namespace frame {
    
    namespace keyboard {

      class base;
      
    } // namespace keyboard {

    namespace mouse {

      class base;
      
    } // namespace mouse {
    
  } // namespace handler {

  namespace glut {

    namespace window {
  
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_PLATFORM_EXPORT simple : public base {

      public:

        field::value::single<unsigned> max_queue_length;
        
      protected:        

        handler::frame::base*    hndlr_frame_;
        handler::keyboard::base* hndlr_kbd_;
        handler::mouse::base*    hndlr_mouse_;        
    
        explicit simple(std::string const&       /* title       */,
                        rect const&              /* rect        */ = rect::dflt_rect,
                        handler::frame::base*    /* frame hndlr */ = nullptr,
                        handler::keyboard::base* /* kbd handlr  */ = nullptr,
                        handler::mouse::base*    /* mouse hndlr */ = nullptr);

        virtual void frame_render_one () =0;
        virtual void frame_render_post();
        virtual void frame_render_pre ();
        
        virtual void reshape (glm::ivec2 const& /* (w,h) */);
        
      private:

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
        
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
  
    } // namespace window {

  } // namespace glut {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_GLUT_WINDOW_SIMPLE_HPP)
