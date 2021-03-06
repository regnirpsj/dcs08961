// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/win32/window/base.cpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/win32/window/base.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<
#include <sstream>        // std::ostringstream
#include <stdexcept>      // std::runtime_error

// includes, project

#include <platform/win32/io.hpp>
#include <platform/win32/utilities.hpp>      // win::[get|set]_long[_ptr]
#include <platform/win32/window/manager.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

#define UKACHULLDCS_USE_TRACE_INTERNAL
#undef UKACHULLDCS_USE_TRACE_INTERNAL

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

  unsigned const window_flags_enable    (WS_CLIPCHILDREN |
                                         WS_CLIPSIBLINGS |
                                         WS_OVERLAPPEDWINDOW |
                                         WS_VISIBLE);
  unsigned const window_flags_disable   (WS_DLGFRAME);
  unsigned const window_flags_ex_enable (WS_EX_CLIENTEDGE);
  unsigned const window_flags_ex_disable(0);
  
  // functions, internal

} // namespace {

namespace platform {

  namespace win32 {

    namespace window {
      
      // variables, exported
  
      // functions, exported

      /* virtual */
      base::~base()
      {
        TRACE("platform::win32::window::base::~base");

        window::manager::sub(this);
      }
      
      HWND const&
      base::handle() const
      {
        TRACE("platform::win32::window::base::handle");

        return hwnd_;
      }
      
      /* virtual */ void
      base::print_on(std::ostream& os) const
      {
        TRACE("platform::win32::window::base::print_on");

        platform::window::base::print_on(os);
        
        using platform::win32::operator<<;
      
        os << "\n,hwnd:" << hwnd_ << ']';
      }
      
      /* explicit */
      base::base(std::string const& a, rect const& b)
        : platform::window::base(a, b),
          hwnd_                 (nullptr),
          flags_                (window_flags_enable    & ~window_flags_disable),
          flags_ex_             (window_flags_ex_enable & ~window_flags_ex_disable),
          register_window_class_()
      {
        TRACE("platform::win32::window::base::base");

        // calculate the size of the client area
        RECT wr = { 0, 0, size->x, size->y };

        ::AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, false);
      
        hwnd_ = ::CreateWindowEx(flags_ex_,                    // window border with a sunken edge
                                 register_window_class::class_name.c_str(), // window-class name
                                 title.get().c_str(),          // caption of window
                                 flags_,                       // window style
                                 position->x,                  // x position
                                 position->y,                  // y position
                                 wr.right - wr.left,           // witdh
                                 wr.bottom - wr.top,           // height
                                 nullptr,                      // handle to parent window
                                 nullptr,                      // handle to menu
                                 ::GetModuleHandle(nullptr),   // application instance
                                 this);                        // window creation data

        if (!hwnd_) {
          std::ostringstream ostr;

          ostr << "Unable to create window '" << title.get() << "'";

          throw std::runtime_error(ostr.str().c_str());
        }

        ::ShowWindow  (hwnd_, SW_SHOWDEFAULT);
        ::UpdateWindow(hwnd_);
        ::ShowCursor  (true);
      
#if defined(UKACHULLDCS_USE_TRACE)
        {
          std::cout << support::trace::prefix() << "platform::win32::window::base::base: "
                    << *this
                    << std::endl;
        }
#endif
      
        window::manager::add(reinterpret_cast<signed>(hwnd_), this);

#if defined(UKACHULLDCS_USE_TRACE_INTERNAL)
        {
          std::cout << "window::manager: ";
          platform::window::manager::print_on(std::cout);
          std::cout << '\n';
        }
#endif
      }
      
      /* virtual */ LRESULT CALLBACK
      base::cb_window_proc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
      {
        TRACE("platform::win32::window::base::cb_window_proc");

#if defined(UKACHULLDCS_USE_TRACE_INTERNAL)
        {
          std::cout << support::trace::prefix() << "platform::win32::window::base::cb_window_proc: "
                    << *this
                    << std::endl;
        }
#endif

        LRESULT result (0);
        bool    handled(false);

        switch (msg) {
        case WM_DESTROY:
          {
            window::manager::sub(this);
            handled = true;
          }
          break;

        case WM_PAINT:
          {
            ::InvalidateRect(hwnd_, nullptr, true);
          
            PAINTSTRUCT ps;
          
            ::BeginPaint(hwnd_, &ps);
            {
              /* nothing to do */
              handled = true;
            }
            ::EndPaint(hwnd_, &ps);
          }
          break;

        default:
          {
            result  = ::DefWindowProc(hWnd, msg, wParam, lParam);
            handled = true;
          }
          break;
        }

        if (!handled) {
          result = ::DefWindowProc(hWnd, msg, wParam, lParam);
        }

        return result;
      }

    } // namespace window {
    
  } // namespace win32 {
  
} // namespace platform {

namespace platform {

  namespace win32 {

    namespace window {
      
      // variables, exported

      /* static */ std::string const base::register_window_class::class_name("platform::win32::window");
      /* static */ unsigned          base::register_window_class::count_    (0);

      // functions, exported
      
      /* explicit */
      base::register_window_class::register_window_class()
        : boost::noncopyable()
      {
        TRACE("platform::win32::window::base::base::register_window_class::register_window_class:"
              + std::to_string(count_));

        if (0 >= count_) {
          WNDCLASSEX wc = { 0 };

          wc.cbSize        = sizeof(WNDCLASSEX);
          wc.cbClsExtra    = 0;
          wc.cbWndExtra    = 0;
          wc.hInstance     = ::GetModuleHandle(nullptr);
          wc.style         = (CS_HREDRAW | CS_VREDRAW);
          wc.lpfnWndProc   = base::cb_window_proc_default;
          wc.hIcon         = ::LoadIcon  (0, IDI_APPLICATION);
          wc.hIconSm       = ::LoadIcon  (0, IDI_APPLICATION);
          wc.hCursor       = ::LoadCursor(0, IDC_ARROW);
          wc.hbrBackground = static_cast<HBRUSH>(::GetStockObject(WHITE_BRUSH));
          wc.lpszMenuName  = nullptr;
          wc.lpszClassName = class_name.c_str();
        
          if (!::RegisterClassEx(&wc)) {
            std::ostringstream ostr;
          
            ostr << "Unable to register window class '" << class_name << "'";
          
            throw std::runtime_error(ostr.str().c_str());
          }
          
          ++count_;
        }
      
        ++count_;
      }
      
      base::register_window_class::~register_window_class()
      {
        TRACE("platform::win32::window::base::base::register_window_class::~register_window_class:"
              + std::to_string(count_-1));

        --count_;

        if (0 >= count_) {
          ::UnregisterClass(class_name.c_str(), ::GetModuleHandle(nullptr));
        }
      }
      
      /* static */ unsigned
      base::register_window_class::count()
      {
        TRACE("platform::win32::window::base::base::register_window_class::count");

        return count_;
      }

    } // namespace window {
    
  } // namespace win32 {
  
} // namespace platform {

namespace platform {

  namespace win32 {

    namespace window {
      
      // variables, exported
  
      // functions, exported

      namespace {
        
#if defined(_WIN64)
        signed user_data_flag(GWLP_USERDATA);
#else
        signed user_data_flag( GWL_USERDATA);
#endif
        
      }
      
      /* static */ LRESULT CALLBACK
      base::cb_window_proc_default(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
      {
        TRACE("platform::win32::window::base::cb_window_proc_default");

#if defined(UKACHULLDCS_USE_TRACE)
        {
          using platform::win32::operator<<;
          
          std::cout << support::trace::prefix()
                    << "platform::win32::window::base::cb_window_proc_default: "
                    << "hWnd:"   << hWnd   << ','
                    << "msg:"    << wm_message_string(msg) << ','
                    << "wParam:" << wParam << ','
                    << "lParam:" << lParam
                    << std::endl;
        }
#endif
        
        switch (msg) {
        case WM_NCCREATE:
        case WM_NCDESTROY:
          {
            base* w(nullptr);

            if (WM_NCCREATE == msg) {
              w  = static_cast<base*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);
            }

            window_long_ptr(hWnd, w, user_data_flag);
            
            return ::DefWindowProc(hWnd, msg, wParam, lParam);
          }
          break;

        default:
          break;
        }

        LRESULT result(0);
        base*   w(window_long_ptr<base>(hWnd, user_data_flag));
        
        if (w) {
          result = w->cb_window_proc(hWnd, msg, wParam, lParam);

#if defined(UKACHULLDCS_USE_TRACE_INTERNAL)
          {
            std::cout << support::trace::prefix()
                      << "platform::win32::window::base::cb_window_proc_default: "
                      << *w
                      << std::endl;
          }
#endif
        } else {
          result = ::DefWindowProc(hWnd, msg, wParam, lParam);
        }
      
        return result;
      }
      
    } // namespace window {
    
  } // namespace win32 {
  
} // namespace platform {
