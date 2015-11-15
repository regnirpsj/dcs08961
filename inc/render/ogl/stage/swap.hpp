// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/ogl/stage/swap.hpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_OGL_STAGE_SWAP_HPP)

#define UKACHULLDCS_08961_RENDER_OGL_STAGE_SWAP_HPP

// includes, system

//#include <>

// includes, project

#include <render/stage/swap.hpp>

namespace render {

  namespace ogl {

    class context;
    
    namespace stage {
      
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_RENDER_EXPORT swap : public render::stage::swap {

      public:

        explicit swap(ogl::context&);
        virtual ~swap();
        
      protected:
        
        virtual void do_execute(render::context::swap&);
        
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace stage {

  } // namespace ogl {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_OGL_STAGE_SWAP_HPP)
