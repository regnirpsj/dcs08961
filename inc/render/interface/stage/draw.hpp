// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/interface/stage/draw.hpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_INTERFACE_STAGE_DRAW_HPP)

#define UKACHULLDCS_08961_RENDER_INTERFACE_STAGE_DRAW_HPP

// includes, system

//#include <>

// includes, project

#include <render/api.hpp>

namespace render {

  namespace stage {
    
    // types, exported (class, enum, struct, union, typedef)

    template <api::type A>
    class draw : public api::traits<A>::draw {

    public:

      typedef typename api::traits<A>::draw inherited;

      static api::type const api_type;

      explicit draw(context<A>& a)
        : inherited(a)
      {}
      
    };

    template <api::type A> /* static */ api::type const draw<A>::api_type = A;
  
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace stage {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_INTERFACE_STAGE_DRAW_HPP)
