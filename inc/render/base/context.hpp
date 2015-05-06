// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/context.hpp                                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_BASE_CONTEXT_HPP)

#define UKACHULLDCS_08961_RENDER_BASE_CONTEXT_HPP

// includes, system

#include <boost/noncopyable.hpp> // boost::noncopyable

// includes, project

#include <render/export.h>
#include <support/printable.hpp>

namespace render {

  namespace base {
    
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT context : private boost::noncopyable,
                                           public support::printable {

    public:

      virtual ~context() =0;
      
      virtual void print_on(std::ostream&) const;

    protected:

      explicit context();
    
    };
  
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace base {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_BASE_CONTEXT_HPP)
