// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/group.cpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/node/group.hpp"

// includes, system

#include <algorithm> // std::find<>

// includes, project

#include <scene/visitor/base.hpp>

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

  namespace node {
    
    // variables, exported
    
    // functions, exported

    /* explicit */
    group::group(std::string const& a)
      : base          (a),
        children      (*this, "children",
                       std::bind(&group::cb_get_children, this),
                       std::bind(&group::cb_set_children, this, std::placeholders::_1),
                       std::bind(&group::cb_add_child,    this, std::placeholders::_1),
                       std::bind(&group::cb_sub_child,    this, std::placeholders::_1)),
        children_list_()
    {
      TRACE("scene::node::group::group");
    }

    /* virtual */
    group::~group()
    {
      TRACE("scene::node::group::~group");

#if 1
      while (!children_list_.empty()) {
        cb_sub_child(*(children_list_.rbegin()));
      }
#else
      { // alternative way: pro:consistent, con:wasted return value
        cb_set_children({});
      }
#endif
    }
    
    /* virtual */ void
    group::accept(visitor::base& v)
    {
      TRACE("scene::node::group::accept");

      v.visit(*this);
    }

    group::children_list_type const&
    group::cb_get_children() const
    {
      TRACE("scene::node::group::cb_get_children");

      return children_list_;
    }

    group::children_list_type
    group::cb_set_children(children_list_type const& a)
    {
      TRACE("scene::node::group::cb_set_children");

      children_list_type result(children_list_);

      for (auto const& c : result) {
        cb_sub_child(c);
      }
      
      for (auto const& c : a) {
        cb_add_child(c);
      }
      
      return result;
    }

    bool
    group::cb_add_child(children_type const& a)
    {
      TRACE("scene::node::group::cb_add_child");

      bool result(false);

      if (nullptr != a) {
        auto const found(std::find(children_list_.begin(), children_list_.end(), a));

        if (children_list_.end() == found) {
          children_list_.push_back(a);
          {
            group* p(dynamic_cast<group*>(a->parent_));
          
            if (nullptr != p) {
              p->cb_sub_child(a);
            }
          }
          a->parent_ = this;

          invalidate_bounds();
        
          result = true;
        }
      }
      
      return result;
    }

    bool
    group::cb_sub_child(children_type const& a)
    {
      TRACE("scene::node::group::cb_sub_child");

      bool result(false);

      if (nullptr != a) {
        auto const found(std::find(children_list_.begin(), children_list_.end(), a));

        if (children_list_.end() != found) {
          a->parent_ = nullptr;
          
          children_list_.erase(found);

          invalidate_bounds();
        
          result = true;
        }
      }
      
      return result;
    }
    
  } // namespace node {
  
} // namespace scene {
