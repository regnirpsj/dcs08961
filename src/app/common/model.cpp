// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/common/model.cpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "model.hpp"

// includes, system

#include <boost/filesystem.hpp>         // boost::filesystem::path
#include <glm/gtx/transform.hpp>
#include <oglplus/opt/resources.hpp>

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class file {

  public:

    file(std::string const& a)
      : stream_()
    {
      TRACE("model::mesh::<unnamed>::file::file");
        
      namespace bfs = boost::filesystem;

      bfs::path const   p(a);
      std::string const d(p.parent_path().string());
      std::string const f(p.stem().string());
      std::string const e(p.extension().string());

#if defined(UKACHULLDCS_USE_TRACE)
      std::cout << support::trace::prefix() << "model::mesh::<unnamed>::file::file: "
                << "'" << d + "/" + f + e << "'"
                << std::endl;
#endif
        
      oglplus::OpenResourceFile(stream_, d, f, e.c_str());
    }

    std::ifstream& stream()
    {
      TRACE("model::mesh::<unnamed>::file::stream");
      
      return stream_;
    }
    
  private:

    std::ifstream stream_;
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

namespace model {
  
  // variables, exported
  
  // functions, exported

  /* explicit */
  mesh::mesh(std::string const& a, oglplus::Program& b)
    : prg_         (b),
      mesh_        (file(a).stream()),
      vao_         (),
      positions_   (),
      normals_     (),
      tcoords_     (),
      xform_       (),
      mtl_id_      (-1)
  {
    TRACE("model::mesh::mesh");

    using namespace oglplus;

    {
      oglplus::Spheref bsphere;
          
      mesh_.BoundingSphere(bsphere);

      if (!bsphere.Degenerate()) {
        xform_ = (glm::scale    ( glm::vec3(1.0 / bsphere.Diameter())) *
                  glm::translate(-glm::vec3(bsphere.Center().x(),
                                            bsphere.Center().y(),
                                            bsphere.Center().z())));
      }
    }

    vao_.Bind();
        
    positions_.Bind(Buffer::Target::Array);
    {
      std::vector<GLfloat> data;
      GLuint               n_per_vertex(mesh_.Positions(data));
          
      Buffer::Data(Buffer::Target::Array, data);
          
      (prg_|"position").Setup<GLfloat>(n_per_vertex).Enable();
    }
    
    normals_.Bind(Buffer::Target::Array);
    {
      std::vector<GLfloat> data;
      GLuint               n_per_vertex(mesh_.Normals(data));
          
      Buffer::Data(Buffer::Target::Array, data);

      (prg_|"normal").Setup<GLfloat>(n_per_vertex).Enable();
    }
    
    tcoords_.Bind(Buffer::Target::Array);
    {
      std::vector<GLfloat> data;
      GLuint               n_per_vertex(mesh_.TexCoordinates(data));
            
      Buffer::Data(Buffer::Target::Array, data);
            
      (prg_|"tcoords").Setup<GLfloat>(n_per_vertex).Enable();
    }
  }

  glm::mat4 const&
  mesh::xform() const
  {
    TRACE("model::mesh::xform(get)");

    return xform_;
  }
  
  glm::mat4
  mesh::xform(glm::mat4 const& a)
  {
    TRACE("model::mesh::xform(set)");

    glm::mat4 const result(xform_);

    xform_ = a;

    return result;
  }
  
  void
  mesh::draw()
  {
    TRACE("model::mesh::draw");
      
    using namespace oglplus;

    prg_.Use();
    
    if (Uniform<glm::mat4>(prg_, "xform_model").IsActive()) {
      Uniform<glm::mat4>(prg_, "xform_model").Set(xform_);
    }
    
    if (Lazy<Uniform<signed>>(prg_, "mtl_id").IsActive()) {
      Lazy<Uniform<signed>>(prg_, "mtl_id").Set(mtl_id_);
    }
    
    vao_.Bind();
    
    mesh_.Instructions().Draw(mesh_.Indices());
  }

} // namespace model {
