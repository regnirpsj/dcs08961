// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/interface/pass/container.hpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_INTERFACE_PASS_CONTAINER_HPP)

#define UKACHULLDCS_08961_RENDER_INTERFACE_PASS_CONTAINER_HPP

// includes, system

//#include <>

// includes, project

#include <render/api.hpp>

namespace render {

  namespace pass {
    
    // types, exported (class, enum, struct, union, typedef)

    template <api::type A>
    class  container : public api::traits<A>::container {

    public:

      typedef typename api::traits<A>::container inherited;

      static api::type const api_type;
    
    };

    template <api::type A> /* static */ api::type const  container<A>::api_type = A;
  
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace pass {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_INTERFACE_PASS_CONTAINER_HPP)
