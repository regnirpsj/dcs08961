// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/camera/perspective.hpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_CAMERA_PERSPECTIVE_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_CAMERA_PERSPECTIVE_HPP

// includes, system

//#include <>

// includes, project

#include <scene/object/camera/base.hpp>

namespace scene {

  namespace object {

    namespace camera {
      
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_SCENE_EXPORT perspective : public base {

      public:

        using subject_inherited = base;

        static float const default_fovy; ///< default vertical vield-of-view (60 degrees)
        
        explicit perspective(float                /* fovy */     = default_fovy,
                             viewport_type const& /* viewport */ = viewport_type(),
                             glm::vec2 const&     /* near/far */ = glm::vec2(frustum_type().near,
                                                                             frustum_type().far));
        virtual ~perspective();

        field::value::single<float> fovy; ///< vertical field-of-view
        
      protected:

        virtual void do_changed(field::base&);
        
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace camera {

  } // namespace object {
      
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_CAMERA_PERSPECTIVE_HPP)
