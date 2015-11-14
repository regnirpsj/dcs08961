// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/state/sampler.hpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_STATE_SAMPLER_HPP)

#define UKACHULLDCS_08961_RENDER_STATE_SAMPLER_HPP

// includes, system

//#include <>

// includes, project

#include <render/state/base.hpp>

namespace render {
  
  namespace state {
      
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT sampler : public base {

    public:
      
      virtual ~sampler();

    protected:
      
      explicit sampler(device::context&);

    };
      
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace state {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_STATE_SAMPLER_HPP)
