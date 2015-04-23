// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/viewer/main.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <csignal>        // SIG*
#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <platform/oglplus/application.hpp>
#include <support/signal_handler.hpp>

#include <application.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {

  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal
  
  // functions, internal

} // namespace {

int
main(int argc, char const* argv[])
{
  TRACE("main");
  
  support::signal_handler::instance->handler(SIGINT,  &viewer::application::terminate);
  support::signal_handler::instance->handler(SIGTERM, &viewer::application::terminate);

  namespace pa  = platform::application;
  namespace poa = platform::oglplus::application;
  
  return poa::execute<viewer::application>(pa::command_line(argc, argv), std::nothrow);
}
