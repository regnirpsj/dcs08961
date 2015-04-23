// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/window.hpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_BASE_WINDOW_HPP)

#define UKACHULLDCS_08961_RENDER_BASE_WINDOW_HPP

// includes, system

#include <boost/noncopyable.hpp> // boost::noncopyable

// includes, project

#include <support/printable.hpp>
#include <render/export.h>

namespace render {

  namespace base {
  
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT window : private boost::noncopyable,
                                          public support::printable {

    public:

      virtual ~window() =0;

      virtual void print_on(std::ostream&) const;
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)
  
  } // namespace base {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_BASE_WINDOW_HPP)
