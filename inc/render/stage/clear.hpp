// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/stage/clear.hpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_STAGE_CLEAR_HPP)

#define UKACHULLDCS_08961_RENDER_STAGE_CLEAR_HPP

// includes, system

//#include <>

// includes, project

#include <render/stage/base.hpp>

namespace render {

  namespace stage {
      
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT clear : public base {

    public:

      field::value::single<bool>      color;         ///< clear color buffer(s) (dflt: true)
      field::value::single<glm::vec4> color_value;   ///< clear value           (dflt: [0,0,0,0])
      field::value::single<bool>      depth;         ///< clear depth buffer    (dflt: true)
      field::value::single<float>     depth_value;   ///< clear vaue            (dflt: [1])
      field::value::single<bool>      stencil;       ///< clear stencil buffer  (dflt: false)
      field::value::single<signed>    stencil_value; ///< clear value           (dflt: 0)
      
      virtual ~clear();
        
    protected:
        
      explicit clear(context::device&);
        
      virtual void do_resize(glm::ivec2 const&);
        
    };
      
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace stage {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_STAGE_CLEAR_HPP)
