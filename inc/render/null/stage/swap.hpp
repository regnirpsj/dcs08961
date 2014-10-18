// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
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

namespace render {

  namespace null {

    class context;
    
    namespace stage {
      
      // types, exported (class, enum, struct, union, typedef)

      class swap : public base::stage::swap {

      public:

        explicit swap(context&);
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
