// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/material_group.hpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_NODE_MATERIAL_GROUP_HPP)

#define UKACHULLDCS_08961_SCENE_NODE_MATERIAL_GROUP_HPP

// includes, system

// #include <>

// includes, project

#include <scene/node/group.hpp>
#include <scene/object/material.hpp>

namespace scene {

  namespace node {
    
    // types, exported (class, enum, struct, union, typedef)

    class material_group : public group {

    public:

      typedef group subject_inherited;

      field::value::single<boost::intrusive_ptr<object::material>> material;
      
      explicit material_group();

      virtual void accept(visitor::base&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace node {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_NODE_MATERIAL_GROUP_HPP)
