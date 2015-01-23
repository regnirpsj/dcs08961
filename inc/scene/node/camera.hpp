// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/camera.hpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_NODE_CAMERA_HPP)

#define UKACHULLDCS_08961_SCENE_NODE_CAMERA_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>
#include <glm/glm.hpp>             // glm::mat4

// includes, project

#include <field/adapter/single.hpp>
#include <field/value/single.hpp>
#include <scene/object/camera/base.hpp>
#include <scene/node/base.hpp>

namespace scene {

  namespace node {
    
    // types, exported (class, enum, struct, union, typedef)
    
    class DCS08961_SCENE_EXPORT camera : public base {
      
    public:
      
      typedef base                                       subject_inherited;
      typedef boost::intrusive_ptr<object::camera::base> camera_ptr_type;
      
      field::value::single<camera_ptr_type>   object; ///< camera object
      field::adapter::single<glm::mat4> const view;   ///< inverse(absolute_xform)

      explicit camera(object::camera::base* /* camera */);

      virtual void accept(visitor::base&);
      
    private:

      mutable glm::mat4 inverse_view_;
      
      glm::mat4 const& cb_get_view() const;
      glm::mat4        cb_set_view(glm::mat4 const&);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace node {
  
} // namespace scene {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_NODE_CAMERA_HPP)
