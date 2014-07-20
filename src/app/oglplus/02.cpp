// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/02.cpp                                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <GL/glew.h>            // ::glew*

#include <boost/filesystem.hpp> // boost::filesystem::path
#include <oglplus/all.hpp>
#include <oglplus/opt/resources.hpp>
#include <oglplus/shapes/obj_mesh.hpp>

#include <glm/glm.hpp>
#include <oglplus/interop/glm.hpp>
#include <glm/gtx/transform.hpp>

#include <vector>

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
        prg_             (),
        varray_          (),
        model_           (prg_, "model"),
        view_            (prg_, "view"),
        proj_            (prg_, "proj"),
        model_list_      ()
    {
      TRACE_ALWAYS("<unnamed>::application::application");

      using namespace oglplus;
      
      {
        namespace bfs = boost::filesystem;

        bfs::path const   p(argv[0]);
        std::string const d(p.parent_path().string());
        std::string const f(p.filename().string());
        
        ResourceFile      vs_src(d + "/../share/shader/glsl", f, ".vs.glsl");
        ResourceFile      fs_src(d + "/../share/shader/glsl", f, ".fs.glsl");
        
        prg_ << VertexShader().Source(GLSLSource::FromStream(vs_src.stream()))
             << FragmentShader().Source(GLSLSource::FromStream(fs_src.stream()));
        
        prg_.Link().Use();
      }

      
      varray_.Bind();
      
      for (auto f : input_files_) {
        model_file mf(f);
        
        model_list_.push_back(model_mesh_list_type::value_type(new model_mesh(mf, prg_)));
      }
      
      ctx_.ClearColor(0.95f, 0.95f, 0.95f, 0.0f);
      ctx_.ClearDepth(1.0f);
      ctx_.Enable(Capability::DepthTest);
    }
    
    virtual void frame_render_one()
    {
      TRACE("<unnamed>::application::frame_render_one");

      using namespace oglplus;
      
      ctx_.Clear().ColorBuffer().DepthBuffer();

      // view
      Typechecked<Uniform<glm::mat4>>(prg_, "view").
        Set(glm::lookAt(glm::vec3( 2.0f, 2.0f, 2.0f),
                        glm::vec3( 0.0f, 0.0f, 0.0f),
                        glm::vec3( 0.0f, 1.0f, 0.0f)));

      // model(s)
      for (auto const& m : model_list_) {
        Typechecked<Uniform<glm::mat4>>(prg_, "model").Set(m->xform);
        // Typechecked<Uniform<unsigned>>(prg_, "mtl_id").Set(m->material_id);
        
        m->instructions.Draw(m->indices);
      }
    }
    
    virtual void reshape(glm::ivec2 const& size)
    {
      TRACE("<unnamed>::application::reshape");

      using namespace oglplus;
      
      ctx_.Viewport(size.x, size.y);

      // Typechecked<Uniform<glm::ivec2>>(prg_, "screen").Set(size);

      Typechecked<Uniform<glm::mat4>>(prg_, "proj").
        Set(glm::perspective(53.0f * 3.1415f / 180.f,
                             float(size.x) / float(size.y),
                             0.1f, 100.0f));
    }

  private:

    struct model_file {

      std::ifstream stream;

      model_file(std::string const& a)
        : stream()
      {
        TRACE("<unnamed>::application::model_file::model_file");
        
        namespace bfs = boost::filesystem;

        bfs::path const   p(a);
        std::string const d(p.parent_path().string());
        std::string const f(p.stem().string());
        std::string const e(p.extension().string());

#if defined(UKACHULLDCS_USE_TRACE)
        std::cout << support::trace::prefix() << "<unnamed>::application::model_file::model_file: "
                  << "'" << d + "/" + f + e << "'"
                  << std::endl;
#endif
        
        oglplus::OpenResourceFile(stream, d, f, e.c_str());
      }
      
    };

    struct model_mesh {

      oglplus::shapes::ObjMesh             mesh;
      oglplus::shapes::DrawingInstructions instructions;
      oglplus::shapes::ObjMesh::IndexArray indices;
      oglplus::Spheref                     bsphere;
      oglplus::Buffer                      positions;
      oglplus::Buffer                      normals;
      glm::mat4                            xform;
      unsigned                             material_id;
      
      model_mesh(model_file& file, oglplus::Program& program)
        : mesh        (file.stream),
          instructions(mesh.Instructions()),
          indices     (mesh.Indices()),
          bsphere     (),
          positions   (),
          normals     (),
          xform       (glm::scale(glm::vec3(.25))),
          material_id ()
      {
        TRACE("<unnamed>::application::model_mesh::model_mesh");

        using namespace oglplus;
        
        mesh.BoundingSphere(bsphere);
        
        positions.Bind(Buffer::Target::Array);
        {
          std::vector<GLfloat> data;
          GLuint               n_per_vertex(mesh.Positions(data));
          
          Buffer::Data(Buffer::Target::Array, data);
          
          (program|"position").Setup<GLfloat>(n_per_vertex).Enable();
        }

        normals.Bind(Buffer::Target::Array);
        {
          std::vector<GLfloat> data;
          GLuint               n_per_vertex(mesh.Normals(data));
          
          Buffer::Data(Buffer::Target::Array, data);

          (program|"normal").Setup<GLfloat>(n_per_vertex).Enable();
        }
      }
      
    };

    typedef std::vector<std::unique_ptr<model_mesh>> model_mesh_list_type;
    
    oglplus::Context                           ctx_;
    oglplus::Program                           prg_;
    oglplus::VertexArray                       varray_;
    oglplus::Lazy<oglplus::Uniform<glm::mat4>> model_;
    oglplus::Lazy<oglplus::Uniform<glm::mat4>> view_;
    oglplus::Lazy<oglplus::Uniform<glm::mat4>> proj_;
    
    model_mesh_list_type model_list_;
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

int
main(int argc, char* argv[])
{
  TRACE("main");
  
  return glut::execute<application>(argc, argv); //, std::nothrow);
}
