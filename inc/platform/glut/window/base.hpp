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

#include <field/adapter/single.hpp>
#include <platform/window/base.hpp>

namespace platform {

  namespace glut {

    namespace window {
  
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_PLATFORM_EXPORT base : public platform::window::base {
        
      public:

        using rect = platform::window::rect;
        
        static rect const dflt_rect; // (100, 100, 800, 600)

        field::adapter::single<signed> const id;
        
        virtual ~base();
        
      protected:
        
        explicit base(std::string const& /* title */, rect const& /* rect */ = dflt_rect);

        virtual void do_changed(field::base&);
        
        virtual void close  ();
        virtual void display() =0;
        virtual void entry  (signed);
        virtual void idle   ();
        virtual void status (signed);
        
      private:

        signed id_;
        
        static void cb_display      ();
        static void cb_entry        (signed);
        static void cb_idle         ();
        static void cb_window_status(signed);

        signed const& cb_get_id() const;
        signed        cb_set_id(signed const&);
        
      };

      class DCS08961_PLATFORM_EXPORT guard : private boost::noncopyable {

      public:

        explicit guard();
                ~guard();

      private:

        signed id_;
                
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

      void flush_gl_errors(std::ostream&);
      
    } // namespace window {

  } // namespace glut {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_GLUT_WINDOW_BASE_HPP)
