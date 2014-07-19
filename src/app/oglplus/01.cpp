// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/01.cpp                                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <GL/glew.h> // ::glew*

#include <oglplus/all.hpp>
#include <oglplus/ext/EXT_direct_state_access.hpp>
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

  std::string const vertex_shader_src
  (
   "#version 330\n"
   "uniform mat4 CameraMatrix, ScaleMatrix;"
   "uniform vec3 LightPos;"
   "uniform float Time;"
   "in vec4 Position;"
   "in vec3 Normal;"
   "out vec3 vertColor;"
   "void main(void)"
   "{"
   "	float angle = gl_InstanceID * 10 * 2 * 3.14159 / 360.0;"
   "	float ct = cos(angle+Time);"
   "	float st = sin(angle+Time);"
   "	mat4 ModelMatrix = mat4("
   "		 ct, 0.0,  st, 0.0,"
   "		0.0, 1.0, 0.0, 0.0,"
   "		-st, 0.0,  ct, 0.0,"
   "		0.0, 0.0, 0.0, 1.0 "
   "	) * mat4("
   "		 1.0, 0.0, 0.0, 0.0,"
   "		 0.0, 1.0, 0.0, 0.0,"
   "		 0.0, 0.0, 1.0, 0.0,"
   "		12.0, 0.0, 0.0, 1.0 "
   "	) * mat4("
   "		 ct, -st, 0.0, 0.0,"
   "		 st,  ct, 0.0, 0.0,"
   "		0.0, 0.0, 1.0, 0.0,"
   "		0.0, 0.0, 0.0, 1.0 "
   "	);"
   "	gl_Position = "
   "		ModelMatrix *"
   "		ScaleMatrix *"
   "		Position;"

   "	vec3 vertLightDir = normalize(LightPos - gl_Position.xyz);"
   "	vec3 vertNormal = normalize(("
   "		ModelMatrix *"
   "		vec4(Normal, 0.0)"
   "	).xyz);"

   "	gl_Position = CameraMatrix * gl_Position;"

   "	vertColor = abs(normalize("
   "		Normal -"
   "		vec3(1.0, 1.0, 1.0) +"
   "		Position.xyz*0.2"
   "	)) * (0.6 + 0.5*max(dot(vertNormal, vertLightDir), 0.0));"
   "}"
   );

  std::string const fragment_shader_src
  (
   "#version 330\n"
   "in  vec3 vertColor;"
   "out vec3 fragColor;"
   "void main(void)"
   "{"
   "	 fragColor = vertColor;"
   "}"
   );
  
  // types, internal (class, enum, struct, union, typedef)

  class application : public glut::application {

  public:

    explicit application(int argc, char* argv[])
      : glut::application(argc, argv),
        ctx_             (),
        dsa_             (),
        vs_              (vertex_shader_src),
        fs_              (fragment_shader_src),
        prg_             (),
        make_cube_       (),
        cube_instr_      (make_cube_.Instructions()),
        cube_indices_    (make_cube_.Indices())
    {
      TRACE("<unnamed>::application::application");

      prg_ << vs_ << fs_;
      
      prg_.Link();
      prg_.Use();

      cube_va_.Bind();

      // bind the VBO for the cube vertex positions
      positions_.Bind(oglplus::Buffer::Target::Array);
      {
        std::vector<GLfloat> data;
        GLuint n_per_vertex = make_cube_.Positions(data);
        // upload the data
        oglplus::Buffer::Data(oglplus::Buffer::Target::Array, data);
        // setup the vertex attribs array for the vertices
        oglplus::VertexArrayAttrib attr(prg_, "Position");
        attr.Setup<GLfloat>(n_per_vertex);
        attr.Enable();
      }

      // bind the VBO for the cube normals
      normals_.Bind(oglplus::Buffer::Target::Array);
      {
        std::vector<GLfloat> data;
        GLuint n_per_vertex = make_cube_.Normals(data);
        // upload the data
        oglplus::Buffer::Data(oglplus::Buffer::Target::Array, data);
        // setup the vertex attribs array for the vertices
        oglplus::VertexArrayAttrib attr(prg_, "Normal");
        attr.Setup<GLfloat>(n_per_vertex);
        attr.Enable();
      }
    
      ctx_.ClearColor(1.0f, 1.0f, 1.0f, 0.0f);
      ctx_.ClearDepth(1.0f);
      ctx_.Enable(oglplus::Capability::DepthTest);
      
      oglplus::Typechecked<oglplus::Uniform<glm::vec3>>  (prg_, "LightPos").
        Set(glm::vec3(7.0, 3.0, -1.0));
      oglplus::Typechecked<oglplus::Uniform<glm::mat4x4>>(prg_, "ScaleMatrix").
        Set(glm::scale(glm::mat4(1.0), glm::vec3(1.0, 0.3, 1.7)));
    }
    
    virtual void frame_render_one()
    {
      TRACE("<unnamed>::application::frame_render_one");

      ctx_.Clear().ColorBuffer().DepthBuffer();

      cube_instr_.Draw(cube_indices_, 36);
    }
    
    virtual void reshape(glm::ivec2 const& size)
    {
      TRACE("<unnamed>::application::reshape");

      ctx_.Viewport(size.x, size.y);

      auto camera(glm::perspective(53.0f*3.1415f/180.f,
                                   float(size.x)/float(size.y),
                                   1.0f, 100.0f) *
                  glm::lookAt(glm::vec3(21.0f, 7.0f, 0.0f),
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
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

int
main(int argc, char* argv[])
{
  return glut::execute<application>(argc, argv, std::nothrow);
}
