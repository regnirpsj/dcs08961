// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/object/texture/base.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/object/texture/base.hpp"

// includes, system

#include <stdexcept> // std::logic_error

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

    namespace texture {
      
      // variables, exported

      /* static */ glm::uvec3 const base::default_size (1, 1, 1);
      /* static */ glm::uvec4 const base::default_color(1, 1, 1, 1);
    
      // functions, exported

      /* virtual */
      base::~base()
      {
        TRACE("scene::object::base::~base");
      }
    
      /* explicit */
      base::base()
        : object::base()
      {
        TRACE("scene::object::base::base");
      }

      /* virtual */ bool
      base::empty() const
      {
        TRACE("scene::object::base::empty");

        throw std::logic_error("pure virtual function 'scene::object::base::empty' called");

        return false;
      }

    } // namespace texture {
    
  } // namespace object {
  
} // namespace scene {
