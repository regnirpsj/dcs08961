// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/transform.hpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_NODE_TRANSFORM_HPP)

#define UKACHULLDCS_08961_SCENE_NODE_TRANSFORM_HPP

// includes, system

#include <glm/glm.hpp> // glm::mat4

// includes, project

#include <scene/node/group.hpp>

namespace scene {

  namespace node {
    
    // types, exported (class, enum, struct, union, typedef)

    class transform : public group {

    public:

      typedef group subject_inherited;

      field::value::single<glm::mat4> xform;

      explicit transform(glm::mat4 const& /* xform */ = glm::mat4());
      
      virtual void accept(visitor::base&);

      virtual glm::mat4 absolute_xform() const;
      
    protected:

      virtual void do_changed(field::base&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace node {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_NODE_TRANSFORM_HPP)
