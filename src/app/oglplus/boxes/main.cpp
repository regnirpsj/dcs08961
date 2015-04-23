// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/main.cpp                                                            */
/*  project    :                                                                                  */
/*  description:  liberated from oglplus example '007_glm_boxes.cpp'                              */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <GL/glew.h>                    // ::glew*

#include <boost/filesystem.hpp>         // boost::filesystem::path
#include <oglplus/all.hpp>
#include <oglplus/opt/resources.hpp>
#include <oglplus/shapes/cube.hpp>

#include <csignal>                      // SIG*
#include <cstring>                      // ::strsignal
#include <glm/glm.hpp>
#include <oglplus/interop/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/io.hpp>

// includes, project

#include <platform/glut/application/base.hpp>
#include <platform/glut/window/simple.hpp>
#include <platform/oglplus/application.hpp>
#include <support/signal_handler.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {

  // types, internal (class, enum, struct, union, typedef)

  class window : public platform::glut::window::simple {
    
    using inherited = platform::glut::window::simple;
    using rect      = platform::window::rect;
    
  public:

    explicit window(std::string const& a, rect const& b, std::string const& c)
      : inherited     (a, b),
        ctx_          (),
        prg_          (),
        make_cube_    (),
        cube_instr_   (make_cube_.Instructions()),
        cube_indices_ (make_cube_.Indices()),
        frame_time_   (prg_, "Time")
    {
      TRACE("<unnamed>::window::window");
      
      using namespace oglplus;

      {
        namespace bfs = boost::filesystem;

        bfs::path const   p(c);
        std::string const d(p.parent_path().string());
        std::string const f(p.stem().string());
        
#if defined(_WIN32)
        static std::string const btrack("../..");
#else
        static std::string const btrack("..");
#endif

        ResourceFile vs_src(d + "/" + btrack + "/share/shader/glsl", f, ".vs.glsl");
        ResourceFile fs_src(d + "/" + btrack + "/share/shader/glsl", f, ".fs.glsl");
        
        prg_ << VertexShader().Source(GLSLSource::FromStream(vs_src.stream()))
             << FragmentShader().Source(GLSLSource::FromStream(fs_src.stream()));
        
        prg_.Link().Use();
      }
      
      cube_va_.Bind();

      positions_.Bind(Buffer::Target::Array);
      {
        std::vector<GLfloat> data;
        GLfloat              size(make_cube_.Positions(data));
        
        Buffer::Data(Buffer::Target::Array, data);

        VertexArrayAttrib attr(prg_, "Position");
        
        attr.Setup<GLfloat>(size);
        attr.Enable();
      }
      
      normals_.Bind(Buffer::Target::Array);
      {
        std::vector<GLfloat> data;
        GLfloat              size(make_cube_.Normals(data));
        
        Buffer::Data(Buffer::Target::Array, data);
        
        VertexArrayAttrib attr(prg_, "Normal");

        attr.Setup<GLfloat>(size);
        attr.Enable();
      }
    
      ctx_.ClearColor(0.95f, 0.95f, 0.95f, 0.0f);
      ctx_.ClearDepth(1.0f);
      ctx_.Enable(Capability::DepthTest);
      
      Typechecked<Uniform<glm::vec3>>  (prg_, "LightPos").
        Set(glm::vec3(7.0, 3.0, -1.0));
      
      Typechecked<Uniform<glm::mat4x4>>(prg_, "ScaleMatrix").
        Set(glm::scale(glm::mat4(1.0),
                       glm::vec3(1.0, 0.3, 1.7)));
    }

    virtual ~window()
    {
      TRACE("<unnamed>::window::~window");
    }
    
  private:

    virtual void frame_render_one()
    {
      TRACE_NEVER("<unnamed>::window::frame_render_one");

      ctx_.Clear().ColorBuffer().DepthBuffer();
      
      {
        using namespace std::chrono;
      
        frame_time_.
          Set(duration_cast<duration<double>>(support::clock::now().time_since_epoch()).count());
      }
      
      cube_instr_.Draw(cube_indices_, 36);
    }

    virtual void reshape(glm::ivec2 const& size)
    {
      TRACE("<unnamed>::window::reshape");
      
      ctx_.Viewport(size.x, size.y);

      auto camera(glm::perspective(53.0f*3.1415f/180.f,
                                   float(size.x)/float(size.y),
                                   1.0f, 100.0f) *
                  glm::lookAt(glm::vec3(21.0f, 8.0f, 7.0f),
                              glm::vec3( 0.0f, 0.0f, 0.0f),
                              glm::vec3( 0.0f, 1.0f, 0.0f)));
      
      oglplus::Uniform<glm::mat4x4>(prg_, "CameraMatrix").Set(camera);
    }
    
    oglplus::Context                       ctx_;
    oglplus::Program                       prg_;
    oglplus::shapes::Cube                  make_cube_;
    oglplus::shapes::DrawingInstructions   cube_instr_;
    oglplus::shapes::Cube::IndexArray      cube_indices_;
    oglplus::VertexArray                   cube_va_;
    oglplus::Buffer                        positions_;
    oglplus::Buffer                        normals_;
    oglplus::Lazy<oglplus::Uniform<float>> frame_time_;
    
  };
  
  class application : public platform::glut::application::base {

    using command_line = platform::application::command_line;
    using inherited    = platform::glut::application::base;
    using rect         = platform::window::rect;
    
  public:

    static void terminate(signed signo)
    {
      TRACE("<unnamed>::application::terminate");
      
      inherited::terminate = true;

      std::cout << '\n'
                << "terminating by user request ('"
                << ::strsignal(signo) << "' " << signo << ")"
                << '\n';
    }
    
    explicit application(command_line const& a)
      : inherited(a),
        window_  (nullptr)
    {
      TRACE("<unnamed>::application::application");
    }

    virtual ~application()
    {
      TRACE("<unnamed>::application::~application");
    }
    
    virtual void process_command_line()
    {
      TRACE("<unnamed>::application::process_command_line");

      inherited::process_command_line();

      window_.reset(new window(command_line_.argv0, rect(50, 50, 1440, 900), command_line_.argv0));
    }
    
  private:

    std::unique_ptr<window> window_;
    
  };
  
  // variables, internal
  
  // functions, internal
  
} // namespace {

int
main(int argc, char const* argv[])
{
  TRACE("main");

  support::signal_handler::instance->handler(SIGINT,  &application::terminate);
  support::signal_handler::instance->handler(SIGTERM, &application::terminate);
  
  namespace pa  = platform::application;
  namespace poa = platform::oglplus::application;
  
  return poa::execute<application>(pa::command_line(argc, argv), std::nothrow);
}
