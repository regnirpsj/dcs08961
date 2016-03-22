// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/voxels/model.hpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_APP_OGLPLUS_VOXELS_MODEL_HPP)

#define UKACHULLDCS_08961_APP_OGLPLUS_VOXELS_MODEL_HPP

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

  class voxel_space {

  public:

    using stats_result_type = std::pair<stats::timer::result, stats::timer::result>;
    
    explicit voxel_space(glm::uvec3 const&);

    glm::uvec3 size() const;
    
    void              draw();
    stats_result_type fetch_stats();
    
  private:

    glm::uvec3 const size_;
    oglplus::Context ctx_;
    stats::cpu       cpu_stats_;
    stats::gpu       gpu_stats_;
    
  };
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace model {

#endif // #if !defined(UKACHULLDCS_08961_APP_OGLPLUS_VOXELS_MODEL_HPP)
