// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/application/command_line.hpp                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_APPLICATION_COMMAND_LINE_HPP)

#define UKACHULLDCS_08961_PLATFORM_APPLICATION_COMMAND_LINE_HPP

// includes, system

#include <boost/program_options.hpp> // boost::program_options::options_description
#include <string>                    // std::string
#include <vector>                    // std::vector<>

// includes, project

#include <platform/export.h>
#include <support/printable.hpp>

namespace platform {

  namespace application {
  
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_PLATFORM_EXPORT command_line : public support::printable {

    public:
      
      using options_description            = boost::program_options::options_description;
      using positional_options_description = boost::program_options::positional_options_description;
      using variables_map                  = boost::program_options::variables_map;

      std::string const              argv0;
      options_description            descriptions;
      variables_map                  options;
      positional_options_description positionals;
      
      explicit command_line(int /* argc */, char const* /* argv */[]);
      
      virtual void print_on(std::ostream&) const;
      
      void process(bool /* force re-evaluation */ = false);
      
    protected:

      std::vector<std::string> argv_;
      bool                     already_processed_;
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace application {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_APPLICATION_COMMAND_LINE_HPP)
