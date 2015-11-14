// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  render/stage/setup.hpp                                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_RENDER_STAGE_SETUP_HPP)

#define UKACHULLDCS_08961_RENDER_STAGE_SETUP_HPP

// includes, system

//#include <>

// includes, project

#include <render/shader/program.hpp>
#include <render/stage/base.hpp>
#include <render/state/blend.hpp>
#include <render/state/depth_stencil.hpp>
#include <render/state/raster.hpp>
#include <render/state/sampler.hpp>

namespace render {

  namespace stage {
      
    // types, exported (class, enum, struct, union, typedef)

    class DCS08961_RENDER_EXPORT setup : public base {

    public:

      using blend_state_field_type         =
        field::value::single<boost::intrusive_ptr<state::blend>>;
      using depth_stencil_state_field_type =
        field::value::single<boost::intrusive_ptr<state::depth_stencil>>;
      using raster_state_field_type        =
        field::value::single<boost::intrusive_ptr<state::raster>>;
      using sampler_state_field_type       =
        field::value::single<boost::intrusive_ptr<state::sampler>>;
      using shader_program_field_type      =
        field::value::single<boost::intrusive_ptr<shader::program>>;

      blend_state_field_type         state_blend;         //<
      depth_stencil_state_field_type state_depth_stencil; //<
      raster_state_field_type        state_raster;        //<
      sampler_state_field_type       state_sampler;       //<
      shader_program_field_type      shader_program;      //<
      
      virtual ~setup();
        
    protected:
        
      explicit setup(device::context&);
        
    };
      
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace stage {
  
} // namespace render {

#endif // #if !defined(UKACHULLDCS_08961_RENDER_STAGE_SETUP_HPP)
