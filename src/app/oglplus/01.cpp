// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/01.cpp                                                              */
/*  project    :                                                                                  */
/*  description:  liberated from oglplus example '007_glm_boxes.cpp'                              */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <GL/glew.h> // ::glew*

#include <boost/filesystem.hpp>    // boost::filesystem::path
#include <oglplus/all.hpp>
#include <oglplus/ext/EXT_direct_state_access.hpp>
#include <oglplus/opt/resources.hpp>
#include <oglplus/shapes/cube.hpp>

#include <glm/glm.hpp>
#include <oglplus/interop/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// includes, project

#include <../common/glut.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {

  // types, internal (class, enum, struct, union, typedef)

  class application : public glut::application {

  public:    

    explicit application(int argc, char* argv[])
      : glut::application(argc, argv),
        ctx_             (),
        dsa_             (),
        vs_              (),
        fs_              (),
        prg_             (),
        make_cube_       (),
        cube_instr_      (make_cube_.Instructions()),
        cube_indices_    (make_cube_.Indices()),
        frame_time_      (prg_, "Time")
    {
      TRACE("<unnamed>::application::application");

      using namespace oglplus;

      {
        namespace bfs = boost::filesystem;

        bfs::path const   p(argv[0]);
        std::string const f(p.filename().string());
        std::string const d(p.parent_path().string());
        
        ResourceFile      vs_src(d + "/../share/shader/glsl", f, ".vs.glsl");
        ResourceFile      fs_src(d + "/../share/shader/glsl", f, ".fs.glsl");
        
        vs_.Source(GLSLSource::FromStream(vs_src.stream()));
        fs_.Source(GLSLSource::FromStream(fs_src.stream()));
      
        prg_ << vs_ << fs_;
      
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
    
    virtual void frame_render_one()
    {
      TRACE("<unnamed>::application::frame_render_one");

      ctx_.Clear().ColorBuffer().DepthBuffer();

      {
        using namespace std::chrono;
      
        frame_time_.
          Set(duration_cast<duration<double>>(frameq_.back().stamp.time_since_epoch()).count());
      }
      
      cube_instr_.Draw(cube_indices_, 36);
    }
    
    virtual void reshape(glm::ivec2 const& size)
    {
      TRACE("<unnamed>::application::reshape");

      ctx_.Viewport(size.x, size.y);

      auto camera(glm::perspective(53.0f*3.1415f/180.f,
                                   float(size.x)/float(size.y),
                                   1.0f, 100.0f) *
                  glm::lookAt(glm::vec3(21.0f, 8.0f, 7.0f),
                              glm::vec3( 0.0f, 0.0f, 0.0f),
                              glm::vec3( 0.0f, 1.0f, 0.0f)));
      
      oglplus::Uniform<glm::mat4x4>(prg_, "CameraMatrix").Set(camera);
    }

  private:

    oglplus::Context                     ctx_;
    oglplus::EXT_direct_state_access     dsa_;
    
    oglplus::VertexShader                vs_;
    oglplus::FragmentShader              fs_;
    oglplus::Program                     prg_;

    oglplus::shapes::Cube                make_cube_;
    oglplus::shapes::DrawingInstructions cube_instr_;
    oglplus::shapes::Cube::IndexArray    cube_indices_;
    oglplus::VertexArray                 cube_va_;
    oglplus::Buffer                      positions_;
    oglplus::Buffer                      normals_;

    oglplus::Lazy<oglplus::Uniform<float>> frame_time_;
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

int
main(int argc, char* argv[])
{
  TRACE("main");
  
  return glut::execute<application>(argc, argv, std::nothrow);
}
