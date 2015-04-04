// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glut/window/base.hpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_GLUT_WINDOW_BASE_HPP)

#define UKACHULLDCS_08961_PLATFORM_GLUT_WINDOW_BASE_HPP

// includes, system

#include <glm/glm.hpp> // glm::ivec2

// includes, project

#include <platform/window/base.hpp>

namespace platform {

  namespace glut {

    namespace window {
  
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_PLATFORM_EXPORT base : platform::window::base {

      public:

        struct state_t {
          signed      id;
          bool        fullscreen;
          glm::ivec2  pos;
          glm::ivec2  size;
          bool        show_stats;
        };

        static void flush_gl_errors(std::ostream&);

        virtual ~base();
        
        virtual void print_on(std::ostream&) const;
        
      protected:

        state_t state_;
        
        explicit base(std::string const&);
        
        virtual void frame_render_one () =0;
        virtual void frame_render_post();
        virtual void frame_render_pre ();
    
        virtual void idle    ();
        virtual void keyboard(unsigned char, glm::ivec2 const&);
        virtual void mouse   (signed, signed, glm::ivec2 const&);
        virtual void reshape (glm::ivec2 const&);
        virtual void special (signed, glm::ivec2 const&);
        
      private:
        
        // calling order:
        //   frame_render_pre()
        //   frame_render_one()
        //   frame_render_post()
        virtual void display();
    
        static void cb_display ();
        static void cb_idle    ();
        static void cb_keyboard(unsigned char, signed, signed);
        static void cb_mouse   (signed, signed, signed, signed);
        static void cb_reshape (signed, signed);
        static void cb_special (signed, signed, signed);
        
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
  
    } // namespace window {

  } // namespace glut {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_GLUT_WINDOW_BASE_HPP)
