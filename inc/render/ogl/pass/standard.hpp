// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/ogl/pass/standard.hpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_OGL_PASS_STANDARD_HPP)

#define UKACHULLDCS_08961_RENDER_OGL_PASS_STANDARD_HPP

// includes, system

//#include <>

// includes, project

#include <render/pass/base.hpp>

namespace render {

  namespace ogl {

    class context;
    
    namespace pass {
      
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_RENDER_EXPORT standard : public render::pass::base {

      public:

        explicit standard(ogl::context&);
        virtual ~standard();
        
      private:

        virtual void do_execute();
        virtual void do_resize (glm::ivec2 const&);
      
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    }  // namespace pass {

  } // namespace ogl {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_OGL_PASS_STANDARD_HPP)
