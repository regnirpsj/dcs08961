// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/null/stage/swap.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_NULL_STAGE_SWAP_HPP)

#define UKACHULLDCS_08961_RENDER_NULL_STAGE_SWAP_HPP

// includes, system

// #include <>

// includes, project

#include <render/base/stage/swap.hpp>
#include <render/null/export.h>

namespace render {

  namespace null {
    
    namespace stage {
      
      // types, exported (class, enum, struct, union, typedef)

      class DCS08961_RENDER_NULL_EXPORT swap : public base::stage::swap {

      public:

        explicit swap();
        virtual ~swap();

      protected:
        
        virtual void do_execute();
        
      };      
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace stage {
    
  } // namespace null {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_NULL_STAGE_SWAP_HPP)
