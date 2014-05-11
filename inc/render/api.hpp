// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/api.hpp                                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_API_HPP)

#define UKACHULLDCS_08961_RENDER_API_HPP

// includes, system

#include <iosfwd> // std::basic_ostream<> (fwd)

// includes, project

//#include <>

namespace render {

  namespace api {
    
    // types, exported (class, enum, struct, union, typedef)

    enum class type {

      d3d, direct3d = d3d, directx = d3d,

      null,

      ogl, opengl = ogl,
      
    };

    template <api::type>
    class traits { };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

    template <typename CTy, typename CTr>
    std::basic_ostream<CTy,CTr>& operator<<(std::basic_ostream<CTy,CTr>&, type const&);
    
  } // namespace api {
  
} // namespace render {

#include <render/api.inl>

#endif // #if !defined(UKACHULLDCS_08961_RENDER_API_HPP)
