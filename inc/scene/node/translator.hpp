// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/translator.hpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_NODE_TRANSLATOR_HPP)

#define UKACHULLDCS_08961_SCENE_NODE_TRANSLATOR_HPP

// includes, system

#include <glm/glm.hpp> // glm::vec3

// includes, project

#include <scene/node/dynamic.hpp>

namespace scene {

  namespace node {
    
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_SCENE_EXPORT translator : public dynamic {

    public:

      typedef dynamic subject_inherited;
      
      field::value::single<glm::vec3> direction; ///< direction [(1,0,0)]
      field::value::single<float>     speed;     ///< speed     [1.0]
      
      explicit translator(glm::vec3 const&   /* velocity */  = glm::vec3(1,0,0));
      explicit translator(float              /* speed */,
                          glm::vec3 const&   /* direction */ = glm::vec3(1,0,0));
      virtual void accept(visitor::base&);

    protected:

      virtual void do_changed(field::base&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace node {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_NODE_TRANSLATOR_HPP)
