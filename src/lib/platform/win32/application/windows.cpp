// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/win32/application/windows.cpp                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/win32/application/windows.hpp"

// includes, system

#include <cstdlib>   // EXIT_*
#include <windows.h> //

// includes, project

#include <platform/win32/window/manager.hpp>
#include <platform/win32/utilities.hpp>

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
      
    namespace application {
      
      // variables, exported
  
      // functions, exported
      
      /* virtual */ signed
      windows::run()
      {
        TRACE("platform::win32::application::windows::run");

        signed result(EXIT_SUCCESS);

        if (!window::manager::count()) {
          result = EXIT_FAILURE;
        } else {
          bool terminate(false);
          
          do {
            TRACE_NEVER("platform::win32::application::windows::run(loop)");
          
            bool dispatch(false);
            MSG  msg;
            
            if (peekmessage_) {
              if (::PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
                dispatch = true;
              } else {
                update();
              }
            } else {
              if (-1 == ::GetMessage(&msg, nullptr, 0, 0)) {
                std::ostringstream ostr;
                
                ostr << "'::GetMessage' error: '" << last_error_message() << "'";
                
                throw std::runtime_error(ostr.str());
              } else {
                dispatch = true;
              }
            }

            if (dispatch) {
              ::TranslateMessage(&msg);
              ::DispatchMessage (&msg);
              
#if 0 // defined(UKACHULLDCS_USE_TRACE)
              {
                std::cout << support::trace::prefix()
                          << "platform::win32::application::windows::run: "
                          << wm_message_string(msg.message)
                          << std::endl;
              }
#endif

              switch (msg.message) {
              case WM_APP:
                {
                  if (WM_QUIT == msg.lParam) {
                    ::PostQuitMessage(unsigned(msg.lParam));
                  }
                }
                break;
                
              case WM_QUIT:
                {
                  terminate = true;
                }
                break;
                
              default:
                break;
              }
            }
          } while (!terminate && (0 != window::manager::count()));
        }

        return result;
      }
      
      /* explicit */
      windows::windows(platform::application::command_line const& a, bool b)
        : base        (a),
          peekmessage_(b)
      {
        TRACE("platform::win32::application::windows::windows");
      }
      
      /* virtual */ void
      windows::update()
      {
        TRACE_NEVER("platform::win32::application::windows::update");
      }
      
    } // namespace application {
    
  } // namespace win32 {
  
} // namespace platform {
