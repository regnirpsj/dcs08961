// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
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

namespace render {

  namespace null {
    
    // types, exported (class, enum, struct, union, typedef)

    class context : public base::context {

    public:
      
      virtual ~context();
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace null {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_NULL_CONTEXT_HPP)
