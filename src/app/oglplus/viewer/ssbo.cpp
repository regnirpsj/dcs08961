// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/viewer/ssbo.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "ssbo.hpp"

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

namespace buffer {
  
  // variables, exported

  /* static */ slot_manager base::slot_mgr(96);
  
  // functions, exported

  /* explicit */
  slot_manager::slot_manager(unsigned a)
    : slots_(a, false)
  {
    TRACE("buffer::slot_manager::slot_manager");
  }
    
  unsigned
  slot_manager::alloc()
  {
    TRACE("buffer::slot_manager::alloc");
    
    unsigned result(0);
      
    for (unsigned i(0); i < slots_.size(); ++i) {
      if (false == slots_[i]) {
        slots_[i] = true;
        result    = i;

        break;
      }
    }

#if defined(UKACHULLDCS_USE_TRACE)
    std::cout << support::trace::prefix() << "buffer::slot_manager::alloc: "
              << "slot:" << result
              << '\n';
#endif
    
    return result;
  }
    
  void
  slot_manager::release(unsigned a)
  {
    TRACE("buffer::slot_manager::release");

#if defined(UKACHULLDCS_USE_TRACE)
    std::cout << support::trace::prefix() << "buffer::slot_manager::release: "
              << "slot:" << a
              << '\n';
#endif
    
    slots_[a] = false;
  }

  /* explicit */
  base::base(std::string const& a, oglplus::Program& b)
    : name_(a),
      prg_ (b),
      buf_ ()
  {
    TRACE("buffer::base::base");
  }
  
} // namespace buffer {
