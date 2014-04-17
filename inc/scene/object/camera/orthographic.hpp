// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/camera/orthographic.hpp                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_CAMERA_ORTHOGRAPHIC_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_CAMERA_ORTHOGRAPHIC_HPP

// includes, system

//#include <>

// includes, project

#include <scene/object/camera/base.hpp>

namespace scene {

  namespace object {

    namespace camera {
      
      // types, exported (class, enum, struct, union, typedef)

      class orthographic : public base {

      public:

        typedef base subject_inherited;

        explicit orthographic(viewport_type const& /* viewport */ = viewport_type(),
                              glm::vec2 const&     /* near/far */ = glm::vec2(frustum_type().near,
                                                                              frustum_type().far));
        virtual ~orthographic();

      protected:

        virtual void do_changed(field::base&);
        
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace camera {

  } // namespace object {
      
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_CAMERA_ORTHOGRAPHIC_HPP)
