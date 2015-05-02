// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/mesh.hpp                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_NODE_MESH_HPP)

#define UKACHULLDCS_08961_SCENE_NODE_MESH_HPP

// includes, system

// #include <>

// includes, project

#include <scene/node/geometry.hpp>

namespace scene {

  namespace node {
    
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_SCENE_EXPORT mesh : public geometry {

    public:

      using subject_inherited = geometry;
      
      using attribute_list_type = geometry::attribute_list_type;
      using index_list_type     = geometry::index_list_type;
      
      explicit mesh(attribute_list_type const&, index_list_type const&);
      
      virtual void accept(visitor::base&);

      void compute_normals();
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace node {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_NODE_MESH_HPP)
