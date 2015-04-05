// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/window/manager.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/window/manager.hpp"

// includes, system

#include <algorithm> // std::find<>
#include <ostream>   // std::ostream

// includes, project

#include <support/io_utils.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal
  
  // functions, internal

} // namespace {

namespace platform {

  namespace window {
    
    class manager::window_compare {

    public:

      explicit window_compare(signed a, base const* b)
        : id_  (a),
          inst_(b)
      {}

      bool operator()(window_id_list_type::value_type const& a) const
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

      signed const id_;
      base const*  inst_;
    
    };

    class manager::type_hasher {

    public:

      size_t operator()(type const& a) const
      {
        return static_cast<size_t>(a);
      }
      
    };
    
  } // namespace window {
  
} // namespace platform {

namespace platform {

  namespace window {
  
    // variables, exported

    /* static */ manager::window_type_map_type manager::window_type_map_;
  
    // functions, exported

    /* static */ unsigned
    manager::count()
    {
      TRACE("platform::window::manager::count");

      unsigned result(0);

      for (auto m : window_type_map_) {
        result += m.second.size();
      }
      
      return result;
    }
    
    /* static */ unsigned
    manager::count(type a)
    {
      TRACE("platform::window::manager::count(type)");

      return window_type_map_[a].size();
    }

    /* static */ void
    manager::print_on(std::ostream& os)
    {
      TRACE_NEVER("platform::window::manager::print_on");

      os << '[';
      
      for (auto m : window_type_map_) {
        using support::ostream::operator<<;
        
        os << m.first << ':' << m.second;
      }
      
      os << ']';
    }
    
    /* static */ bool
    manager::add(type a, signed b, base* c)
    {
      TRACE("platform::window::manager::add");

      return window_type_map_[a].insert(std::make_pair(b, c)).second;
    }

    /* static */ bool
    manager::sub(type a, base* b)
    {
      TRACE("platform::window::manager::sub(base*)");

      bool result(false);
      auto found (std::find_if(window_type_map_[a].begin(),
                               window_type_map_[a].end(),
                               window_compare(-1, b)));

      if (window_type_map_[a].end() != found) {
        window_type_map_[a].erase(found);

        result = true;
      }
      
      return result;
    }

    /* static */ bool
    manager::sub(type a, signed b)
    {
      TRACE("platform::window::manager::sub(signed)");

      bool result(false);
      auto found (std::find_if(window_type_map_[a].begin(),
                               window_type_map_[a].end(),
                               window_compare(b, nullptr)));

      if (window_type_map_[a].end() != found) {
        window_type_map_[a].erase(found);

        result = true;
      }
      
      return result;
    }

    /* static */ base*
    manager::get(type a, signed b)
    {
      TRACE_NEVER("platform::window::manager::get");

      base* result(nullptr);
      auto  found(std::find_if(window_type_map_[a].begin(),
                               window_type_map_[a].end(),
                               window_compare(b, nullptr)));

      if (window_type_map_[a].end() != found) {
        result = found->second;
      }

      return result;
    }

    /* static */ std::vector<signed>
    manager::all(type a)
    {
      TRACE_NEVER("platform::window::manager::all");

      std::vector<signed> result;
      
      for (auto w : window_type_map_[a]) {
        result.push_back(w.first);
      }
      
      return result;
    }
    
    std::ostream&
    operator<<(std::ostream& os, manager::type const& a)
    {
      TRACE_NEVER("platform::window::operator<<(manager::type)");
      
      std::ostream::sentry const cerberus(os);

      if (cerberus) {
        switch (a) {
        case manager::type::glut:  os << "GLUT";  break;
        case manager::type::win32: os << "Win32"; break;
        case manager::type::winrt: os << "WinRT"; break;
        }
      }

      return os;
    }
    
  } // namespace window {
  
} // namespace platform {
