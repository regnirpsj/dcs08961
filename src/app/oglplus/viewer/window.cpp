// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/viewer/window.cpp                                                   */
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

namespace viewer {
  
  // variables, exported
  
  // functions, exported
  
  /* explicit */
  window::window(command_line const& a, rect const& b,
                 std::string const& c, string_list_type const& d)
    : inherited        (a.argv0 + " [" + c + "]", b),
      ctx_             (),
      prg_             (),
      tex_diffuse_     (),
      tex_envmap_      (),
      model_list_      (),
      light_list_      ("light_list_buf",    prg_, 1),
      material_list_   ("material_list_buf", prg_, 2),
      cpu_stats_       (a.argv0 + ":cpu"),
      gpu_stats_       (a.argv0 + ":gpu"),
      camera_          ({ glm::mat4() }),
      projection_      ({ glm::mat4(), 60.0, glm::vec2(0.001, 1000.0) }),
      title_base_      (title.get()),
      navigation_hndlr_(nullptr)
  {
    TRACE("viewer::window::window");

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

      std::array<std::string const, 10> const file_names = {
        {
          std::string("phong.vp.glsl"),
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
        
        std::cout << "loading shader file: '" << fn << "'";
                  
        std::stringstream src;

        src << std::ifstream(fn).rdbuf();

        if (!src.str().empty()) {
          std::string const tmp(glsl_normalize_string(fn));
          
          std::cout << " as '" << tmp << "'\n";
          
          NamedString::Set(NamedStringType::ShaderInclude, tmp, src.str());
        } else {
          throw std::runtime_error("unable to load content for shader file '" + fn + "'");
        }
      }

      prg_ << VertexShader  ().Source(NamedString::Get(glsl_normalize_string(b + sep + file_names[0])))
           << FragmentShader().Source(NamedString::Get(glsl_normalize_string(b + sep + file_names[1])));

      // to avoid removal/deactivation of attributes ARB_separate_shader_objects is used
      prg_.MakeSeparable(true).BuildInclude({ glsl_normalize_string(d), glsl_normalize_string(b) }).Link().Use();
    }
    
    if (!d.empty()) {
      glm::uvec3 size;
      glm::vec3  incr;

      {
        typedef boost::tokenizer<boost::char_separator<char>> tokenizer;

        boost::char_separator<char> const sep          ("x");
        tokenizer                         tokens       (c, sep);
        tokenizer::iterator               current_token(tokens.begin());

        for (unsigned i(0); i < 3; ++i) {
          try {
            size[i] = std::stoi(*current_token);
          }

          catch (std::logic_error&) {
            size[i] = unsigned(d.size());
          }

          incr[i] = (size[i] > 1) ? 1.05f : 0.0f;

          ++current_token;
        }
      }

      size = glm::max(size, glm::uvec3(1, 1, 1));
      
      unsigned                         load_count(0);
      support::timer                   timer_single;
      support::timer                   timer_total;
      string_list_type::const_iterator f(d.begin());

      timer_total.reset();
        
      for (unsigned x(0); x < size.x; ++x) {
        for (unsigned y(0); y < size.y; ++y) {
          for (unsigned z(0); z < size.z; ++z) {
            glm::vec3 const pos(glm::vec3(x,y,z) * incr);
            model::mesh*    mm(nullptr);

            timer_single.reset();

            try {
              mm = new model::mesh(*f, prg_);

              mm->xform(glm::translate(pos) * mm->xform());

              model_list_.push_back(model_mesh_list_type::value_type(mm));
            }

            catch (oglplus::Error& ex) {
              platform::oglplus::application::print_oglplus_error_common(ex, std::cerr,
                                                                         "OGLPlus: GL error");

              delete mm; mm = nullptr;
            }

            catch (std::runtime_error& ex) {
              platform::oglplus::application::print_stdcpp_error_common(ex, std::cerr,
                                                                        "System: Runtime error");
              std::cerr << std::endl;

              delete mm; mm = nullptr;
            }

            if (nullptr == mm) {
              std::cout << "unable to load file: "  << *f << std::endl;
            } else {
              using namespace std::chrono;

              std::cout << "loaded:'" << *f << "' @"
                        << glm::io::precision(2) << glm::io::width(6)
                        << pos << " in "
                        << duration_fmt(symbol) << std::fixed << std::right
                        << duration_cast<duration<double>>(timer_single.lapse())
                        << std::endl;

              ++load_count;
            }

            if (d.end() == ++f) {
              f = d.begin();
            }
          }
        }
      }

      {
        using namespace std::chrono;
          
        std::cout << "loaded " << load_count << " file" << ((1 != load_count) ? "s" : "") << " in "
                  << duration_fmt(symbol) << std::fixed << std::right
                  << duration_cast<duration<double>>(timer_total.lapse())
                  << std::endl;
      }
        
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
    ctx_.Enable(smart_enums::DepthTest());
    ctx_.Enable(smart_enums::CullFace());
  }

  /* virtual */
  window::~window()
  {
    TRACE("viewer::window::~window");
  }
  
  /* virtual */ void
  window::frame_render_one()
  {
    TRACE_NEVER("viewer::window::frame_render_one");

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
      
      // model(s)
      for (auto const& m : model_list_) {
        m->draw();
      }
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
    TRACE_NEVER("viewer::window::frame_render_pre");

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
    TRACE("viewer::window::reshape");

    inherited::reshape(size);

    projection_.xform = glm::perspective(projection_.fovy_degree * 3.1415f / 180.f,
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

} // namespace viewer {
