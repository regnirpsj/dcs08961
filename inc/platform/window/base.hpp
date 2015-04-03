// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  platform_window_base.hpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_PLATFORM_WINDOW_BASE_HPP)

#define UKACHULLDCS_08961_PLATFORM_WINDOW_BASE_HPP

// includes, system

#include <boost/noncopyable.hpp> // boost::noncopyable
#include <string>                // std::string

// includes, project

#include <platform/export.h>
#include <support/printable.hpp>

namespace platform {

  namespace window {

    class DCS08961_PLATFORM_EXPORT base : private boost::noncopyable,
                                          public support::printable {

    public:

      virtual ~base() =0;
      
      virtual void print_on(std::ostream&) const;

    protected:

      std::string title_;
      
      explicit base(std::string const& /* title */);
      
    };
      
    // types, exported (class, enum, struct, union, typedef)

    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace window {
  
} // namespace platform {

#endif // #if !defined(UKACHULLDCS_08961_PLATFORM_WINDOW_BASE_HPP)
