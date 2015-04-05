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

// #include <>

// includes, project

#include <platform/window/base.hpp>

namespace platform {

  namespace glut {

    namespace window {
  
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_PLATFORM_EXPORT base : public platform::window::base {

      public:

        using rect = platform::window::rect;
        
        static rect const dflt_rect; // (100, 100, 800, 600)

        virtual ~base();
        
        virtual void print_on(std::ostream&) const;
        
      protected:

        signed id_;
        
        explicit base(std::string const& /* title */, rect const& /* rect */ = dflt_rect);

        virtual void close  ();
        virtual void display() =0;
        virtual void entry  (signed);
        virtual void idle   ();
        virtual void status (signed);
        
      private:
        
        static void cb_display      ();
        static void cb_entry        (signed);
        static void cb_idle         ();
        static void cb_window_status(signed);
        
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

      void flush_gl_errors(std::ostream&);
      
    } // namespace window {

  } // namespace glut {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_GLUT_WINDOW_BASE_HPP)
