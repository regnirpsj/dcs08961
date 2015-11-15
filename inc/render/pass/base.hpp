// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/pass/base.hpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_PASS_BASE_HPP)

#define UKACHULLDCS_08961_RENDER_PASS_BASE_HPP

// includes, system

//#include <>

// includes, project

#include <render/stage/base.hpp>

namespace render {
    
  namespace pass {
      
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT base : public stage::base {

    public:

      virtual ~base();
        
    protected:
        
      explicit base(context::device&);

    };
      
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace pass {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_PASS_BASE_HPP)
