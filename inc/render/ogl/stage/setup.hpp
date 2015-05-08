// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/ogl/stage/setup.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_OGL_STAGE_SETUP_HPP)

#define UKACHULLDCS_08961_RENDER_OGL_STAGE_SETUP_HPP

// includes, system

//#include <>

// includes, project

#include <render/stage/setup.hpp>

namespace render {

  namespace ogl {
    
    class context;
  
    namespace stage {
      
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_RENDER_EXPORT setup : public render::stage::setup {

      public:

        explicit setup(ogl::context&);
        virtual ~setup();

      protected:

        virtual void do_execute();
        virtual void do_resize (glm::ivec2 const&);
        
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace stage {

  } // namespace ogl {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_OGL_STAGE_SETUP_HPP)
