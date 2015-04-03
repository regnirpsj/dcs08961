// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glut/window/manager.cpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/glut/window/manager.hpp"

// includes, system

#include <algorithm> // std::find<>

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class window_compare {

  public:

    explicit window_compare(signed a, platform::glut::window::base const* b)
      : id_  (a),
        inst_(b)
    {}

    bool operator()(platform::glut::window::manager::window_list_type::value_type const& a)
    {
      bool result(false);

      if        ((-1 != id_) && inst_) {
        result = (a.first == id_) && (a.second == inst_);
      } else if (-1 != id_) {
        result = (a.first == id_);
      } else if (nullptr != inst_) {
        result = (a.second == inst_);
      }
      
      return result;
    }
    
  private:

    signed const                        id_;
    platform::glut::window::base const* inst_;
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

namespace platform {

  namespace glut {

    namespace window {
  
      // variables, exported

      /* static */ manager::window_list_type manager::window_list_;
  
      // functions, exported

      /* static */ unsigned
      manager::count()
      {
        TRACE("platform::glut::window::manager::count");

        return window_list_.size();
      }
      
      /* static */ bool
      manager::add(signed a, base* b)
      {
        TRACE("platform::glut::window::manager::add");

        return window_list_.insert(std::make_pair(a, b)).second;
      }

      /* static */ bool
      manager::sub(base* a)
      {
        TRACE("platform::glut::window::manager::sub(base*)");

        bool result(false);
        auto found (std::find_if(window_list_.begin(), window_list_.end(),
                                 window_compare(-1, a)));

        if (window_list_.end() != found) {
          window_list_.erase(found);

          result = true;
        }
      
        return result;
      }

      /* static */ bool
      manager::sub(signed a)
      {
        TRACE("platform::glut::window::manager::sub(signed)");

        bool result(false);
        auto found (std::find_if(window_list_.begin(), window_list_.end(),
                                 window_compare(a, nullptr)));

        if (window_list_.end() != found) {
          window_list_.erase(found);

          result = true;
        }
      
        return result;
      }

      /* static */ base*
      manager::get(signed a)
      {
        TRACE_NEVER("platform::glut::window::manager::get");

        base* result(nullptr);
        auto  found(std::find_if(window_list_.begin(), window_list_.end(),
                                 window_compare(a, nullptr)));

        if (window_list_.end() != found) {
          result = found->second;
        }

        return result;
      }
  
    } // namespace window {

  } // namespace glut {
  
} // namespace platform {
