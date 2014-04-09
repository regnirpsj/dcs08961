// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/directional_light.cpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/object/directional_light.hpp"

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

    /* static */ directional_light const directional_light::dflt_light("dflt_directional_light");
    
    // functions, exported
    
    /* explicit */
    directional_light::directional_light(std::string const& a, rep const& b)
      : light_source(a, b),
        direction   (*this, "direction",
                     std::bind(&directional_light::cb_get_direction, this),
                     std::bind(&directional_light::cb_set_direction, this, std::placeholders::_1),
                     b.direction)
    {   
      TRACE("scene::object::directional_light::directional_light");
    }
    
    glm::vec3 const&
    directional_light::cb_get_direction() const
    {
      TRACE("scene::object::directional_light::cb_get_direction");
      
      return rep_.direction;
    }
    
    glm::vec3
    directional_light::cb_set_direction(glm::vec3 const& a)
    {
      TRACE("scene::object::directional_light::cb_set_direction");

      glm::vec3 const result(rep_.direction);

      rep_.direction = a;

      return result;
    }
    
  } // namespace object {
  
} // namespace scene {
