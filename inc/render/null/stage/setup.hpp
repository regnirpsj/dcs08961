// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/null/stage/setup.hpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_NULL_STAGE_SETUP_HPP)

#define UKACHULLDCS_08961_RENDER_NULL_STAGE_SETUP_HPP

// includes, system

// #include <>

// includes, project

#include <render/base/stage/setup.hpp>

namespace render {

  namespace null {
    
    namespace stage {
      
      // types, exported (class, enum, struct, union, typedef)

      class setup : public base::stage::setup {

      public:

        explicit setup();
        virtual ~setup();

      protected:
        
        virtual void do_execute();
        
      };      
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace stage {
    
  } // namespace null {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_NULL_STAGE_SETUP_HPP)
