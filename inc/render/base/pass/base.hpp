// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/pass/base.hpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_BASE_PASS_BASE_HPP)

#define UKACHULLDCS_08961_RENDER_BASE_PASS_BASE_HPP

// includes, system

//#include <>

// includes, project

#include <render/base/stage/base.hpp>

namespace render {

  namespace base {

    namespace pass {
      
      // types, exported (class, enum, struct, union, typedef)

      class base : public stage::base {

      public:

        virtual ~base() =0;

        virtual void print_on(std::ostream&) const;
        
      protected:

        explicit base(context&, statistics::base&);
        
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace pass {
    
  } // namespace base {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_BASE_PASS_BASE_HPP)
