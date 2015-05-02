// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/win32/window/manager.cpp                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/win32/window/manager.hpp"

// includes, system

#include <glm/gtx/io.hpp>

// includes, project

#include <platform/win32/window/base.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  using display_list_type = platform::win32::window::manager::display_list_type;
  using monitor_list_type = platform::win32::window::manager::monitor_list_type;
  
  // variables, internal
  
  // functions, internal

  display_list_type
  enumerate_displays()
  {
    TRACE("platform::win32::window::<unnamed>::enumerate_displays");

    using namespace platform::win32::window;
    
    manager::display_list_type result;
    DISPLAY_DEVICE             dd;

    memset(&dd, 0, sizeof(DISPLAY_DEVICE));
    
    dd.cb = sizeof(DISPLAY_DEVICE);

    unsigned const flags(0);
    unsigned       i    (0);

    while (::EnumDisplayDevices(nullptr, i, &dd, flags)) {
      if (DISPLAY_DEVICE_ACTIVE & dd.StateFlags) {
        manager::display_devmode_pair_type ddev_pair(std::make_pair(dd,
                                                                    manager::devmode_list_type()));
        DEVMODE                            ddmode;

        ddmode.dmSize        = sizeof(DEVMODE);
        ddmode.dmDriverExtra = 0;

        // idx0: current
        if (::EnumDisplaySettingsEx(ddev_pair.first.DeviceName, ENUM_CURRENT_SETTINGS, &ddmode,
                                    flags)) {
          ddev_pair.second.push_back(ddmode);
        }
        
        unsigned const flags(0);
        unsigned       j(0);

        // idx1-n:supported
        while (::EnumDisplaySettingsEx(ddev_pair.first.DeviceName, j, &ddmode, flags)) {
          if (32 <= ddmode.dmBitsPerPel) {
            ddev_pair.second.push_back(ddmode);
          }
          
          ++j;
        }

        // idx:n+1: registry
        if (::EnumDisplaySettingsEx(ddev_pair.first.DeviceName, ENUM_REGISTRY_SETTINGS, &ddmode,
                                    flags)) {
          ddev_pair.second.push_back(ddmode);
        }
        
        result.push_back(ddev_pair);
      }
      
      ++i;
    }

    return result;
  }

  BOOL CALLBACK
  enumerate_monitor_cb(HMONITOR hMon, HDC /* hdcMon */, LPRECT /* lprcMon */, LPARAM dwData)
  {
    TRACE("platform::win32::window::<unnamed>::enumerate_monitor_cb");

    MONITORINFOEX minfo;
    
    minfo.cbSize = sizeof(MONITORINFOEX);

    BOOL const result(::GetMonitorInfo(hMon, &minfo));

    if (result) {
      using namespace platform::win32::window;
      
      auto monitor_list(reinterpret_cast<manager::monitor_list_type*>(dwData));

      if (monitor_list) {
        monitor_list->push_back(minfo);
      }
    }
    
    return result;
  }
  
  monitor_list_type
  enumerate_monitors()
  {
    TRACE("platform::win32::window::<unnamed>::enumerate_monitors");

    using namespace platform::win32::window;

    manager::monitor_list_type result;

    if (!::EnumDisplayMonitors(nullptr, nullptr, enumerate_monitor_cb,
                               reinterpret_cast<LPARAM>(&result)))
      result = manager::monitor_list_type();
    
    return result;
  }

} // namespace {

namespace platform {

  namespace win32 {

    namespace window {
  
      // variables, exported

      /* static */ manager::display_list_type manager::display_list_;
      /* static */ manager::monitor_list_type manager::monitor_list_;
      
      // functions, exported

      /* static */ unsigned
      manager::count()
      {
        TRACE("platform::win32::window::manager::count");

        return platform::window::manager::count(window_type::win32);
      }

      /* static */ base*
      manager::get(signed a)
      {
        TRACE_NEVER("platform::win32::window::manager::get");

        return static_cast<base*>(platform::window::manager::get(window_type::win32, a));
      }

      /* static */ std::vector<manager::id_type> const&
      manager::all()
      {
        TRACE_NEVER("platform::win32::window::manager::all");

        return platform::window::manager::all(window_type::win32);
      }

      /* static */ manager::display_list_type const&
      manager::display_list(bool a)
      {
        TRACE("platform::win32::window::manager::display_list");
      
        if (a || display_list_.empty()) {
          display_list_ = enumerate_displays();
        }
      
        return display_list_;
      }

      /* static */ manager::monitor_list_type const&
      manager::monitor_list(bool a)
      {
        TRACE("platform::win32::window::manager::monitor_list");
      
        if (a || monitor_list_.empty()) {
          monitor_list_ = enumerate_monitors();
        }
      
        return monitor_list_;
      }

      /* static */ bool
      manager::add(signed a, base* b)
      {
        TRACE("platform::win32::window::manager::add");

        return platform::window::manager::add(window_type::win32, a, b);
      }

      /* static */ bool
      manager::sub(base* a)
      {
        TRACE("platform::win32::window::manager::sub(base*)");

        return platform::window::manager::sub(window_type::win32, a);
      }

      /* static */ bool
      manager::sub(signed a)
      {
        TRACE("platform::win32::window::manager::sub(signed)");

        return platform::window::manager::sub(window_type::win32, a);
      }
  
    } // namespace window {

  } // namespace win32 {
  
} // namespace platform {
