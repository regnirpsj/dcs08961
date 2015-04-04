// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glut/window/manager.hpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_GLUT_WINDOW_MANAGER_HPP)

#define UKACHULLDCS_08961_PLATFORM_GLUT_WINDOW_MANAGER_HPP

// includes, system

#include <boost/noncopyable.hpp> // boost::noncopyable
#include <unordered_map>         // std::unordered_map<>

// includes, project

#include <platform/export.h>

namespace platform {

  namespace glut {

    namespace window {
  
      // types, exported (class, enum, struct, union, typedef)

      class base;

      class DCS08961_PLATFORM_EXPORT manager : private boost::noncopyable {

      public:

        using window_list_type = std::unordered_map<signed, base*>;
        
        static unsigned count();
        
      private:

        friend class base;
        
        static window_list_type window_list_;

        static bool  add(signed, base*);
        static bool  sub(base*);
        static bool  sub(signed);
        static base* get(signed);
        
      };
        
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
  
    } // namespace window {

  } // namespace glut {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_GLUT_WINDOW_MANAGER_HPP)
