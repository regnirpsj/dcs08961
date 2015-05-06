// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/pass/container.cpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/base/pass/container.hpp"

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

namespace render {

  namespace base {

    namespace pass {
      
      // variables, exported
  
      // functions, exported

      /* explicit */
      container::container(context& a)
        : base  (a),
          stages(*this, "stages")
      {
        TRACE("render::base::pass::container::container");

        name = "[render::base::pass::container]";
      }

      /* virtual */
      container::~container()
      {
        TRACE("render::base::pass::container::~container");
      }
      
      /* virtual */ void
      container::do_execute()
      {
        TRACE("render::base::pass::container::do_execute");

        for (auto s : stages.get()) {
          s->execute();
        }
      }

      /* virtual */ void
      container::do_resize(glm::ivec2 const& a)
      {
        TRACE("render::base::pass::container::do_resize");

        for (auto s : stages.get()) {
          s->resize(a);
        }
      }
      
    } // namespace pass {
    
  } // namespace base {
  
} // namespace render {
