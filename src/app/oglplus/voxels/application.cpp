// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/voxels/application.cpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "application.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <support/signal_handler.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace voxels {
  
  // variables, exported
  
  // functions, exported
  
  /* static */ void
  application::terminate(signed signo)
  {
    TRACE("voxels::application::terminate");
      
    inherited::terminate = true;

    std::cout << '\n'
              << "terminating by user request ('"
              << support::signal_name(signo) << "' " << signo << ")"
              << '\n';
  }

  /* explicit */
  application::application(command_line const& a)
    : inherited   (a),
      window_     (nullptr)
  {
    TRACE("voxels::application::application");
  }

  /* virtual */
  application::~application()
  {
    TRACE("voxels::application::~application");
  }
    
  /* virtual */ void
  application::process_command_line()
  {
    TRACE("voxels::application::process_command_line");

    inherited::process_command_line();

    window_.reset(new window(command_line_, rect(50, 50, 1920, 1080)));
  }

} // namespace voxels {
