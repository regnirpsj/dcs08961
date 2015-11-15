// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/shader/compute.hpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_SHADER_COMPUTE_HPP)

#define UKACHULLDCS_08961_RENDER_SHADER_COMPUTE_HPP

// includes, system

#include <glm/glm.hpp> // glm::uvec3

// includes, project

#include <render/shader/base.hpp>

namespace render {
  
  namespace shader {
      
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT compute : public base {

    public:      
      
      virtual ~compute();

      void activate() =delete;
      void dispatch(glm::uvec3 const& = glm::uvec3(1,0,0));
      
    protected:

      explicit compute(context::device&);

      virtual void do_activate();
      virtual void do_dispatch(glm::uvec3 const&) =0;
      
    };
      
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace shader {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_SHADER_COMPUTE_HPP)
