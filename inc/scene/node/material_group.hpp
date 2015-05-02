// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
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

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>

// includes, project

#include <scene/node/group.hpp>
#include <scene/object/material.hpp>

namespace scene {

  namespace node {
    
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_SCENE_EXPORT material_group : public group {

    public:

      using subject_inherited = group;
      using source_ptr_type   = boost::intrusive_ptr<object::material>;
      
      field::value::single<source_ptr_type> material; ///< source
      
      explicit material_group();

      virtual void accept(visitor::base&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace node {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_NODE_MATERIAL_GROUP_HPP)
