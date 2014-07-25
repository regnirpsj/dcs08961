// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/common/model.hpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_APP_COMMON_MODEL_HPP)

#define UKACHULLDCS_08961_APP_COMMON_MODEL_HPP

// includes, system

#include <GL/glew.h>                    // ::gl*
#include <boost/filesystem.hpp>         // boost::filesystem::path
#include <oglplus/all.hpp>
#include <oglplus/opt/resources.hpp>
#include <oglplus/shapes/obj_mesh.hpp>

#include <glm/glm.hpp>
#include <oglplus/interop/glm.hpp>
#include <glm/gtx/transform.hpp>

// includes, project

// #include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
#if defined(UKACHULLDCS_USE_TRACE) || defined(UKACHULLDCS_ALL_TRACE)
#  include <typeinfo>
#  include <support/type_info.hpp>
#endif

namespace model {
  
  // types, exported (class, enum, struct, union, typedef)

  struct file {

    std::ifstream stream;

    file(std::string const& a)
      : stream()
    {
      TRACE("<unnamed>::application::file::file");
        
      namespace bfs = boost::filesystem;

      bfs::path const   p(a);
      std::string const d(p.parent_path().string());
      std::string const f(p.stem().string());
      std::string const e(p.extension().string());

#if defined(UKACHULLDCS_USE_TRACE)
      std::cout << support::trace::prefix() << "<unnamed>::application::file::file: "
                << "'" << d + "/" + f + e << "'"
                << std::endl;
#endif
        
      oglplus::OpenResourceFile(stream, d, f, e.c_str());
    }
      
  };

  struct mesh {

    oglplus::Program&                    prg_;
    oglplus::shapes::ObjMesh             mesh_;
    oglplus::shapes::DrawingInstructions instructions;
    oglplus::shapes::ObjMesh::IndexArray indices;
    oglplus::VertexArray                 vao;
    oglplus::Buffer                      positions;
    oglplus::Buffer                      normals;
    oglplus::Buffer                      tcoords;
    glm::mat4                            xform;
    signed                               material_id;
      
    mesh(file& f, oglplus::Program& p)
      : prg_        (p),
        mesh_       (f.stream),
        instructions(mesh_.Instructions()),
        indices     (mesh_.Indices()),
        vao         (),
        positions   (),
        normals     (),
        tcoords     (),
        xform       (),
        material_id (-1)
    {
      TRACE("<unnamed>::application::mesh::mesh");

      using namespace oglplus;

      {
        oglplus::Spheref bsphere;
          
        mesh_.BoundingSphere(bsphere);

        if (!bsphere.Degenerate()) {
          xform = (glm::scale(glm::vec3(1.0 / bsphere.Diameter())) *
                   glm::translate(-glm::vec3(bsphere.Center().x(),
                                             bsphere.Center().y(),
                                             bsphere.Center().z())));
        }
      }
        
      vao.Bind();
        
      positions.Bind(Buffer::Target::Array);
      {
        std::vector<GLfloat> data;
        GLuint               n_per_vertex(mesh_.Positions(data));
          
        Buffer::Data(Buffer::Target::Array, data);
          
        (prg_|"position").Setup<GLfloat>(n_per_vertex).Enable();
      }

      normals.Bind(Buffer::Target::Array);
      {
        std::vector<GLfloat> data;
        GLuint               n_per_vertex(mesh_.Normals(data));
          
        Buffer::Data(Buffer::Target::Array, data);

        (prg_|"normal").Setup<GLfloat>(n_per_vertex).Enable();
      }

      tcoords.Bind(Buffer::Target::Array);
      {
        std::vector<GLfloat> data;
        GLuint               n_per_vertex(mesh_.TexCoordinates(data));
            
        Buffer::Data(Buffer::Target::Array, data);
            
        (prg_|"tcoords").Setup<GLfloat>(n_per_vertex).Enable();
      }
    }

    void draw()
    {
      using namespace oglplus;
        
      Lazy<Uniform<glm::mat4>>(prg_, "model").Set(xform);

      if (Lazy<Uniform<unsigned>>(prg_, "mtl_id").IsActive()) {
        Lazy<Uniform<unsigned>>(prg_, "mtl_id").Set(material_id);
      }
        
      vao.Bind();
      instructions.Draw(indices);
    }
      
  };

  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace model {

#endif // #if !defined(UKACHULLDCS_08961_APP_COMMON_MODEL_HPP)
