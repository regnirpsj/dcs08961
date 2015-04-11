// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  support/trace.hpp                                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SUPPORT_TRACE_HPP)

#define UKACHULLDCS_08961_SUPPORT_TRACE_HPP

// includes, system

#include <boost/noncopyable.hpp> // boost::noncopyable
#include <iostream>              // std::cout, std::ostream
#include <string>                // std::string

// includes, project

#include <support/chrono.hpp> // clock::duration
#include <support/export.h>

namespace support {
  
  // types, exported (class, enum, struct, union, typedef)

  class DCS08961_SUPPORT_EXPORT trace : private boost::noncopyable {

  public:
    
    explicit  trace(std::string const&, std::ostream& = std::cout);
             ~trace();
    
    static DCS08961_SUPPORT_EXPORT void        enter(std::string const&, std::ostream& = std::cout);
    static DCS08961_SUPPORT_EXPORT void        leave(std::string const&, std::ostream& = std::cout);
    static DCS08961_SUPPORT_EXPORT std::string prefix();
    
  private:

    std::string const msg_;
    std::ostream&     os_;
    clock::duration   start_;
    clock::duration   stop_;

    static void        enter (trace* /* ctx */, std::string const& /* msg */, std::ostream&);
    static void        leave (trace* /* ctx */, std::string const& /* msg */, std::ostream&);
    static std::string prefix(trace* /* ctx */, bool /* show duration */);
    
  };

  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace support {

#include <boost/current_function.hpp> // BOOST_CURRENT_FUNCTION

#define TRACE_NEVER(x)
#define TRACE_ALWAYS(x)       volatile support::trace const __(x)
#define TRACE_FUNC_ALWAYS     volatile support::trace const __(BOOST_CURRENT_FUNCTION)
#define TRACE_ENTER_ALWAYS(x)          support::trace::enter(x)
#define TRACE_LEAVE_ALWAYS(x)          support::trace::leave(x)

#endif // #if !defined(UKACHULLDCS_08961_SUPPORT_TRACE_HPP)

// the following is intentionally outside the include guards to allow including this header
// multiple times with different settings for UKACHULLDCS_USE_TRACE

#if defined(TRACE)
#  undef TRACE
#endif

#if defined(TRACE_FUNC)
#  undef TRACE_FUNC
#endif

#if defined(TRACE_ENTER)
#  undef TRACE_ENTER
#endif

#if defined(TRACE_LEAVE)
#  undef TRACE_LEAVE
#endif

#if defined(UKACHULLDCS_ALL_TRACE)
#  define UKACHULLDCS_USE_TRACE
#endif

#if defined(UKACHULLDCS_USE_TRACE)
#  define TRACE(x) TRACE_ALWAYS(x)
#  define TRACE_FUNC TRACE_FUNC_ALWAYS
#  define TRACE_ENTER(x) TRACE_ENTER_ALWAYS(x)
#  define TRACE_LEAVE(x) TRACE_LEAVE_ALWAYS(x)
#else
#  define TRACE(x)
#  define TRACE_FUNC
#  define TRACE_ENTER(x)
#  define TRACE_LEAVE(x)
#endif
