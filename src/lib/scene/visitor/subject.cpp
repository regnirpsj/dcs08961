// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/visitor/subject.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/visitor/subject.hpp"

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

  namespace visitor {
    
    // variables, exported
  
    // functions, exported

    /* virtual */
    subject::~subject()
    {
      TRACE("scene::visitor::subject::~subject");
    }

    /* virtual */ void
    subject::accept(visitor::base&)
    {
      TRACE("scene::visitor::subject::accept");

      throw std::logic_error("pure virtual function 'scene::visitor::subject::accept' called");
    }
    
  } // namespace visitor {
  
} // namespace scene {
