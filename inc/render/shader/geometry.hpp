// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/shader/geometry.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_SHADER_GEOMETRY_HPP)

#define UKACHULLDCS_08961_RENDER_SHADER_GEOMETRY_HPP

// includes, system

//#include <>

// includes, project

#include <render/shader/base.hpp>

namespace render {
  
  namespace shader {
      
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT geometry : public base {

    public:      
      
      virtual ~geometry();
      
    protected:

      explicit geometry(context::device&);

    };
      
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace shader {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_SHADER_GEOMETRY_HPP)
