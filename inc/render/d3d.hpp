// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/d3d.hpp                                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_D3D_HPP)

#define UKACHULLDCS_08961_RENDER_D3D_HPP

// includes, system

//#include <>

// includes, project

#include <render/api.hpp>
#include <render/d3d/context.hpp>
#include <render/d3d/pass.hpp>
#include <render/d3d/stage.hpp>

namespace render {

  namespace api {
    
    // types, exported (class, enum, struct, union, typedef)

    template <> class traits<type::d3d> {

    public:

      typedef d3d::context context;
      typedef d3d::pass    pass;
      typedef d3d::stage   stage;
      
    };
  
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace api {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_D3D_HPP)
