// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/pass/container.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "render/pass/container.hpp"

// includes, system

#include <algorithm> // std::find<>
#include <stdexcept> // std::runtime_error

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

  namespace pass {
      
    // variables, exported
  
    // functions, exported

    /* explicit */
    container::container(context::device& a)
      : base       (a),
        stages     (*this, "stages",
                    std::bind(&container::cb_get_stages, this),
                    std::bind(&container::cb_set_stages, this, std::placeholders::_1),
                    std::bind(&container::cb_add_stage,  this, std::placeholders::_1),
                    std::bind(&container::cb_sub_stage,  this, std::placeholders::_1)),
        stage_list_()
    {
      TRACE("render::pass::container::container");

      name = "[render::pass::container]";
    }

    /* virtual */
    container::~container()
    {
      TRACE("render::pass::container::~container");
    }
      
    /* virtual */ void
    container::do_execute(context::swap& a)
    {
      TRACE("render::pass::container::do_execute");

      for (auto& s : stage_list_) {
        s->execute(a);
      }
    }

    /* virtual */ void
    container::do_resize(glm::ivec2 const& a)
    {
      TRACE("render::pass::container::do_resize");

      for (auto& s : stage_list_) {
        s->resize(a);
      }
    }

    container::stage_list_type const&
    container::cb_get_stages() const
    {
      TRACE("render::pass::container::cb_get_stages");

      return stage_list_;
    }

    container::stage_list_type
    container::cb_set_stages(stage_list_type const& a)
    {
      TRACE("render::pass::container::cb_set_stages");

      stage_list_type result(stage_list_);

      stage_list_ = {};
      
      for (auto const& c : a) {
        cb_add_stage(c);
      }
      
      return result;
    }

    bool
    container::cb_add_stage(stage_type const& a)
    {
      TRACE("render::pass::container::cb_add_stage");

      bool result(false);

      if (nullptr != a) {
        if (this != a.get()) {
          stage_list_.push_back(a);
          
          result = true;
        } else {
          throw std::runtime_error("'render::pass::container::cb_add_stage': "
                                   "adding a 'render::pass::container' instance to its own"
                                   "'stages' field is not supported");
        }
      }
      
      return result;
    }

    bool
    container::cb_sub_stage(stage_type const& a)
    {
      TRACE("render::pass::container::cb_sub_stage");

      bool result(false);

      if (nullptr != a) {
        auto const found(std::find(stage_list_.begin(), stage_list_.end(), a));

        if (stage_list_.end() != found) {          
          stage_list_.erase(found);
        
          result = true;
        }
      }
      
      return result;
    }    
    
  } // namespace pass {
  
} // namespace render {
