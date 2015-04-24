// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/glx/window/manager.hpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_GLX_WINDOW_MANAGER_HPP)

#define UKACHULLDCS_08961_PLATFORM_GLX_WINDOW_MANAGER_HPP

// includes, system

// #include <>

// includes, project

#include <platform/window/manager.hpp>

namespace platform {

  namespace glx {

    namespace window {
  
      // types, exported (class, enum, struct, union, typedef)

      class base;

      class DCS08961_PLATFORM_EXPORT manager : private platform::window::manager {

      public:

        using id_type = platform::window::manager::id_type;
        
        static unsigned count();
        static base*    get(id_type);
        
        static std::vector<id_type> const& all();
        
      private:

        friend class base;
        
        static bool  add(id_type, base*);
        static bool  sub(base*);
        static bool  sub(id_type);
        
      };

      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
  
    } // namespace window {
    
  } // namespace glx {
    
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_GLX_WINDOW_MANAGER_HPP)
