// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/primitive/cylinder.hpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_PRIMITIVE_CYLINDER_HPP)

#define UKACHULLDCS_08961_SCENE_PRIMITIVE_CYLINDER_HPP

// includes, system

//#include <>

// includes, project

#include <scene/node/geometry.hpp>

namespace scene {

  namespace primitive {
    
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_SCENE_EXPORT cylinder : public node::geometry {

    public:

      typedef node::geometry subject_inherited;

      explicit cylinder(unsigned = 36);

      field::value::single<unsigned> sides; ///< sides
      
      virtual void accept(visitor::base&);

    protected:

      virtual void do_changed(field::base&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace primitive {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_PRIMITIVE_CYLINDER_HPP)
