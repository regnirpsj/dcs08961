// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
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

//#include <>

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

      /* explicit*/
      container::container()
        : base       (),
          stage_list_()
      {
        TRACE("render::base::pass::container::container(dflt)");
      }
      
      /* explicit*/
      container::container(std::initializer_list<base*> const& a)
        : base       (),
          stage_list_()
      {
        TRACE("render::base::pass::container::container(std::initializer_list)");

        for (auto s : a) { add(s); }
      }
      
      /* virtual */
      container::~container()
      {
        TRACE("render::base::pass::container::~container");
      }

      unsigned
      container::size() const
      {
        TRACE("render::base::pass::container::size");

        support::simple_lock_guard const slg(stage_list_lock_);
        
        return stage_list_.size();
      }
      
      bool
      container::add(base* a)
      {
        TRACE("render::base::pass::container::add");

        bool result(false);
        
        support::simple_lock_guard const slg(stage_list_lock_);
        {
          result = stage_list_.insert(a).second;
        }

        return result;
      }
      
      bool
      container::sub(base* a)
      {
        TRACE("render::base::pass::container::sub");

        bool result(false);
        
        support::simple_lock_guard const slg(stage_list_lock_);
        {
          result = (1 == stage_list_.erase(a));
        }

        return result;
      }
        
      /* virtual */ void
      container::execute()
      {
        TRACE("render::base::pass::container::execute");

        support::simple_lock_guard const slg(stage_list_lock_);
        
        for (auto p : stage_list_) {
          p->execute();
        }
      }
      
      /* virtual */ void
      container::print_on(std::ostream& os) const
      {
        TRACE_NEVER("render::base::pass::container::print_on");

        base::print_on(os);

        support::simple_lock_guard const slg(stage_list_lock_);
        {
          os << "\b,s:" << stage_list_.size() << ']';
        }
      }
      
    } // namespace pass {
    
  } // namespace base {
  
} // namespace render {
