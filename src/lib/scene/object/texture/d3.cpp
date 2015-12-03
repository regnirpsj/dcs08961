// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/texture/d3.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/object/texture/d3.hpp"

// includes, system

//#include <>

// includes, project

#include <object/texture/fill.hpp>
#include <object/texture/load.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace scene {

  namespace object {

    namespace texture {
  
      // variables, exported
  
      // functions, exported

      /* explicit */
      d3::d3(glm::uvec3 const& a, glm::uvec4 const& b)
        : base  (),
          tdata_(gli::FORMAT_RGBA8_UNORM_PACK32, gli::texture3D::texelcoord_type(a.x, a.y, a.z))
      {   
        TRACE("scene::object::d3::d3");
      
        fill(tdata_, glm::u8vec4(b));
      } 
    
      /* explicit */
      d3::d3(std::string const& a)
        : base  (),
          tdata_(load(a))
      {   
        TRACE("scene::object::d3::d3(file)");
      
        if (!empty()) {
          name = a;
        } 
      }
      
      /* virtual */
      d3::~d3()
      {
        TRACE("scene::object::d3::~d3");
      } 
    
      /* virtual */ bool
      d3::empty() const
      {
        TRACE("scene::object::d3::empty");
      
        return tdata_.empty();
      }
      
    } // namespace texture {

  } // namespace object {
  
} // namespace scene {
