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
      container::container(context& a, statistics::base& b)
        : base       (a, b),
          stage_list_()
      {
        TRACE("render::base::pass::container::container(dflt)");
      }
      
      /* explicit*/
      container::container(context& a, statistics::base& b,
                           std::initializer_list<base_type*> const& c)
        : base       (a, b),
          stage_list_()
      {
        TRACE("render::base::pass::container::container(std::initializer_list)");

        for (auto s : c) { add(s); }
      }
      
      /* virtual */
      container::~container()
      {
        TRACE("render::base::pass::container::~container");
      }

      bool
      container::empty() const
      {
        TRACE("render::base::pass::container::empty");

        support::simple_lock_guard const slg(stage_list_lock_);
        
        return stage_list_.empty();
      }
      
      unsigned
      container::size() const
      {
        TRACE("render::base::pass::container::size");

        support::simple_lock_guard const slg(stage_list_lock_);
        
        return stage_list_.size();
      }
      
      bool
      container::add(base_type* a)
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
      container::sub(base_type* a)
      {
        TRACE("render::base::pass::container::sub");

        bool result(false);
        
        support::simple_lock_guard const slg(stage_list_lock_);
        {
          result = (1 == stage_list_.erase(a));
        }

        return result;
      }

      void
      container::clear()
      {
        TRACE("render::base::pass::container::clear");

        support::simple_lock_guard const slg(stage_list_lock_);
        
        return stage_list_.clear();
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

      /* virtual */ void
      container::do_execute()
      {
        TRACE("render::base::pass::container::do_execute");

        support::simple_lock_guard const slg(stage_list_lock_);
        
        for (auto p : stage_list_) {
          p->execute();
        }
      }
      
    } // namespace pass {
    
  } // namespace base {
  
} // namespace render {
