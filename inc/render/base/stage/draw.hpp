// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/stage/draw.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_BASE_STAGE_DRAW_HPP)

#define UKACHULLDCS_08961_RENDER_BASE_STAGE_DRAW_HPP

// includes, system

//#include <>

// includes, project

#include <render/base/stage/base.hpp>

namespace render {

  namespace base {

    namespace stage {
      
      // types, exported (class, enum, struct, union, typedef)

      class draw : public base {

      public:
        
        virtual ~draw();
      
        virtual void print_on(std::ostream&) const;

      protected:

        explicit draw(context&, statistics::base&);

        virtual void do_execute();
          
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace stage {
    
  } // namespace base {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_BASE_STAGE_DRAW_HPP)
