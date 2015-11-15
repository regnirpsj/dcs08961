// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/ogl/stage/clear.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_OGL_STAGE_CLEAR_HPP)

#define UKACHULLDCS_08961_RENDER_OGL_STAGE_CLEAR_HPP

// includes, system

//#include <>

// includes, project

#include <render/stage/clear.hpp>

namespace render {

  namespace ogl {

    class context;
    
    namespace stage {
      
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_RENDER_EXPORT clear : public render::stage::clear {

      public:

        explicit clear(ogl::context&);
        virtual ~clear();
        
      protected:
        
        virtual void do_execute(render::context::swap&);
        
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace stage {

  } // namespace ogl {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_OGL_STAGE_CLEAR_HPP)
