// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  support/application.cpp                                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "support/application.hpp"

// includes, system

#include <boost/concept_check.hpp> // boost::ignore_unused_variable_warning<>
#include <boost/filesystem.hpp>    // boost::filesystem::path
#include <stdexcept>               // std::logic_error

// includes, project

// #include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

#if defined(UKACHULLDCS_USE_TRACE)
#  include <iomanip>
#endif

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace support {
  
  // variables, exported

  /* static */ application* application::application_(nullptr);
  
  // functions, exported
  
  /* static */ application*
  application::instance()
  {
    TRACE("support::application::instance");
    
    return application_;
  }
  
  /* virtual */ void
  application::config(int argc, char* argv[])
  {
    TRACE("support::application::config");

    cmdline_process(argc, argv);
  }
  
  /* virtual */ void
  application::init()
  {
    TRACE("support::application::init");
  }
  
  /* virtual */ signed
  application::run()
  {
    TRACE("support::application::run");

    throw std::logic_error("pure virtual function 'support::application::run' called");
    
    return 0;
  }
  
  /* virtual */ void
  application::fini()
  {
    TRACE("support::application::fini");
  }

  /* virtual */ void
  application::print_on(std::ostream& os) const
  {
    TRACE_NEVER("support::application::print_on");
      
    os << '['
       << "@0x"      << application_ << ','
       << "verbose:" << verbose_level_
       << ']';
  }
  
  /* explicit */
  application::application()
    : boost::noncopyable  (),
      support::printable  (),
      cmdline_options_    (),
      cmdline_positionals_(),
      verbose_level_      (0)
  {
    TRACE("support::application::application");

    if (nullptr == application_) {
      application_ = this;
    } else {
      throw std::logic_error("only one application instance allowed at runtime");
    }

#if defined(UKACHULLDCS_USE_TRACE)
    std::cout << support::trace::prefix() << "support::application::application: "
              << *this
              << std::endl;
#endif
    
    {
      namespace po = boost::program_options;

      po::options_description global("Global Options");

      global.add_options()
        ("help,h", "display command-line help and exit");
      
      global.add_options()
        ("verbose,v",
         po::value<unsigned>(&verbose_level_)
         ->implicit_value(verbose_level_ + 1)
         ->default_value (verbose_level_),
         "verbosity level");
      
      cmdline_options_.add(global);
    }
  }
  
  /* virtual */
  application::~application()
  {
    TRACE("support::application::~application");
  }

  /* virtual */ void
  application::cmdline_eval(boost::program_options::variables_map&)
  {
    TRACE("support::application::cmdline_eval");
  }
  
  /* virtual */ void
  application::cmdline_process(int argc, char* argv[])
  {
    TRACE("support::application::cmdline_process");
    
    namespace po = boost::program_options;

    std::string const base_name(boost::filesystem::path(argv[0]).filename().string());
    bool              print_help(false);
    signed            return_value(EXIT_SUCCESS);
    po::variables_map vm;
    
    try {
      po::store(po::command_line_parser(argc, argv)
                .options   (cmdline_options_)
                .positional(cmdline_positionals_)
                .run       (),
                vm);

      po::notify(vm);
    }
    
    catch (std::exception const& ex) {
      std::cerr << '\n' /* << base_name << ' ' */
                << "command-line problem: " << ex.what() << std::endl;
      
      print_help   = true;
      return_value = EXIT_FAILURE;
    }
    
    if (vm.count("help") || print_help) {
      std::cerr << "\nusage: " << base_name << " [OPTIONS] [POSITIONALS ...]\n"
                << cmdline_options_
                << std::endl;
      
      std::exit(return_value);
    }

    cmdline_eval(vm);
  }
  
} // namespace support {
