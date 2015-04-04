// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/posix/application/base.cpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "platform/posix/application/base.hpp"

// includes, system

//#include <>

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

  namespace posix {

    namespace application {
      
      // variables, exported
  
      // functions, exported

      /* virtual */ void
      base::print_on(std::ostream& os) const
      {
        TRACE_NEVER("platform::posix::application::base::print_on");

        platform::application::single_instance::print_on(os);

        using support::ostream::operator<<;
        
        os << "\b," << input_files_ << ']';
      }
      
      /* explicit */
      base::base(platform::application::command_line const& a)
        : platform::application::single_instance(a),
          input_files_                          ()
      {
        TRACE("platform::posix::application::base::base");

        {
          namespace bpo = boost::program_options;
          
          bpo::options_description od("Command-Line Options");

          od.add_options()
            ("file,f",
             bpo::value(&input_files_)->composing(),
             "input file(s)\n"
             "positional arguments are accumulated as input files");

          command_line_.descriptions.add(od);
          command_line_.positionals .add("file", -1);
        }
      }

    } // namespace application {

  } // namespace posix {
  
} // namespace platform {
