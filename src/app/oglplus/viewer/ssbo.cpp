// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/viewer/ssbo.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "ssbo.hpp"

// includes, system

//#include <>

// includes, project

//#include <>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace buffer {
  
  // variables, exported

  /* static */ slot_manager base::slot_mgr(96);
  
  // functions, exported

  /* explicit */
  slot_manager::slot_manager(unsigned a)
    : slots_(a, false)
  {
    TRACE("buffer::slot_manager::slot_manager");
  }
    
  unsigned
  slot_manager::alloc()
  {
    TRACE("buffer::slot_manager::alloc");
    
    unsigned result(0);
      
    for (unsigned i(0); i < slots_.size(); ++i) {
      if (false == slots_[i]) {
        slots_[i] = true;
        result    = i;

        break;
      }
    }

#if defined(UKACHULLDCS_USE_TRACE)
    std::cout << support::trace::prefix() << "buffer::slot_manager::alloc: "
              << "slot:" << result
              << '\n';
#endif

#if 0
    {
#define MKT(a) std::make_tuple(#a, a, -1)
      std::array<std::tuple<char const*, signed const, signed>, 219> limits = {
        {
          MKT(GL_ACTIVE_TEXTURE),
          MKT(GL_ALIASED_LINE_WIDTH_RANGE),
          MKT(GL_ARRAY_BUFFER_BINDING),
          MKT(GL_BLEND),
          //MKT(GL_BLEND_COLOR),
          MKT(GL_BLEND_DST_ALPHA),
          MKT(GL_BLEND_DST_RGB),
          MKT(GL_BLEND_EQUATION_ALPHA),
          MKT(GL_BLEND_EQUATION_RGB),
          MKT(GL_BLEND_SRC_ALPHA),
          MKT(GL_BLEND_SRC_RGB),
          //MKT(GL_COLOR_CLEAR_VALUE),
          MKT(GL_COLOR_LOGIC_OP),
          //MKT(GL_COLOR_WRITEMASK),
          //MKT(GL_COMPRESSED_TEXTURE_FORMATS),
          MKT(GL_CONTEXT_FLAGS),
          MKT(GL_CULL_FACE),
          MKT(GL_CURRENT_PROGRAM),
          MKT(GL_DEBUG_GROUP_STACK_DEPTH),
          MKT(GL_DEPTH_CLEAR_VALUE),
          MKT(GL_DEPTH_FUNC),
          MKT(GL_DEPTH_RANGE),
          MKT(GL_DEPTH_TEST),
          MKT(GL_DEPTH_WRITEMASK),
          MKT(GL_DISPATCH_INDIRECT_BUFFER_BINDING),
          MKT(GL_DITHER),
          MKT(GL_DOUBLEBUFFER),
          MKT(GL_DRAW_BUFFER),
          MKT(GL_DRAW_FRAMEBUFFER_BINDING),
          MKT(GL_ELEMENT_ARRAY_BUFFER_BINDING),
          MKT(GL_FRAGMENT_SHADER_DERIVATIVE_HINT),
          MKT(GL_IMPLEMENTATION_COLOR_READ_FORMAT),
          MKT(GL_IMPLEMENTATION_COLOR_READ_TYPE),
          MKT(GL_LAYER_PROVOKING_VERTEX),
          MKT(GL_LINE_SMOOTH),
          MKT(GL_LINE_SMOOTH_HINT),
          MKT(GL_LINE_WIDTH),
          MKT(GL_LOGIC_OP_MODE),
          MKT(GL_MAJOR_VERSION),
          MKT(GL_MAX_3D_TEXTURE_SIZE),
          MKT(GL_MAX_ARRAY_TEXTURE_LAYERS),
          MKT(GL_MAX_CLIP_DISTANCES),
          MKT(GL_MAX_COLOR_TEXTURE_SAMPLES),
          MKT(GL_MAX_COMBINED_ATOMIC_COUNTERS),
          MKT(GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS),
          MKT(GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS),
          MKT(GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS),
          MKT(GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS),
          MKT(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS),
          MKT(GL_MAX_COMBINED_UNIFORM_BLOCKS),
          MKT(GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS),
          MKT(GL_MAX_COMPUTE_ATOMIC_COUNTERS),
          MKT(GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS),
          MKT(GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS),
          MKT(GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS),
          MKT(GL_MAX_COMPUTE_UNIFORM_BLOCKS),
          MKT(GL_MAX_COMPUTE_UNIFORM_COMPONENTS),
          MKT(GL_MAX_COMPUTE_WORK_GROUP_COUNT),
          MKT(GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS),
          MKT(GL_MAX_COMPUTE_WORK_GROUP_SIZE),
          MKT(GL_MAX_CUBE_MAP_TEXTURE_SIZE),
          MKT(GL_MAX_DEBUG_GROUP_STACK_DEPTH),
          MKT(GL_MAX_DEPTH_TEXTURE_SAMPLES),
          MKT(GL_MAX_DRAW_BUFFERS),
          MKT(GL_MAX_DUAL_SOURCE_DRAW_BUFFERS),
          MKT(GL_MAX_ELEMENTS_INDICES),
          MKT(GL_MAX_ELEMENTS_VERTICES),
          MKT(GL_MAX_ELEMENT_INDEX),
          MKT(GL_MAX_FRAGMENT_ATOMIC_COUNTERS),
          MKT(GL_MAX_FRAGMENT_INPUT_COMPONENTS),
          MKT(GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS),
          MKT(GL_MAX_FRAGMENT_UNIFORM_BLOCKS),
          MKT(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS),
          MKT(GL_MAX_FRAGMENT_UNIFORM_VECTORS),
          MKT(GL_MAX_FRAMEBUFFER_HEIGHT),
          MKT(GL_MAX_FRAMEBUFFER_LAYERS),
          MKT(GL_MAX_FRAMEBUFFER_SAMPLES),
          MKT(GL_MAX_FRAMEBUFFER_WIDTH),
          MKT(GL_MAX_GEOMETRY_ATOMIC_COUNTERS),
          MKT(GL_MAX_GEOMETRY_INPUT_COMPONENTS),
          MKT(GL_MAX_GEOMETRY_OUTPUT_COMPONENTS),
          MKT(GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS),
          MKT(GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS),
          MKT(GL_MAX_GEOMETRY_UNIFORM_BLOCKS),
          MKT(GL_MAX_GEOMETRY_UNIFORM_COMPONENTS),
          MKT(GL_MAX_INTEGER_SAMPLES),
          MKT(GL_MAX_LABEL_LENGTH),
          MKT(GL_MAX_PROGRAM_TEXEL_OFFSET),
          MKT(GL_MAX_RECTANGLE_TEXTURE_SIZE),
          MKT(GL_MAX_RENDERBUFFER_SIZE),
          MKT(GL_MAX_SAMPLE_MASK_WORDS),
          MKT(GL_MAX_SERVER_WAIT_TIMEOUT),
          MKT(GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS),
          MKT(GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS),
          MKT(GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS),
          MKT(GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS),
          MKT(GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS),
          MKT(GL_MAX_TEXTURE_BUFFER_SIZE),
          MKT(GL_MAX_TEXTURE_IMAGE_UNITS),
          MKT(GL_MAX_TEXTURE_LOD_BIAS),
          MKT(GL_MAX_TEXTURE_SIZE),
          MKT(GL_MAX_UNIFORM_BLOCK_SIZE),
          MKT(GL_MAX_UNIFORM_BUFFER_BINDINGS),
          MKT(GL_MAX_UNIFORM_LOCATIONS),
          MKT(GL_MAX_VARYING_COMPONENTS),
          MKT(GL_MAX_VARYING_FLOATS),
          MKT(GL_MAX_VARYING_VECTORS),
          MKT(GL_MAX_VERTEX_ATOMIC_COUNTERS),
          MKT(GL_MAX_VERTEX_ATTRIBS),
          MKT(GL_MAX_VERTEX_ATTRIB_BINDINGS),
          MKT(GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET),
          MKT(GL_MAX_VERTEX_OUTPUT_COMPONENTS),
          MKT(GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS),
          MKT(GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS),
          MKT(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS),
          MKT(GL_MAX_VERTEX_UNIFORM_BLOCKS),
          MKT(GL_MAX_VERTEX_UNIFORM_COMPONENTS),
          MKT(GL_MAX_VERTEX_UNIFORM_VECTORS),
          MKT(GL_MAX_VIEWPORTS),
          MKT(GL_MAX_VIEWPORT_DIMS),
          MKT(GL_MINOR_VERSION),
          MKT(GL_MIN_MAP_BUFFER_ALIGNMENT),
          MKT(GL_MIN_PROGRAM_TEXEL_OFFSET),
          MKT(GL_NUM_COMPRESSED_TEXTURE_FORMATS),
          MKT(GL_NUM_EXTENSIONS),
          MKT(GL_NUM_PROGRAM_BINARY_FORMATS),
          MKT(GL_NUM_SHADER_BINARY_FORMATS),
          MKT(GL_PACK_ALIGNMENT),
          MKT(GL_PACK_IMAGE_HEIGHT),
          MKT(GL_PACK_LSB_FIRST),
          MKT(GL_PACK_ROW_LENGTH),
          MKT(GL_PACK_SKIP_IMAGES),
          MKT(GL_PACK_SKIP_PIXELS),
          MKT(GL_PACK_SKIP_ROWS),
          MKT(GL_PACK_SWAP_BYTES),
          MKT(GL_PIXEL_PACK_BUFFER_BINDING),
          MKT(GL_PIXEL_UNPACK_BUFFER_BINDING),
          MKT(GL_POINT_FADE_THRESHOLD_SIZE),
          MKT(GL_POINT_SIZE),
          MKT(GL_POINT_SIZE_GRANULARITY),
          MKT(GL_POINT_SIZE_RANGE),
          MKT(GL_POLYGON_OFFSET_FACTOR),
          MKT(GL_POLYGON_OFFSET_FILL),
          MKT(GL_POLYGON_OFFSET_LINE),
          MKT(GL_POLYGON_OFFSET_POINT),
          MKT(GL_POLYGON_OFFSET_UNITS),
          MKT(GL_POLYGON_SMOOTH),
          MKT(GL_POLYGON_SMOOTH_HINT),
          MKT(GL_PRIMITIVE_RESTART_INDEX),
          MKT(GL_PROGRAM_BINARY_FORMATS),
          MKT(GL_PROGRAM_PIPELINE_BINDING),
          MKT(GL_PROGRAM_POINT_SIZE),
          MKT(GL_PROVOKING_VERTEX),
          MKT(GL_READ_BUFFER),
          MKT(GL_READ_FRAMEBUFFER_BINDING),
          MKT(GL_RENDERBUFFER_BINDING),
          MKT(GL_SAMPLER_BINDING),
          MKT(GL_SAMPLES),
          MKT(GL_SAMPLE_BUFFERS),
          MKT(GL_SAMPLE_COVERAGE_INVERT),
          MKT(GL_SAMPLE_COVERAGE_VALUE),
          //MKT(GL_SCISSOR_BOX),
          MKT(GL_SCISSOR_TEST),
          MKT(GL_SHADER_COMPILER),
          MKT(GL_SHADER_STORAGE_BUFFER_BINDING),
          MKT(GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT),
          MKT(GL_SHADER_STORAGE_BUFFER_SIZE),
          MKT(GL_SHADER_STORAGE_BUFFER_START),
          MKT(GL_SMOOTH_LINE_WIDTH_GRANULARITY),
          MKT(GL_SMOOTH_LINE_WIDTH_RANGE),
          MKT(GL_STENCIL_BACK_FAIL),
          MKT(GL_STENCIL_BACK_FUNC),
          MKT(GL_STENCIL_BACK_PASS_DEPTH_FAIL),
          MKT(GL_STENCIL_BACK_PASS_DEPTH_PASS),
          MKT(GL_STENCIL_BACK_REF),
          MKT(GL_STENCIL_BACK_VALUE_MASK),
          MKT(GL_STENCIL_BACK_WRITEMASK),
          MKT(GL_STENCIL_CLEAR_VALUE),
          MKT(GL_STENCIL_FAIL),
          MKT(GL_STENCIL_FUNC),
          MKT(GL_STENCIL_PASS_DEPTH_FAIL),
          MKT(GL_STENCIL_PASS_DEPTH_PASS),
          MKT(GL_STENCIL_REF),
          MKT(GL_STENCIL_TEST),
          MKT(GL_STENCIL_VALUE_MASK),
          MKT(GL_STENCIL_WRITEMASK),
          MKT(GL_STEREO),
          MKT(GL_SUBPIXEL_BITS),
          MKT(GL_TEXTURE_2D),
          MKT(GL_TEXTURE_BINDING_1D),
          MKT(GL_TEXTURE_BINDING_1D_ARRAY),
          MKT(GL_TEXTURE_BINDING_2D),
          MKT(GL_TEXTURE_BINDING_2D_ARRAY),
          MKT(GL_TEXTURE_BINDING_2D_MULTISAMPLE),
          MKT(GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY),
          MKT(GL_TEXTURE_BINDING_3D),
          MKT(GL_TEXTURE_BINDING_BUFFER),
          MKT(GL_TEXTURE_BINDING_CUBE_MAP),
          MKT(GL_TEXTURE_BINDING_RECTANGLE),
          MKT(GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT),
          MKT(GL_TEXTURE_COMPRESSION_HINT),
          MKT(GL_TIMESTAMP),
          MKT(GL_TRANSFORM_FEEDBACK_BUFFER_BINDING),
          MKT(GL_TRANSFORM_FEEDBACK_BUFFER_SIZE),
          MKT(GL_TRANSFORM_FEEDBACK_BUFFER_START),
          MKT(GL_UNIFORM_BUFFER_BINDING),
          MKT(GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT),
          MKT(GL_UNIFORM_BUFFER_SIZE),
          MKT(GL_UNIFORM_BUFFER_START),
          MKT(GL_UNPACK_ALIGNMENT),
          MKT(GL_UNPACK_IMAGE_HEIGHT),
          MKT(GL_UNPACK_LSB_FIRST),
          MKT(GL_UNPACK_ROW_LENGTH),
          MKT(GL_UNPACK_SKIP_IMAGES),
          MKT(GL_UNPACK_SKIP_PIXELS),
          MKT(GL_UNPACK_SKIP_ROWS),
          MKT(GL_UNPACK_SWAP_BYTES),
          MKT(GL_VERTEX_ARRAY_BINDING),
          MKT(GL_VERTEX_BINDING_DIVISOR),
          MKT(GL_VERTEX_BINDING_OFFSET),
          MKT(GL_VERTEX_BINDING_STRIDE),
          //MKT(GL_VIEWPORT),
          MKT(GL_VIEWPORT_BOUNDS_RANGE),
          MKT(GL_VIEWPORT_INDEX_PROVOKING_VERTEX),
          MKT(GL_VIEWPORT_SUBPIXEL_BITS),
        }
      };
#undef MKT
      
      for (auto& l : limits) {
        ::glGetIntegerv(std::get<1>(l), &std::get<2>(l));
      }
      
      std::cout << support::trace::prefix() << "buffer::slot_manager::alloc: ";

      std::string const indent(support::trace::prefix().length(), ' ');
      
      for (auto const& l : limits) {
        std::cout << '\n' << indent
                  << std::get<0>(l) << ':' << std::get<2>(l);
      }

      std::cout << '\n';
    }
#endif
    
    return result;
  }
    
  void
  slot_manager::release(unsigned a)
  {
    TRACE("buffer::slot_manager::release");

#if defined(UKACHULLDCS_USE_TRACE)
    std::cout << support::trace::prefix() << "buffer::slot_manager::release: "
              << "slot:" << a
              << '\n';
#endif
    
    slots_[a] = false;
  }

  /* explicit */
  base::base(std::string const& a, oglplus::Program& b)
    : name_(a),
      prg_ (b),
      buf_ ()
  {
    TRACE("buffer::base::base");
  }
  
} // namespace buffer {
