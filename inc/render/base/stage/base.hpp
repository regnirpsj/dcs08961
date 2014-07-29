// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/stage/base.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_BASE_STAGE_BASE_HPP)

#define UKACHULLDCS_08961_RENDER_BASE_STAGE_BASE_HPP

// includes, system

//#include <>

// includes, project

#include <support/printable.hpp>
#include <support/refcounted.hpp>

namespace render {

  namespace base {

    namespace stage {
      
      // types, exported (class, enum, struct, union, typedef)

      class base : public support::printable,
                   public support::refcounted {

      public:

        virtual ~base() =0;

        virtual void execute() =0;
      
        virtual void print_on(std::ostream&) const;

      protected:

        explicit base();
        
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace stage {
    
  } // namespace base {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_BASE_STAGE_BASE_HPP)
