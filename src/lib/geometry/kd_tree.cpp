// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  geometry/kd_tree.cpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "geometry/kd_tree.hpp"

// includes, system

#include <glm/glm.hpp>
#include <glm/gtx/io.hpp>

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

  using value_type = glm::vec4;
  
  geometry::bintree<value_type>      btree;
  geometry::quadtree<value_type>     qtree;
  geometry::octree<value_type>       otree;
  geometry::hexadecatree<value_type> hdtree;
  
  // functions, internal

} // namespace {

namespace geometry {
  
  // variables, exported
  
  // functions, exported
  
} // namespace geometry {
