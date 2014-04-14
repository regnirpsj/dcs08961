// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/visitor/dfs.cpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/visitor/dfs.hpp"

// includes, system

#include <string> // std::string

// includes, project

#include <scene/node/group.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>
#if defined(UKACHULLDCS_USE_TRACE) || defined(UKACHULLDCS_ALL_TRACE)
#  include <typeinfo>
#  include <support/type_info.hpp>
#endif

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

  template <typename L>
  inline void
  visit_helper(L const& l, scene::visitor::dfs& v)
  {
    TRACE("<unnamed>::scene::visitor::dfs::visit_helper(" + support::demangle(typeid(l)) + ")");

    for (auto c : l) {
      c->accept(v);
    }
  }
  
} // namespace {

namespace scene {

  namespace visitor {
    
    // variables, exported
  
    // functions, exported

    /* virtual */
    dfs::~dfs()
    {
      TRACE("scene::visitor::dfs::~dfs");
    }

    /* virtual */ void
    dfs::visit(node::group& a)
    {
      TRACE("scene::visitor::dfs::visit(node::group)");

      visit_helper(a.children.get(), *this);
    }

    /* virtual */ void
    dfs::print_on(std::ostream&) const
    {
      TRACE_NEVER("scene::visitor::dfs::print_on");
    }

    /* explicit */
    dfs::dfs()
      : base()
    {
      TRACE("scene::visitor::dfs::dfs");
    }

    /* virtual */ void
    dfs::visit(subject&)
    {
      TRACE("scene::visitor::dfs::visit(subject)");
    }
    
  } // namespace visitor {
  
} // namespace scene {
