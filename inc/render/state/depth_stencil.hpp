// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/state/depth_stencil.hpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_STATE_DEPTH_STENCIL_HPP)

#define UKACHULLDCS_08961_RENDER_STATE_DEPTH_STENCIL_HPP

// includes, system

//#include <>

// includes, project

#include <render/state/base.hpp>

namespace render {
  
  namespace state {
      
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT depth_stencil : public base {

    public:
      
      virtual ~depth_stencil();
      
      virtual void print_on(std::ostream&) const;

    protected:
      
      explicit depth_stencil(context&);

    };
      
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace state {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_STATE_DEPTH_STENCIL_HPP)
