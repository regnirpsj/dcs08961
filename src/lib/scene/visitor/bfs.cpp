// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/visitor/bfs.cpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "scene/visitor/bfs.hpp"

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

  template <typename L, typename T, typename Q>
  inline void
  visit_helper(L const& l, T const*, Q& q, scene::visitor::bfs& v)
  {
    TRACE("<unnamed>::scene::visitor::bfs::visit_helper(" + support::demangle(typeid(l)) + ")");

    Q lq;

    for (auto const& c : l) {
      if (nullptr == dynamic_cast<T const*>(c.get())) {
        q.push(c);
      } else {
        lq.push(c);
      }
    }

    while (!lq.empty()) {
      lq.front()->accept(v);
      lq.pop();
    }
  }
  
} // namespace {

namespace scene {

  namespace visitor {
    
    // variables, exported
  
    // functions, exported

    /* virtual */
    bfs::~bfs()
    {
      TRACE("scene::visitor::bfs::~bfs");

      flush();
    }
    
    /* virtual */ void
    bfs::visit(node::group& a)
    {
      TRACE("scene::visitor::bfs::visit(node::group)");

      visit_helper(a.children.get(), &a, node_queue_, *this);
    }

    /* virtual */ void
    bfs::print_on(std::ostream& os) const
    {
      TRACE_NEVER("scene::visitor::bfs::print_on");

      os << '[' << "'scene::visitor::bfs::print_on' not yet implemented" << ']';
    }

    /* explicit */
    bfs::bfs()
      : base       (),
        node_queue_()
    {
      TRACE("scene::visitor::bfs::bfs");
    }

    /* virtual */ void
    bfs::flush()
    {
      TRACE("scene::visitor::bfs::flush");
      
      while (!node_queue_.empty()) {
        node_queue_.front()->accept(*this);
        node_queue_.pop();
      }
    }

    /* virtual */ void
    bfs::visit(subject&)
    {
      TRACE("scene::visitor::bfs::visit(subject)");
    }
    
  } // namespace visitor {
  
} // namespace scene {
