// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/primitive/icosahedron.hpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_PRIMITIVE_ICOSAHEDRON_HPP)

#define UKACHULLDCS_08961_SCENE_PRIMITIVE_ICOSAHEDRON_HPP

// includes, system

//#include <>

// includes, project

#include <scene/node/geometry.hpp>

namespace scene {

  namespace primitive {
    
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_SCENE_EXPORT icosahedron : public node::geometry {

    public:

      using subject_inherited = node::geometry;

      explicit icosahedron();
      
      virtual void accept(visitor::base&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace primitive {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_PRIMITIVE_ICOSAHEDRON_HPP)
