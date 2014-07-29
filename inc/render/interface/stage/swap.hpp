// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/interface/stage/swap.hpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_INTERFACE_STAGE_SWAP_HPP)

#define UKACHULLDCS_08961_RENDER_INTERFACE_STAGE_SWAP_HPP

// includes, system

//#include <>

// includes, project

#include <render/api.hpp>

namespace render {

  namespace stage {
    
    // types, exported (class, enum, struct, union, typedef)

    template <api::type A>
    class swap : public api::traits<A>::swap {

    public:

      typedef typename api::traits<A>::swap inherited;

      static api::type const api_type;
    
    };

    template <api::type A> /* static */ api::type const swap<A>::api_type = A;
  
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace stage {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_INTERFACE_STAGE_SWAP_HPP)
