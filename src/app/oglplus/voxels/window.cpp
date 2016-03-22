// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/voxels/window.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "window.hpp"

// includes, system

#include <boost/filesystem.hpp> // boost::filesystem::path
#include <boost/tokenizer.hpp>  // boost::char_separator<>, boost::tokenizer<>
#include <oglplus/opt/smart_enums.hpp>

#include <glm/glm.hpp>
#include <oglplus/interop/glm.hpp>
#include <glm/gtx/io.hpp>
#include <glm/gtx/transform.hpp>

// includes, project

#include <platform/oglplus/application.hpp>
#include <support/chrono_io.hpp>
#include <support/io_utils.hpp>
#include <support/string.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class frame_handler : public platform::handler::frame::base {

  public:

    explicit frame_handler()
      : platform::handler::frame::base(7)
    {}
    
    double fps() const
    {
      using namespace std::chrono;

      double result(1.0);

      if (!frameq_.empty()) {
        result /= duration_cast<duration<double>>(frameq_.back().cma).count();
      }
      
      return result;
    }
    
  } dflt_frame_handler;
  
  // variables, internal
  
  // functions, internal

  std::string
  glsl_normalize_string(std::string const& a)
  {
    std::string result(a);

    std::replace(result.begin(), result.end(), '\\', '/');

    std::string const            s("C:");
    std::string::size_type const i(result.find(s));

    if (i != std::string::npos) {
      result.replace(i, s.length(), "/c");
    }

    return result;
  }
  
} // namespace {

namespace voxels {
  
  // variables, exported
  
  // functions, exported
  
  /* explicit */
  window::window(command_line const& a, rect const& b)
    : inherited        (a.argv0 + " ", b),
      ctx_             (),
      prg_             (),
      vspace_          (glm::uvec3(10)),
      light_list_      ("light_list_buf",    prg_),
      material_list_   ("material_list_buf", prg_),
      cpu_stats_       (a.argv0 + ":cpu"),
      gpu_stats_       (a.argv0 + ":gpu"),
      camera_          ({ glm::mat4() }),
      projection_      ({ glm::mat4(), 60.0, glm::vec2(0.001, 1000.0) }),
      title_base_      (title.get()),
      navigation_hndlr_(nullptr)
  {
    TRACE("voxels::window::window");

    frame_handler += &dflt_frame_handler;
    
    using namespace oglplus;

    {
      namespace bfs = boost::filesystem;

      static std::string const sep("/");
      static std::string const dd ("..");
      
#if defined(_WIN32)
      static std::string const btrack(dd + sep + dd);
#else
      static std::string const btrack(dd);
#endif
        
      bfs::path const   p(a.argv0);
      std::string const d(bfs::canonical(p.parent_path()).string());
      std::string const b(d + sep + btrack + sep + "share" + sep + "shader" + sep + "glsl");

      std::array<std::string const, 11> const file_names = {
        {
          std::string("app_oglplus_voxels.vs.glsl"),
          std::string("app_oglplus_voxels.gs.glsl"),
          std::string("phong.fp.glsl"),
          std::string("common/config.glsl"),
          std::string("common/constants.glsl"),
          std::string("common/functions.glsl"),
          std::string("common/light.glsl"),
          std::string("common/material.glsl"),
          std::string("common/phong.glsl"),
          std::string("common/pipeline.glsl"),
          std::string("common/uniforms.glsl"),
        }
      };

      for (auto fname : file_names) {
        auto fn(b + sep + fname);
        
        //std::cout << "loading shader file: '" << fn << "'";
                  
        std::stringstream src;

        src << std::ifstream(fn).rdbuf();

        if (!src.str().empty()) {
          std::string const tmp(glsl_normalize_string(fn));
          
          //std::cout << " as '" << tmp << "'\n";
          
          NamedString::Set(NamedStringType::ShaderInclude, tmp, src.str());
        } else {
          throw std::runtime_error("unable to load content for shader file '" + fn + "'");
        }
      }

      prg_ << VertexShader  ().
        Source(NamedString::Get(glsl_normalize_string(b + sep + file_names[0])))
           << GeometryShader().
        Source(NamedString::Get(glsl_normalize_string(b + sep + file_names[1])))
           << FragmentShader().
        Source(NamedString::Get(glsl_normalize_string(b + sep + file_names[2])));

      // to avoid removal/deactivation of attributes ARB_separate_shader_objects is used
      prg_/*.MakeSeparable(true)*/
        .BuildInclude({ glsl_normalize_string(d), glsl_normalize_string(b) })
        .Link()
        .Use();
    }
    
    {
      glm::uvec3 const size(vspace_.size());
      
      camera_.xform = glm::inverse(glm::lookAt(glm::vec3(size) * glm::vec3(2, 0.75, 2),
                                               glm::vec3(size - glm::uvec3(1)) * glm::vec3(0.5),
                                               glm::vec3( 0.0f, 1.0f, 0.0f)));
    }
    
    {
      using namespace platform::handler;
      
      navigation_hndlr_.reset(new navigation::simple);
      
      keyboard_handler += dynamic_cast<keyboard::base*>(navigation_hndlr_.get());
      mouse_handler    += dynamic_cast<mouse::base*>   (navigation_hndlr_.get());
    }
    
    ctx_.ClearColor(0.95f, 0.95f, 0.95f, 0.0f);
    ctx_.ClearDepth(1.0f);
    ctx_.Enable    (smart_enums::DepthTest());
    
    ctx_.BlendFunc(BlendFn::SrcAlpha, BlendFn::OneMinusSrcAlpha);
    ctx_.Enable   (smart_enums::Blend());
    
    ctx_.Enable(smart_enums::CullFace());
  }

  /* virtual */
  window::~window()
  {
    TRACE("voxels::window::~window");
  }
  
  /* virtual */ void
  window::frame_render_one()
  {
    TRACE_NEVER("voxels::window::frame_render_one");

    {
      stats::guard const sgcpu(cpu_stats_);
      stats::guard const sggpu(gpu_stats_);

      using namespace oglplus;

      ctx_.Clear().ColorBuffer().DepthBuffer();
      
      glm::mat4 xfview;
      
      // view
      if (Uniform<glm::mat4>(prg_, "xform_view").IsActive()) {
        glm::mat4 const xlat(camera_.xform * navigation_hndlr_->translation.get());
        glm::mat4 const rotl(                navigation_hndlr_->rotation.get());

        xfview = rotl * glm::inverse(xlat);
        
        Uniform<glm::mat4>(prg_, "xform_view").Set(xfview);
      }
      
      {
        using light_t = light_list_type::value_type;
      
        std::array<light_t const, 4> const lights = {
          {
            light_t(true,
                    //glm::inverse(xfview) *
                    glm::vec4( 1.0,  0.0,  0.0,  0.0),
                    glm::vec3(-1.0,  0.0,  0.0),
                    glm::vec3( 0.1,  0.0,  0.0),
                    glm::vec3( 0.3,  0.0,  0.0),
                    glm::vec3( 0.6,  0.0,  0.0)),
            light_t(true,
                    //glm::inverse(xfview) *
                    glm::vec4( 0.0,  1.0,  0.0,  0.0),
                    glm::vec3( 0.0, -1.0,  0.0),
                    glm::vec3( 0.0,  0.1,  0.0),
                    glm::vec3( 0.0,  0.3,  0.0),
                    glm::vec3( 0.0,  0.6,  0.0)),
            light_t(true,
                    //glm::inverse(xfview) *
                    glm::vec4( 0.0,  0.0,  1.0,  0.0),
                    glm::vec3( 0.0,  0.0, -1.0),
                    glm::vec3( 0.0,  0.0,  0.1),
                    glm::vec3( 0.0,  0.0,  0.3),
                    glm::vec3( 0.0,  0.0,  0.6)),
            light_t(true,
                    (glm::inverse(xfview) * glm::vec4(0.0, 0.0,  0.0, 1.0)),
                    (glm::inverse(xfview) * glm::vec4(0.0, 0.0, -1.0, 0.0)).xyz(),
                    glm::vec3( 0.1,  0.1,  0.1),
                    glm::vec3( 0.3,  0.3,  0.3),
                    glm::vec3( 0.6,  0.6,  0.6),
                    glm::vec3( 1.0,  0.0,  0.0), 64.0, 45.0/*_deg*/),
          }
        };
      
        light_list_.update(lights);
      }

      {
        using material_t = material_list_type::value_type;
        
        std::array<material_t const, 1> const materials = {
          {
            material_t(glm::vec3(0.2, 0.2, 0.2),
                       glm::vec3(0.8, 0.8, 0.8),
                       glm::vec3(0.0, 0.0, 0.0),
                       glm::vec3(0.2, 0.2, 0.2),
                       glm::vec3(0.0, 0.0, 0.0),
                       1.0,
                       64.0,
                       1.0,
                       true, false),
          }
        };
      
        material_list_.update(materials);
      }

      // draw voxels
      vspace_.draw();
    }

#if 0
    {
      for (auto const& m : model_list_) {
        model::mesh::stats_result_type const sm(m->fetch_stats());

        std::cout << sm.first << '\t' << sm.second << '\n';
      }

      std::cout << cpu_stats_.fetch() << '\t' << gpu_stats_.fetch() << '\n';
    }
#endif
  }

  /* virtual */ void
  window::frame_render_pre()
  {
    TRACE_NEVER("voxels::window::frame_render_pre");

    {
      std::ostringstream ostr;

      ostr << title_base_
           << " ["
           << std::fixed << std::right << std::setfill(' ') << std::setw(7) << std::setprecision(3)
           << dflt_frame_handler.fps()
           << "Hz]";
      
      title = ostr.str();
    }
    
    ctx_.Clear().ColorBuffer().DepthBuffer();
  }
    
  /* virtual */ void
  window::reshape(glm::ivec2 const& size)
  {
    TRACE("voxels::window::reshape");

    inherited::reshape(size);

    projection_.xform = glm::perspective(glm::radians(projection_.fovy_degree),
                                         float(size.x) / float(size.y),
                                         projection_.near_far.x, projection_.near_far.y);
      
    using namespace oglplus;

    ctx_.Viewport(size.x, size.y);

    if (Uniform<glm::mat4>(prg_, "xform_projection").IsActive()) {
      Uniform<glm::mat4>(prg_, "xform_projection").Set(projection_.xform);
    }

    if (Lazy<Uniform<glm::ivec2>>(prg_, "screen_size").IsActive()) {
      Lazy<Uniform<glm::ivec2>>(prg_, "screen_size").Set(size);
    }
  }

} // namespace voxels {
