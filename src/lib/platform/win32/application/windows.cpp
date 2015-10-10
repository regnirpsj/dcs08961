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

#include <csignal>   //
#include <windows.h> //

// includes, project

#include <support/signal_handler.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

  signed msg_loop_thr_id(-1);
  
  // functions, internal

  void
  signal_handler(signed signo)
  {
    TRACE("<unnamed>::signal_handler(" + std::to_string(signo) + ")");
    
    signed exit_code(EXIT_FAILURE);
    
    switch (signo) {
    case SIGINT:
    case SIGTERM:
      exit_code = EXIT_SUCCESS;
      break;
    default:
      break;
    }
    if (-1 != msg_loop_thr_id) {
      ::PostThreadMessage(msg_loop_thr_id,
			  WM_APP,    // msg.message
			  exit_code, // msg.wParam
			  WM_QUIT);  // msg.lParam
    }
  }
  
} // namespace {

namespace platform {

  namespace win32 {
      
    namespace application {
      
      // variables, exported
  
      // functions, exported
      
      /* virtual */ signed
      windows::run()
      {
	TRACE("platform::application::win32::windows::run");

	MSG  msg;
	bool done(false);

	msg_loop_thr_id = ::GetCurrentThreadId();
	
	support::signal_handler::instance->handler(SIGINT,  signal_handler);
	support::signal_handler::instance->handler(SIGTERM, signal_handler);
	
	while (!done) {
	  TRACE_NEVER("platform::application::win32::windows::run(loop)");
	  
	  bool dispatch(false);
	  
	  if (peekmessage_) {
	    if (::PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
	      dispatch = true;
	    } else {
	      update();
	    }
	  } else {
	    if (-1 == ::GetMessage(&msg, nullptr, 0, 0)) {
	      throw std::runtime_error("'::GetMessage' problem");
	    } else {
	      dispatch = true;
	    }
	  }

	  if (dispatch) {
	    ::TranslateMessage(&msg);
	    ::DispatchMessage (&msg);
	  }

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
	      done = true;
	    }
	    break;
	    
	  default:
	    break;
	  }	  
	}

	return 0;
      }

      /* explicit */
      windows::windows(platform::application::command_line const& a, bool b)
	: base        (a),
	  peekmessage_(b)
      {
	TRACE("platform::application::win32::windows::windows");
      }
      
      /* virtual */ void
      windows::update()
      {
	TRACE_NEVER("platform::application::win32::windows::update");
      }

    } // namespace application {
    
  } // namespace win32 {
  
} // namespace platform {
