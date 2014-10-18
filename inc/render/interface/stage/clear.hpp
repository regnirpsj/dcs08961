// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/interface/stage/clear.hpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_INTERFACE_STAGE_CLEAR_HPP)

#define UKACHULLDCS_08961_RENDER_INTERFACE_STAGE_CLEAR_HPP

// includes, system

//#include <>

// includes, project

#include <render/api.hpp>

namespace render {

  namespace stage {
    
    // types, exported (class, enum, struct, union, typedef)

    template <api::type A>
    class clear : public api::traits<A>::clear {

    public:

      typedef typename api::traits<A>::clear inherited;

      static api::type const api_type;

      explicit clear(context<A>& a)
        : inherited(a)
      {}
      
    };

    template <api::type A> /* static */ api::type const clear<A>::api_type = A;
  
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace stage {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_INTERFACE_STAGE_CLEAR_HPP)
