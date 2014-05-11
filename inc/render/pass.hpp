// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/pass.hpp                                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_PASS_HPP)

#define UKACHULLDCS_08961_RENDER_PASS_HPP

// includes, system

//#include <>

// includes, project

#include <render/api.hpp>

namespace render {
  
  // types, exported (class, enum, struct, union, typedef)

  template <api::type A>
  class pass : public api::traits<A>::pass {

  public:

    typedef typename api::traits<A>::pass inherited;

    static api::type const api_type;
    
  };

  template <api::type A> /* static */ api::type const pass<A>::api_type = A;
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_PASS_HPP)
