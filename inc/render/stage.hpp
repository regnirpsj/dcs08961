// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/stage.hpp                                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_STAGE_HPP)

#define UKACHULLDCS_08961_RENDER_STAGE_HPP

// includes, system

//#include <>

// includes, project

#include <render/api.hpp>

namespace render {
  
  // types, exported (class, enum, struct, union, typedef)

  template <api::type A>
  class stage : public api::traits<A>::stage {

  public:

    typedef typename api::traits<A>::stage inherited;

    static api::type const api_type;
    
  };

  template <api::type A> /* static */ api::type const stage<A>::api_type = A;
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_STAGE_HPP)
