// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/application/command_line.cpp                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/application/command_line.hpp"

// includes, system

#include <boost/filesystem.hpp> // boost::filesystem::path
#include <ostream>              // std::ostream
#include <stdexcept>            // std::exception

// includes, project

#include <support/io_utils.hpp>

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

  namespace application {
  
    // variables, exported
  
    // functions, exported

    /* explicit */
    command_line::command_line(int argc, char const* argv[])
      : support::printable(),
        argv0             (((nullptr == argv) || (nullptr == argv[0])) ? "<unspecified>" : argv[0]),
        descriptions      (),
        options           (),
        positionals       (),
        argv_             (),
        already_processed_(false)
    {
      TRACE("platform::application::command_line::command_line");
      
      for (signed i(1); i < argc; ++i) {
        argv_.push_back(argv[i]);
      }
    }

    /* virtual */ void
    command_line::print_on(std::ostream& os) const
    {
      TRACE_NEVER("platform::application::command_line::print_on");

      using support::ostream::operator<<;
      
      os << '[' << argv_ << ',' << ((already_processed_) ? "" : "!") << "processed"<< ']';
    }

    void
    command_line::process(bool force_processing)
    {
      TRACE("platform::application::command_line::process");

      if (!already_processed_ || force_processing) {
        namespace bpo = boost::program_options;

        try {
          options.clear();
          
          bpo::store(bpo::command_line_parser(argv_)
                     .options                (descriptions)
                     .positional             (positionals)
                     .run                    (),
                     options);
          
          bpo::notify(options);

          already_processed_ = true;
        }

        catch (std::exception const& ex) {
          options.clear();
          
          already_processed_ = false;

          throw ex;
        }
      }
    }
    
  } // namespace application {
  
} // namespace platform {
