// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/application/base.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/application/base.hpp"

// includes, system

#include <boost/filesystem.hpp> // boost::filesystem::path
#include <cstdlib>              // EXIT_SUCCESS
#include <ostream>              // std::ostream
#include <stdexcept>            // std::exception
#include <system_error>         // std::system_error

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

  namespace application {
  
    // variables, exported
  
    // functions, exported

    /* virtual */ signed
    base::run()
    {
      TRACE("platform::application::base::run");

      throw std::logic_error("pure virtual function 'platform::application::base::run' called");

      return EXIT_FAILURE;
    }

    /* virtual */ void
    base::process_command_line()
    {
      bool   print_help(false);
      signed exit_value(EXIT_SUCCESS);
      
      try {
        command_line_.process();
      }

      catch (std::exception const& ex) {
        std::cerr << '\n' << "command-line problem: " << ex.what() << std::endl;
        
        print_help = true;
        exit_value = EXIT_FAILURE;
      }
      
      if (command_line_.options.count("help") || print_help) {
        std::string const base_name(boost::filesystem::path(command_line_.argv0)
                                    .filename().string());
        
        std::cerr << "\nusage: " << base_name << " [OPTIONS] [POSITIONALS ...]\n"
                  << command_line_.descriptions
                  << std::endl;
        
        // std::exit(exit_value);
        throw std::system_error(ECANCELED, std::generic_category(),
                                "exit value:" + std::to_string(exit_value));
      }
    }
    
    /* virtual */ void
    base::print_on(std::ostream& os) const
    {
      TRACE_NEVER("platform::application::base::print_on");

      os << '['
         << "@0x"      << this << ','
         << "verbose:" << verbose_level_
         << ']';
    }
    
    /* explicit */
    base::base(command_line const& a)
      : boost::noncopyable(),
        support::printable(),
        command_line_     (a),
        verbose_level_    (0)
    {
      TRACE("platform::application::base::application");

      namespace bpo = boost::program_options;

      bpo::options_description global("Global Options");

      global.add_options()
        ("help,h", "display command-line help and exit");

      global.add_options()
        ("verbose,v",
         bpo::value<unsigned>(&verbose_level_)
         ->implicit_value(verbose_level_ + 1)
         ->default_value (verbose_level_),
         "verbosity level");

      command_line_.descriptions.add(global);
    }

    /* virtual */
    base::~base()
    {
      TRACE("platform::application::base::~application");
    }
    
  } // namespace application {
  
} // namespace platform {
