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

  namespace glut {

    namespace window {
  
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_PLATFORM_EXPORT simple : public base {

      public:

        field::value::single<unsigned> max_queue_length;
        
      protected:
        
        using time_point = support::clock::time_point;
        
        struct keyboard_info_t {
          signed     key;
          signed     modifier;
          bool       key_up;
          time_point stamp;
        };
        
        struct mouse_info_t {
          signed     button;
          signed     state;
          signed     modifier;
          glm::ivec2 pos;
          time_point stamp;
        };

        using keyboard_info_queue = std::deque<keyboard_info_t>;
        using mouse_info_queue    = std::deque<mouse_info_t>;
        
        keyboard_info_queue keyboardq_;
        mouse_info_queue    mouseq_;
    
        explicit simple(std::string const& /* title */, rect const& /* rect */ = base::dflt_rect);

        virtual void frame_render_one () =0;
        virtual void frame_render_post();
        virtual void frame_render_pre ();
        
        virtual bool keyboard(unsigned char     /* key           */,
                              glm::ivec2 const& /* ptr pos       */,
                              bool              /* up/down       */);

        virtual bool motion  (glm::ivec2 const& /* ptr pos       */,
                              bool              /* mouse/passive */);
        
        virtual bool mouse   (signed            /* button        */,
                              signed            /* state         */,
                              glm::ivec2 const& /* ptr pos       */,
                              bool              /* wheel         */);
        
        virtual void reshape (glm::ivec2 const& /* (w,h)         */);
        
        virtual bool special (signed            /* key           */,
                              glm::ivec2 const& /* ptr pos       */,
                              bool              /* up/down       */);
        
      private:

        // calling order:
        //   frame_render_pre()
        //   frame_render_one()
        //   frame_render_post()
        virtual void display();
        
        static void cb_keyboard      (unsigned char, signed, signed);  // -> keyboard
        static void cb_keyboard_up   (unsigned char, signed, signed);  // -> keyboard
        static void cb_mouse         (signed, signed, signed, signed); // -> mouse
        static void cb_mouse_motion  (signed, signed);                 // -> motion
        static void cb_mouse_wheel   (signed, signed, signed, signed); // -> mouse
        static void cb_passive_motion(signed, signed);                 // -> motion
        static void cb_reshape       (signed, signed);                 // -> reshape
        static void cb_special       (signed, signed, signed);         // -> special
        static void cb_special_up    (signed, signed, signed);         // -> special
        
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
  
    } // namespace window {

  } // namespace glut {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_GLUT_WINDOW_SIMPLE_HPP)
