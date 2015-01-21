// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/null/stage/draw.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_NULL_STAGE_DRAW_HPP)

#define UKACHULLDCS_08961_RENDER_NULL_STAGE_DRAW_HPP

// includes, system

#include <vector> // std::vector<>

// includes, project

#include <render/base/stage/draw.hpp>
#include <scene/objects.hpp>
#include <render/null/export.h>

namespace render {

  namespace null {
    
    namespace stage {
      
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_RENDER_NULL_EXPORT draw : public base::stage::draw {

      public:

        typedef std::vector<scene::object::light::base::rep> light_list_type;
        typedef std::vector<scene::object::material::rep>    material_list_type;
        
        explicit draw(scene::node::group*  /* scene root */,
                      scene::node::camera* /* camera */);
        virtual ~draw();

      protected:
        
        virtual void do_execute();

      private:

        bool               scene_bbox_changed_;
        light_list_type    light_list_;
        material_list_type material_list_;
        
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace stage {
    
  } // namespace null {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_NULL_STAGE_DRAW_HPP)
