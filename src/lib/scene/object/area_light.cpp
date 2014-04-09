// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/area_light.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/object/area_light.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

//#include <>

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
    
    // variables, exported

    /* static */ area_light const area_light::dflt_light("dflt_area_light");
    
    // functions, exported
    
    /* explicit */
    area_light::area_light(std::string const& a, rep const& b)
      : light_source(a, b),
        spot_light  (a, b),
        size        (*this, "size",
                     std::bind(&area_light::cb_get_size, this),
                     std::bind(&area_light::cb_set_size, this, std::placeholders::_1),
                     b.size),
        samples     (*this, "samples",
                     std::bind(&area_light::cb_get_samples, this),
                     std::bind(&area_light::cb_set_samples, this, std::placeholders::_1),
                     b.samples)
    {
      TRACE("scene::object::area_light::area_light");
    }
    
    glm::vec2 const&
    area_light::cb_get_size() const
    {
      TRACE("scene::object::area_light::cb_get_size");
      
      return rep_.size;
    } 
    
    glm::vec2
    area_light::cb_set_size(glm::vec2 const& a)
    {
      TRACE("scene::object::area_light::cb_set_size");
      
      glm::vec2 const result(rep_.size);

      rep_.size = a;

      return result;
    }
    
    glm::uvec2 const&
    area_light::cb_get_samples() const
    {
      TRACE("scene::object::area_light::cb_get_samples");
      
      return rep_.samples;
    }
    
    glm::uvec2
    area_light::cb_set_samples(glm::uvec2 const& a)
    {
      TRACE("scene::object::area_light::cb_set_samples");

      glm::uvec2 const result(rep_.samples);

      rep_.samples = a;

      return result;
    }
    
  } // namespace object {
  
} // namespace scene {
