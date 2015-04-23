// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  support/signal_handler_win32.cpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "support/signal_handler.hpp"

// includes, system

#include <array>         // std::array<>
#include <csignal>       // ::signal
#include <cstdlib>       // std::abort, std::exit
#include <cstring>       // ::strsignal
#include <iomanip>       // std::boolalpha
#include <iostream>      // std::cerr
#include <unordered_map> // std::unordered_map<>

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  using handler_map_type = std::unordered_map<signed,
                                              support::signal_handler::handler_function_type>;
  
  // variables, internal

  std::array<signed const, 6> const supported_signals = {
    {
      SIGINT, SIGILL, SIGABRT, SIGFPE, SIGSEGV, SIGTERM,
    }
  };
  
  bool             initialized(false);
  handler_map_type handler_map;
  
  // functions, internal

  void
  default_handler(signed signo)
  {
    TRACE("support::signal_handler::<unnamed>::default_handler");

    if (handler_map.end() != handler_map.find(signo)) {
      handler_map[signo](signo);
    } else {
      volatile bool create_core(false);

      switch (signo) {
      case SIGILL:
      case SIGABRT:
      case SIGFPE:
      case SIGSEGV:
        create_core = true;
        break;
        
      case SIGINT:
      case SIGTERM:
        break;
        
      default:
        break;
      }

#if 0
      {
        std::cerr << '\n'
                  << "support::signal_handler::<unnamed>::default_handler: "
                  << "caught signal '" << ::strsignal(signo)            << "'; "
                  << "core:"           << std::boolalpha << create_core << ", "
                  << '\n';
      }
#endif

      if (create_core) {
        std::abort();
      }

      std::exit(EXIT_SUCCESS);
    }
  }

  
  void
  initialize()
  {
    TRACE("support::signal_handler::<unnamed>::initialize");
    
    if (!initialized) {
      for (auto signo : supported_signals) {
        if (0 !=  signo) {
          ::signal(signo, &default_handler);
        }
      }
      
      initialized = true;
    }
  }

} // namespace {

namespace support {
  
  // variables, exported
  
  // functions, exported

  signal_handler::~signal_handler()
  {
    TRACE("support::signal_handler::signal_handler");
  }

  signal_handler::handler_function_type
  signal_handler::handler(signed signo)
  {
    TRACE("support::signal_handler::handler(get)");
    
    return handler_map[signo];
  }

  signal_handler::handler_function_type
  signal_handler::handler(signed signo, handler_function_type new_handler)
  {
    TRACE("support::signal_handler::handler(set)");
    
    handler_function_type old_handler(handler_map[signo]);

    if (new_handler) {
      handler_map[signo] = new_handler;
    }
    
    return old_handler;
  }

  /* explicit */
  signal_handler::signal_handler(boost::restricted)
  {
    TRACE("support::signal_handler::signal_handler");
    
    initialize();
  }

} // namespace support {
