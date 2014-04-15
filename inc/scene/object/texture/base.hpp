// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/texture/base.hpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_BASE_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_BASE_HPP

// includes, system

#include <glm/glm.hpp> // glm::*

// includes, project

#include <scene/object/base.hpp>

namespace scene {

  namespace object {

    namespace texture {
      
      // types, exported (class, enum, struct, union, typedef)

      class base : public object::base {

      public:

        static glm::uvec3 const default_size;  // (1,1,1)
        static glm::uvec4 const default_color; // (1,1,1,1)
      
        virtual ~base() =0;

        virtual bool empty() const =0;
      
      protected:
      
        explicit base();
      
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace texture {
    
  } // namespace object {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_BASE_HPP)
