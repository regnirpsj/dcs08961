// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/viewer/application.cpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "application.hpp"

// includes, system

//#include <>

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

namespace viewer {
  
  // variables, exported
  
  // functions, exported
  
  /* static */ void
  application::terminate(::siginfo_t* a)
  {
    TRACE("viewer::application::terminate");
      
    inherited::terminate = true;

    std::cout << '\n'
              << "terminating by user request ('"
              << ::strsignal(a->si_signo) << "' " << a->si_signo << ")"
              << '\n';
  }
    
  /* explicit */
  application::application(command_line const& a)
    : inherited   (a),
      input_files_(),
      layout_     ("1x1xN"),
      window_     (nullptr)
  {
    TRACE("viewer::application::application");

    {
      namespace bpo = boost::program_options;

      bpo::options_description od("Application Options",
                                  command_line::line_length,
                                  command_line::text_length);

      od.add_options()
        ("layout,l",
         bpo::value<std::string>(&layout_)->default_value(layout_),
         "layout pattern for input file(s)\n"
         "format: XxYxZ with X,Y,Z in [0..N] (e.g., line in Z: 1x1xN, cube: 3x3x3)");
        
      od.add_options()
        ("file,f",
         bpo::value(&input_files_)->composing(),
         "input file(s)\n"
         "note: positional arguments are accumulated as input files");

      command_line_.descriptions.add(od);
      command_line_.positionals .add("file", -1);
    }
  }

  /* virtual */
  application::~application()
  {
    TRACE("viewer::application::~application");
  }
    
  /* virtual */ void
  application::process_command_line()
  {
    TRACE("viewer::application::process_command_line");

    inherited::process_command_line();

    window_.reset(new window(command_line_, rect(50, 50, 1440, 900),
                             layout_, input_files_));
  }

} // namespace viewer {
