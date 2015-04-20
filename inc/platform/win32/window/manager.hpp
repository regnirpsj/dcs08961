// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/win32/window/manager.hpp                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_WIN32_WINDOW_MANAGER_HPP)

#define UKACHULLDCS_08961_PLATFORM_WIN32_WINDOW_MANAGER_HPP

// includes, system

#include <boost/noncopyable.hpp> // boost::noncopyable
#include <unordered_set>         // std::unordered_set<>
#include <vector>                // std::vector<>
#include <windows.h>             // win32 stuff

// includes, project

#include <platform/window/manager.hpp>

namespace platform {

  namespace win32 {

    namespace window {
  
      // types, exported (class, enum, struct, union, typedef)

      class base;

      class DCS08961_PLATFORM_EXPORT manager : private platform::window::manager {

      public:

        using devmode_list_type         = std::vector<DEVMODE>;
        using display_devmode_pair_type = std::pair<DISPLAY_DEVICE, devmode_list_type>;
        using display_list_type         = std::vector<display_devmode_pair_type>;
        using monitor_list_type         = std::vector<MONITORINFOEX>;
        
        static unsigned count();
        static base*    get(signed);
        
        static std::vector<signed> all();

        static display_list_type const& display_list(bool /* re-scan */ = false);
        static monitor_list_type const& monitor_list(bool /* re-scan */ = false);

      
      private:

        friend class base;

        static display_list_type display_list_;
        static monitor_list_type monitor_list_;
      
        static bool  add(signed, base*);
        static bool  sub(base*);
        static bool  sub(signed);
        
      };
        
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
  
    } // namespace window {

  } // namespace win32 {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_WIN32_WINDOW_MANAGER_HPP)
