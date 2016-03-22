// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/voxelswindow.hpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_APP_OGLPLUS_VOXELS_WINDOW_HPP)

#define UKACHULLDCS_08961_APP_OGLPLUS_VOXELS_WINDOW_HPP

// includes, system

//#include <>

// includes, project

#include <platform/application/command_line.hpp>
#include <platform/glut/window/simple.hpp>
#include <platform/handler/navigation.hpp>
#include <scene/object/light/base.hpp>
#include <scene/object/material.hpp>

#include <model.hpp>
#include <ssbo.hpp>

namespace voxels {
  
  // types, exported (class, enum, struct, union, typedef)

  class window : public platform::glut::window::simple {
    
    using command_line     = platform::application::command_line;
    using inherited        = platform::glut::window::simple;
    using rect             = platform::window::rect;
    using string_list_type = std::vector<std::string>;
    
  public:

    explicit window(command_line const&, rect const&);
    virtual ~window();
    
  private:

    virtual void frame_render_one();
    virtual void frame_render_pre();
    
    virtual void reshape(glm::ivec2 const&);
    
  private:

    struct camera_info_t {
      glm::mat4 xform;
    };
    
    struct projection_info_t {
      glm::mat4 xform;
      float     fovy_degree;
      glm::vec2 near_far;
    };
    
    using light_list_type    = buffer::multi_value<scene::object::light::base::rep>;
    using material_list_type = buffer::multi_value<scene::object::material::rep>;
    
    oglplus::Context     ctx_;
    oglplus::Program     prg_;
    model::voxel_space   vspace_;
    light_list_type      light_list_;
    material_list_type   material_list_;
    stats::cpu           cpu_stats_;
    stats::gpu           gpu_stats_;
    camera_info_t        camera_;
    projection_info_t    projection_;
    std::string const    title_base_;
    std::unique_ptr<platform::handler::navigation::base> navigation_hndlr_;
    
  };
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace voxels {

#endif // #if !defined(UKACHULLDCS_08961_APP_OGLPLUS_VOXELS_WINDOW_HPP)
