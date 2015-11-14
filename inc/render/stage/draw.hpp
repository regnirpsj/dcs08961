// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/stage/draw.hpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_STAGE_DRAW_HPP)

#define UKACHULLDCS_08961_RENDER_STAGE_DRAW_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>

// includes, project

#include <render/stage/base.hpp>
#include <scene/node/camera.hpp>
#include <scene/node/group.hpp>

namespace render {

  namespace stage {
      
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT draw : public base {

    public:

      using camera_field_type =
        field::value::single<boost::intrusive_ptr<scene::node::camera const>>;
      using scene_field_type  =
        field::value::single<boost::intrusive_ptr<scene::node::group const>>;

      camera_field_type camera; //< camera (view, projection, viewport)
      scene_field_type  scene;  //< scene (geo, lights, etc)
      
      virtual ~draw();
        
    protected:
      
      explicit draw(device::context&);

      virtual void do_resize(glm::ivec2 const&);
        
    };
      
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace stage {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_STAGE_DRAW_HPP)
