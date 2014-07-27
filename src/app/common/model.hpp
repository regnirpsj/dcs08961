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
#include <oglplus/all.hpp>
#include <oglplus/shapes/obj_mesh.hpp>

#include <glm/glm.hpp>
#include <oglplus/interop/glm.hpp>

// includes, project

// #include <>

namespace model {
  
  // types, exported (class, enum, struct, union, typedef)

  class mesh {

  public:
    
    explicit mesh(std::string const&, oglplus::Program&);

    glm::mat4 const& xform() const;
    glm::mat4        xform(glm::mat4 const&);
    
    void draw();

  private:

    oglplus::Program&        prg_;
    oglplus::shapes::ObjMesh mesh_;
    oglplus::VertexArray     vao_;
    oglplus::Buffer          positions_;
    oglplus::Buffer          normals_;
    oglplus::Buffer          tcoords_;
    glm::mat4                xform_;
    signed                   mtl_id_;
    
  };

  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace model {

#endif // #if !defined(UKACHULLDCS_08961_APP_COMMON_MODEL_HPP)