// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
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

#include <glm/gtx/utilities.hpp>
#include <scene/object/camera/base.hpp>

namespace scene {

  namespace object {

    namespace camera {
      
      // types, exported (class, enum, struct, union, typedef)

      class perspective : public base {

      public:

        typedef base subject_inherited;

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1700))
        explicit perspective(float                /* fovy */     = 60_deg,
                             viewport_type const& /* viewport */ = viewport_type(),
                             glm::vec2 const&     /* near/far */ = glm::vec2(frustum_type().near,
                                                                             frustum_type().far));
#else
        explicit perspective(float                /* fovy */     = 60 _deg,
                             viewport_type const& /* viewport */ = viewport_type(),
                             glm::vec2 const&     /* near/far */ = glm::vec2(frustum_type().near,
                                                                             frustum_type().far));
#endif
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