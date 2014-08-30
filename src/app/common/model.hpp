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
#include <utility>

// includes, project

#include <stats.hpp>

namespace model {
  
  // types, exported (class, enum, struct, union, typedef)

  class mesh {

  public:

    typedef std::pair<stats::timer::result, stats::timer::result> stats_result_type;
    
    explicit mesh(std::string const&, oglplus::Program&);

    glm::mat4 const& xform() const;
    glm::mat4        xform(glm::mat4 const&);
    
    void              draw();
    stats_result_type fetch_stats();
    
  private:

    oglplus::Program&        prg_;
    oglplus::shapes::ObjMesh mesh_;
    oglplus::VertexArray     vao_;
    oglplus::Buffer          positions_;
    oglplus::Buffer          normals_;
    oglplus::Buffer          tcoords_;
    glm::mat4                xform_;
    signed                   mtl_id_;
    stats::cpu               cpu_stats_;
    stats::gpu               gpu_stats_;
    
  };

  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace model {

#endif // #if !defined(UKACHULLDCS_08961_APP_COMMON_MODEL_HPP)
