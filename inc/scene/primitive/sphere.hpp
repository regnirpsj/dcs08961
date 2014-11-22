// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/primitive/sphere.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_PRIMITIVE_SPHERE_HPP)

#define UKACHULLDCS_08961_SCENE_PRIMITIVE_SPHERE_HPP

// includes, system

//#include <>

// includes, project

#include <scene/node/geometry.hpp>

namespace scene {

  namespace primitive {
    
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_SCENE_EXPORT sphere : public node::geometry {

    public:

      typedef node::geometry subject_inherited;

      explicit sphere();

      field::value::single<unsigned> subdivision; ///< sub-disviion levels
      
      virtual void accept(visitor::base&);

    protected:

      virtual void do_changed(field::base&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace primitive {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_PRIMITIVE_SPHERE_HPP)
