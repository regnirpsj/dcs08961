// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/null/context.hpp                                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_NULL_CONTEXT_HPP)

#define UKACHULLDCS_08961_RENDER_NULL_CONTEXT_HPP

// includes, system

//#include <>

// includes, project

#include <render/base/context.hpp>
#include <render/null/export.h>

namespace render {

  namespace null {
    
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_NULL_EXPORT context : public base::context {

    public:

      static context dflt;
      
      virtual ~context();
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace null {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_NULL_CONTEXT_HPP)
