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

//#include <>

// includes, project

#include <platform/window/manager.hpp>

namespace platform {

  namespace glut {

    namespace window {
  
      // types, exported (class, enum, struct, union, typedef)

      class base;

      class DCS08961_PLATFORM_EXPORT manager : private platform::window::manager {

      public:
        
        static unsigned count();
        static base*    get(signed);
        
        static std::vector<signed> all();
        
      private:

        friend class base;
        
        static bool  add(signed, base*);
        static bool  sub(base*);
        static bool  sub(signed);
        
      };
        
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
  
    } // namespace window {

  } // namespace glut {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_GLUT_WINDOW_MANAGER_HPP)
