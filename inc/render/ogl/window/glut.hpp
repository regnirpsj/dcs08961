// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/ogl/window/glut.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_WINDOW_GLUT_HPP)

#define UKACHULLDCS_08961_RENDER_WINDOW_GLUT_HPP

// includes, system

//#include <>

// includes, project

#include <platform/glut/window/base.hpp>
#include <render/window.hpp>

namespace render {

  namespace ogl {
    
    namespace window {
      
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_RENDER_EXPORT glut : public platform::glut::window::base,
                                          public render::window {

      public:

        explicit glut();
        virtual ~glut();

      protected:

        virtual void display();
      
      };
  
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace window {
    
  } // namespace ogl {
    
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_WINDOW_GLUT_HPP)
