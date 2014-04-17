// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/camera/base.hpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_CAMERA_BASE_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_CAMERA_BASE_HPP

// includes, system

#include <glm/glm.hpp> // glm::mat4, glm::vec2

// includes, project

#include <field/value/single.hpp>
#include <scene/object/base.hpp>
#include <scene/object/camera/viewport.hpp>

namespace scene {

  namespace object {

    namespace camera {
      
      // types, exported (class, enum, struct, union, typedef)

      class base : public object::base {

      public:

        typedef object::base     subject_inherited;
        typedef glm::mat4        matrix_type;
        typedef camera::viewport viewport_type;

        virtual ~base() =0;

        field::value::single<matrix_type>   projection; ///< projection xform
        field::value::single<viewport_type> viewport;   ///< viewport

      protected:
        
        glm::vec2 near_far_;

        explicit base(matrix_type const&   /* projection */,
                      viewport_type const& /* viewport */,
                      glm::vec2 const&     /* near/far */);

        virtual void do_changed(field::base&);
        
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace camera {

  } // namespace object {
      
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_CAMERA_BASE_HPP)
