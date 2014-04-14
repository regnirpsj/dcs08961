// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/light/directional.cpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/object/light/directional.hpp"

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

  scene::object::light::base::rep const dflt_rep(false,
                                                 glm::vec4(0.0, 0.0,  1.0, 0.0),
                                                 glm::vec3(0.0, 0.0, -1.0),
                                                 glm::vec3(0.0, 0.0,  0.0),
                                                 glm::vec3(1.0, 1.0,  1.0),
                                                 glm::vec3(1.0, 1.0,  1.0),
                                                 glm::vec3(1.0, 0.0,  0.0),
                                                 0.0,
                                                 180.0);
  
  // functions, internal

} // namespace {

namespace scene {

  namespace object {

    namespace light {
      
      // variables, exported

      /* static */ directional const directional::dflt_light;
    
      // functions, exported
    
      /* explicit */
      directional::directional()
        : base     (dflt_rep),
          direction(*this, "direction", dflt_rep.direction)
      {   
        TRACE("scene::object::light::directional::directional");
      }
      
      /* virtual */ void
      directional::do_changed(field::base& f)
      {
        TRACE("scene::object::light::directional::do_changed");
        
        if (&f == &direction) { rep_list_[0].direction = direction.get(); }
        
        else {
          base::do_changed(f);
        }
      }

    } // namespace light {
    
  } // namespace object {
  
} // namespace scene {
