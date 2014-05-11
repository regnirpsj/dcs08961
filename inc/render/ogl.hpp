// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/ogl.hpp                                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_OGL_HPP)

#define UKACHULLDCS_08961_RENDER_OGL_HPP

// includes, system

//#include <>

// includes, project

#include <render/api.hpp>
#include <render/ogl/context.hpp>
#include <render/ogl/pass.hpp>
#include <render/ogl/stage.hpp>

namespace render {

  namespace api {
    
    // types, exported (class, enum, struct, union, typedef)

    template <> class traits<type::ogl> {

    public:

      typedef ogl::context context;
      typedef ogl::pass    pass;
      typedef ogl::stage   stage;
      
    };
  
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace api {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_OGL_HPP)
