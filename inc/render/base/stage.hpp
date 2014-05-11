// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/stage.hpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_BASE_STAGE_HPP)

#define UKACHULLDCS_08961_RENDER_BASE_STAGE_HPP

// includes, system

#include <boost/noncopyable.hpp> // boost::noncopyable

// includes, project

#include <support/printable.hpp>

namespace render {

  namespace base {
    
    // types, exported (class, enum, struct, union, typedef)

    class stage : private boost::noncopyable,
                  public support::printable {

    public:

      virtual ~stage() =0;
      
      virtual void print_on(std::ostream&) const;

    protected:
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace base {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_BASE_STAGE_HPP)
