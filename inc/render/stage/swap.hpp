// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/stage/swap.hpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_STAGE_SWAP_HPP)

#define UKACHULLDCS_08961_RENDER_STAGE_SWAP_HPP

// includes, system

//#include <>

// includes, project

#include <render/stage/base.hpp>

namespace render {

  namespace stage {
      
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT swap : public base {

    public:
      
      field::value::single<bool> sync_to_vblank; ///< (dflt: true)
      
      virtual ~swap();
        
    protected:
        
      explicit swap(context::device&);
        
      virtual void do_resize(glm::ivec2 const&);
        
    };
      
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace stage {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_STAGE_SWAP_HPP)
