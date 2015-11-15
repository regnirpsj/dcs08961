// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/ogl/context.hpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_OGL_CONTEXT_HPP)

#define UKACHULLDCS_08961_RENDER_OGL_CONTEXT_HPP

// includes, system

//#include <>

// includes, project

#include <render/context.hpp>

namespace render {

  namespace ogl {
    
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT context : public render::context::device,
                                           public render::context::swap {

    public:

      explicit context();
      virtual ~context();
      
      virtual void print_on(std::ostream&) const;
    
    };
  
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace ogl {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_OGL_CONTEXT_HPP)
