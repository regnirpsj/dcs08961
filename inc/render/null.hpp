// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/null.hpp                                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_NULL_HPP)

#define UKACHULLDCS_08961_RENDER_NULL_HPP

// includes, system

//#include <>

// includes, project

#include <render/api.hpp>
#include <render/null/context.hpp>
#include <render/null/pass.hpp>
#include <render/null/stage.hpp>

namespace render {

  namespace api {
    
    // types, exported (class, enum, struct, union, typedef)

    template <> class traits<type::null> {

    public:

      typedef null::context context;
      typedef null::pass    pass;
      typedef null::stage   stage;
      
    };
  
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace api {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_NULL_HPP)
