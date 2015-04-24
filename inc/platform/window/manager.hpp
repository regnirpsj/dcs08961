// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/window/manager.hpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_WINDOW_MANAGER_HPP)

#define UKACHULLDCS_08961_PLATFORM_WINDOW_MANAGER_HPP

// includes, system

#include <boost/noncopyable.hpp> // boost::noncopyable
#include <iosfwd>                // std::ostream (fwd decl)
#include <unordered_map>         // std::unordered_map<>
#include <vector>                // std::vector<>

// includes, project

#include <platform/export.h>

namespace platform {

  namespace window {
  
    // types, exported (class, enum, struct, union, typedef)

    class base;

    class DCS08961_PLATFORM_EXPORT manager : private boost::noncopyable {
      
    public:

      using id_type = signed long long;
      
      enum class window_type { glut, glx, win32, winrt, };
      
      static unsigned count();
      static unsigned count(window_type);

      static void print_on(std::ostream&);
      
    protected:
      
      static bool                 add(window_type, id_type, base*);
      static bool                 sub(window_type, base*);
      static bool                 sub(window_type, id_type);
      static base*                get(window_type, id_type);
      static std::vector<id_type> all(window_type);
      
    private:

      class window_compare;
      class window_type_hasher { public: size_t operator()(window_type const&) const; };
      
      using window_id_list_type  = std::unordered_map<id_type, base*>;
      using window_type_map_type = std::unordered_map<window_type,
                                                      window_id_list_type,
                                                      window_type_hasher>;
      
      static window_type_map_type window_type_map_;
      
    };
        
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

    DCS08961_PLATFORM_EXPORT  std::ostream& operator<<(std::ostream&, manager::window_type const&);
    
  } // namespace window {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_WINDOW_MANAGER_HPP)
