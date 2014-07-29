// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
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

#include <render/base/context.hpp>

namespace render {

  namespace ogl {
    
    // types, exported (class, enum, struct, union, typedef)

    class context : public base::context {

    public:

      class implementation;
      
      explicit context(std::string const& /* display */ = "",
                       signed             /* visual */  = -1);
      virtual ~context();

      virtual void print_on(std::ostream&) const;

    private:

      static implementation* impl;
      
      std::string const display_;
      signed            visual_;
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace ogl {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_OGL_CONTEXT_HPP)
