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

#include <field/adapter/single.hpp>
#include <field/value/single.hpp>
#include <scene/object/base.hpp>
#include <scene/object/camera/frustum.hpp>
#include <scene/object/camera/viewport.hpp>

namespace scene {

  namespace object {

    namespace camera {
      
      // types, exported (class, enum, struct, union, typedef)

      class base : public object::base {

      public:

        typedef object::base     subject_inherited;
        typedef glm::mat4        matrix_type;
        typedef camera::frustum  frustum_type;
        typedef camera::viewport viewport_type;

        virtual ~base() =0;

        field::adapter::single<matrix_type> const  projection; ///< projection xform
        field::adapter::single<frustum_type> const frustum;    ///< frustum
        field::value::single<viewport_type>        viewport;   ///< viewport

      protected:
        
        matrix_type  projection_;
        frustum_type frustum_;

        explicit base(matrix_type const&   /* projection */,
                      viewport_type const& /* viewport */,
                      glm::vec2 const&     /* near/far */);

        virtual void do_changed(field::base&);

        frustum_type compute_frustum(viewport_type const& /* viewport */,
                                     glm::vec2 const& /* near/far */);
          
      private:
        
        matrix_type const&  cb_get_projection() const;
        matrix_type         cb_set_projection(matrix_type const&);
        frustum_type const& cb_get_frustum   () const;
        frustum_type        cb_set_frustum   (frustum_type const&);
        
      };
      
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace camera {

  } // namespace object {
      
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_CAMERA_BASE_HPP)
