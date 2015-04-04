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

// includes, project

#include <platform/export.h>
//#include <support/printable.hpp>

namespace platform {

  namespace window {
  
    // types, exported (class, enum, struct, union, typedef)

    class base;

    class DCS08961_PLATFORM_EXPORT manager : private boost::noncopyable {

      class window_compare;
      class type_hasher;
      
    public:

      enum class type { glut, win32, winrt, };
      
      static unsigned count();
      static unsigned count(type);

      static std::ostream& print_on(std::ostream&);
      
    protected:
      
      static bool     add  (type, signed, base*);
      static bool     sub  (type, base*);
      static bool     sub  (type, signed);
      static base*    get  (type, signed);
      
    private:

      using window_id_list_type  = std::unordered_map<signed, base*>;
      using window_type_map_type = std::unordered_map<type, window_id_list_type, type_hasher>;
      
      static window_type_map_type window_type_map_;
      
    };
        
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

    std::ostream& operator<<(std::ostream&, manager::type const&);
    
  } // namespace window {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_WINDOW_MANAGER_HPP)
