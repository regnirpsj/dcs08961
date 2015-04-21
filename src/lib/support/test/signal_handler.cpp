// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  support/test/signal_handler.cpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <csignal> // std::raise
#include <cstdlib> // EXIT_*

// includes, project

#include <support/chrono.hpp>
#include <support/signal_handler.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal

  volatile bool handled_int (false);
  volatile bool handled_term(false);
  
  // functions, internal
  
  void
  interrupt_handler_int(signed)
  {
    TRACE("<unnamed>::interrupt_handler_int");

    handled_int = true;
  }

  void
  interrupt_handler_term(signed)
  {
    TRACE("<unnamed>::interrupt_handler_term");

    handled_term = true;
  }
  
} // namespace {

int
main()
{
  TRACE("main");

  using namespace support;
  
  signal_handler::instance->handler(SIGINT,  interrupt_handler_int);
  signal_handler::instance->handler(SIGTERM, interrupt_handler_term);
  
  sleep(std::chrono::milliseconds(750));

  int result(EXIT_SUCCESS);

  if (std::raise(SIGINT) || !handled_int) {
    result |= EXIT_FAILURE;
  }

  if (std::raise(SIGTERM) || !handled_term) {
    result |= EXIT_FAILURE;
  }
  
  return result;
}
