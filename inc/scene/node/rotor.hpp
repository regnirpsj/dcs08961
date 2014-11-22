// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/rotor.hpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_NODE_ROTOR_HPP)

#define UKACHULLDCS_08961_SCENE_NODE_ROTOR_HPP

// includes, system

#include <glm/glm.hpp> // glm::vec3

// includes, project

#include <scene/node/dynamic.hpp>

namespace scene {

  namespace node {
    
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_SCENE_EXPORT rotor : public dynamic {

    public:

      typedef dynamic subject_inherited;

      field::value::single<glm::vec3> axis; ///< rotation axis          [(0,1,0)]
      field::value::single<float>     rpm;  ///< revolutions per minute [1.0]
      
      explicit rotor(float            /* rpm */  = 1.0,
                     glm::vec3 const& /* axis */ = glm::vec3(0,1,0));

      virtual void accept(visitor::base&);

    protected:
      
      virtual void do_changed(field::base&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace node {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_NODE_ROTOR_HPP)
