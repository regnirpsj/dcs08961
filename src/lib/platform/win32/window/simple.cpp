// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/win32/window/simple.cpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/win32/window/simple.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<
#include <ostream>        // std::ostream
#include <windowsx.h>     // GET_[X|Y]_LPARAM

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

namespace platform {

  namespace win32 {

    namespace window {
      
      // variables, exported
  
      // functions, exported

      /* explicit */
      simple::simple(std::string const& a, rect const& b)
        : base     (a, b),
          focused  (*this, "focused",   false),
          minimized(*this, "minimized", false)
      {
        TRACE("platform::win32::window::simple::simple");
        
        RECT wr;

        ::GetClientRect(hwnd_, &wr);

        size = glm::ivec2(wr.right - wr.left, wr.bottom - wr.top);
      }
      
      /* virtual */
      simple::~simple()
      {
        TRACE("platform::win32::window::simple::~simple");
      }
        
      /* virtual */ LRESULT CALLBACK
      simple::cb_window_proc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
      {
        TRACE("platform::win32::window::simple::cb_window_proc");
        
        LRESULT result (0);
        bool    handled(false);
      
        switch (msg) {
        case WM_KEYDOWN:
          {
            // for virtual key codes see
            // http://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx
            switch (wParam) {
            case VK_ESCAPE:
              {
                ::PostMessage(hWnd, WM_CLOSE, 0, 0);
                handled = true;
              }
              break;
            }
          }
          break;

        case WM_KILLFOCUS:
        case WM_SETFOCUS:
          {
            focused = (WM_SETFOCUS == msg);
            
            handled = focus(focused.get());
          }
          break;

        case WM_PAINT:
          {
            ::InvalidateRect(hwnd_, nullptr, true);

            PAINTSTRUCT ps;

            ::BeginPaint(hwnd_, &ps);
            {
              handled = redraw();
            }
            ::EndPaint(hwnd_, &ps);
          }
          break;

        case WM_SHOWWINDOW:
          {
            handled = redraw();
          }
          break;

        case WM_SIZE:
          {
            if (WM_SIZE == msg) {
              minimized = (SIZE_MINIMIZED == wParam);
            }

            size = glm::ivec2(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
            
            handled = resize(size.get(), minimized.get());
          }
          break;

        default:
          {
            result  = base::cb_window_proc(hWnd, msg, wParam, lParam);
            handled = true;
          }
          break;
        }

        if (!handled) {
          result = ::DefWindowProc(hWnd, msg, wParam, lParam);
        }

        return result;
      }
        
      /* virtual */ bool
      simple::focus(bool)
      {
        TRACE("platform::win32::window::simple::focus");

        return true;
      }

      /* virtual */ bool
      simple::redraw()
      {
        TRACE("platform::win32::window::simple::redraw");

        return true;
      }

      /* virtual */ bool
      simple::resize(glm::ivec2 const& a, bool b)
      {
        TRACE("platform::win32::window::simple::resize");

        return true;
      }
    
    } // namespace window {
    
  } // namespace win32 {
  
} // namespace platform {
