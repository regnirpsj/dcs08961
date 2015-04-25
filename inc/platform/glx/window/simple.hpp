// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glx/window/simple.hpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_GLX_WINDOW_SIMPLE_HPP)

#define UKACHULLDCS_08961_PLATFORM_GLX_WINDOW_SIMPLE_HPP

// includes, system

//#include <>

// includes, project

#include <platform/glx/window/base.hpp>

namespace platform {

  namespace glx {

    namespace window {

      class DCS08961_PLATFORM_EXPORT simple : public base {

      protected:
        
        using attribute_list = base::attribute_list;
        
        explicit simple(std::string const&    /* title   */,
                        rect const&           /* rect    */ = rect::dflt_rect,
                        std::string const&    /* display */ = dflt_display_name,
                        attribute_list const& /* attrs   */ = dflt_attributes);

        virtual void frame_render_one () =0;
        virtual void frame_render_post();
        virtual void frame_render_pre ();

      private:

        // calling order:
        //   frame_render_pre()
        //   frame_render_one()
        //   frame_render_post()
        virtual void display();
        
      };
      
      // types, exported (class, enum, struct, union, typedef)

      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
  
    } // namespace window {
    
  } // namespace glx {
    
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_GLX_WINDOW_SIMPLE_HPP)
