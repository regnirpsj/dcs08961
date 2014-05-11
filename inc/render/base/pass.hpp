// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/base/pass.hpp                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_BASE_PASS_HPP)

#define UKACHULLDCS_08961_RENDER_BASE_PASS_HPP

// includes, system

#include <boost/noncopyable.hpp> // boost::noncopyable

// includes, project

#include <render/base/stage.hpp>

namespace render {

  namespace base {
    
    // types, exported (class, enum, struct, union, typedef)

    class pass : public stage {

    public:

      virtual ~pass() =0;
      
    protected:
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace base {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_BASE_PASS_HPP)
