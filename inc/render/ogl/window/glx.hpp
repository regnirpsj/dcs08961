// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/ogl/window/glx.hpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_OGL_WINDOW_GLX_HPP)

#define UKACHULLDCS_08961_RENDER_OGL_WINDOW_GLX_HPP

// includes, system

//#include <>

// includes, project

#include <platform/glx/window/base.hpp>
#include <render/window.hpp>

namespace render {

  namespace ogl {
    
    namespace window {
      
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_RENDER_EXPORT glx : public platform::glx::window::base,
                                         public render::window {

      public:

        explicit glx();
        virtual ~glx();

      protected:

        virtual void display();
      
      };
  
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace window {
    
  } // namespace ogl {
    
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_OGL_WINDOW_GLX_HPP)
