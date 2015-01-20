// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/null/stage/draw.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_NULL_STAGE_DRAW_HPP)

#define UKACHULLDCS_08961_RENDER_NULL_STAGE_DRAW_HPP

// includes, system

// #include <>

// includes, project

#include <render/base/stage/draw.hpp>

namespace render {

  namespace null {
    
    namespace stage {
      
      // types, exported (class, enum, struct, union, typedef)

      class draw : public base::stage::draw {

      public:

        explicit draw();
        virtual ~draw();

      protected:
        
        virtual void do_execute();
        
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace stage {
    
  } // namespace null {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_NULL_STAGE_DRAW_HPP)
