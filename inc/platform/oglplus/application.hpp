// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform/oglplus/application.hpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_OGLPLUS_APPLICATION_HPP)

#define UKACHULLDCS_08961_PLATFORM_OGLPLUS_APPLICATION_HPP

// includes, system

#include <exception> // std::exception
#include <iosfwd>    // std::ostream (fwd decl)
#include <string>    // std::sring

// includes, project

#include <platform/application/command_line.hpp>
#include <platform/config.hpp>

namespace oglplus {

  class Error;

} // namespace oglplus {


namespace platform {

  namespace oglplus {

    namespace application {
  
      // types, exported (class, enum, struct, union, typedef)

      using command_line = platform::application::command_line;
      
      // variables, exported (extern)

      // functions, inlined (inline)

      template <typename T> signed execute(command_line const&);
      template <typename T> signed execute(command_line const&, std::nothrow_t const&) noexcept;
      
      // functions, exported (extern)
      
      void print_oglplus_error_common(::oglplus::Error&,
                                      std::ostream&, std::string const& /* prefix */);
      void print_stdcpp_error_common (std::exception&,
                                      std::ostream&, std::string const& /* prefix */);
      
    } // namespace application {

  } // namespace oglplus {
  
} // namespace platform {

#include <platform/oglplus/application.inl>

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_OGLPLUS_APPLICATION_HPP)
