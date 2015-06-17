// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/viewerwindow.hpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_APP_OGLPLUS_VIEWER_WINDOW_HPP)

#define UKACHULLDCS_08961_APP_OGLPLUS_VIEWER_WINDOW_HPP

// includes, system

//#include <>

// includes, project

#include <platform/application/command_line.hpp>
#include <platform/glut/window/simple.hpp>
#include <platform/handler/navigation.hpp>
#include <scene/object/light/base.hpp>

#include <model.hpp>
#include <ssbo.hpp>

namespace viewer {
  
  // types, exported (class, enum, struct, union, typedef)

  class window : public platform::glut::window::simple {
    
    using command_line     = platform::application::command_line;
    using inherited        = platform::glut::window::simple;
    using rect             = platform::window::rect;
    using string_list_type = std::vector<std::string>;
    
  public:

    explicit window(command_line const&, rect const&, std::string const&, string_list_type const&);
    virtual ~window();
    
  private:

    virtual void frame_render_one();
    virtual void frame_render_pre();
    
    virtual void reshape(glm::ivec2 const&);
    
  private:

    using model_mesh_list_type = std::vector<std::unique_ptr<model::mesh>>;

    struct camera_info_t {
      glm::mat4 xform;
    };
    
    struct projection_info_t {
      glm::mat4 xform;
      float     fovy_degree;
      glm::vec2 near_far;
    };
    
    using light_list_type = buffer::multi_value<scene::object::light::base::rep>;
    
    oglplus::Context     ctx_;
    oglplus::Program     prg_;
    oglplus::Texture     tex_diffuse_;
    oglplus::Texture     tex_envmap_;
    model_mesh_list_type model_list_;
    light_list_type      light_list_;
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
  
} // namespace viewer {

#endif // #if !defined(UKACHULLDCS_08961_APP_OGLPLUS_VIEWER_WINDOW_HPP)
