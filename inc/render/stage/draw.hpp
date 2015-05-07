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

namespace scene {

  namespace node {

    class camera;
    class group;
    
  } // namespace node {
  
} // namespace scene {

namespace render {

  namespace stage {
      
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT draw : public base {

    public:

      using camera_field_type = field::value::single<boost::intrusive_ptr<scene::node::camera>>;
      using scene_field_type  = field::value::single<boost::intrusive_ptr<scene::node::group>>;

      camera_field_type camera;
      scene_field_type  scene;
      
      virtual ~draw();
        
    protected:
      
      explicit draw(context&);

      virtual void do_resize(glm::ivec2 const&);
        
    };
      
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace stage {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_STAGE_DRAW_HPP)
