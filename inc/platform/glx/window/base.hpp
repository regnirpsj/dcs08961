// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glx/window/base.hpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_GLX_WINDOW_BASE_HPP)

#define UKACHULLDCS_08961_PLATFORM_GLX_WINDOW_BASE_HPP

// includes, system

#include <GL/glxew.h> // Colormap, Display, GLXContext, Window, XVisualInfo
#include <string> // std::string
#include <vector> // std::vector<>

// includes, project

#include <platform/window/base.hpp>

namespace platform {

  namespace glx {

    namespace window {
  
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_PLATFORM_EXPORT base : public platform::window::base {

      public:

        using rect           = platform::window::rect;
        using attribute_list = std::vector<signed>;

        static attribute_list const dflt_attributes;   // { GLX_RGBA, GLX_DOUBLEBUFFER, None }
        static std::string const    dflt_display_name; // ":0.0"
        
        virtual ~base();
        
      protected:

        Display*     x11_display_;
        Window       x11_window_;
        XVisualInfo* x11_visual_;
        Colormap     x11_colormap_;
        GLXContext   glx_context_;
        
        explicit base(std::string const&    /* title   */,
                      rect const&           /* rect    */ = rect::dflt_rect,
                      std::string const&    /* display */ = dflt_display_name,
                      attribute_list const& /* attrs   */ = dflt_attributes);
        
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace window {
    
  } // namespace glx {
    
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_GLX_WINDOW_BASE_HPP)
