// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/voxels/model.cpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "model.hpp"

// includes, system

#include <glm/gtx/transform.hpp>
#include <oglplus/opt/resources.hpp>

// includes, project

// #include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal

  std::string const voxel_space_name("model::voxel_space");
  
  // functions, internal

} // namespace {

namespace model {
  
  // variables, exported
  
  // functions, exported

  /* explicit */
  voxel_space::voxel_space(glm::uvec3 const& a)
    : size_(a),
      ctx_ (),
      cpu_stats_(voxel_space_name + ":cpu"),
      gpu_stats_(voxel_space_name + ":gpu")
  {
    TRACE("model::voxel_space::voxel_space");
  }

  glm::uvec3
  voxel_space::size() const
  {
    TRACE("model::voxel_space::size");
    
    return size_;
  }
  
  void
  voxel_space::draw()
  {
    TRACE("model::voxel_space::draw");
  }

  voxel_space::stats_result_type
  voxel_space::fetch_stats()
  {
    TRACE("model::voxel_space::fetch_stats");

    return std::make_pair(cpu_stats_.fetch(), gpu_stats_.fetch());
  }

} // namespace model {
