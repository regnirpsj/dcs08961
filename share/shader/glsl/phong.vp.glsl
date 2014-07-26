/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  shader/gls/phong.vp.glsl                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SHADER_GLSL_PHONG_VP_GLSL)

#define UKACHULLDCS_08961_SHADER_GLSL_PHONG_VP_GLSL

#version 430 core
#extension GL_ARB_shading_language_include : require

/* includes, system */

//#include <>

/* includes, project */

#include <common/phong.glsl>
#include <common/uniforms.glsl>

/* constants */

/* types, internal (enum, struct, union, typedef) */

/* variables, uniform */

/* variables, global */

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 normal;
layout (location = 2) in vec2 tcoords;
in int  mtl_id;

out vp_out_t {
       vec3 position_wc;
       vec3 normal_wc;
       vec2 tcoords;
  flat int  mtl_id;
} vp_out;

/* functions */

void
main()
{
  gl_Position = xform_projection * xform_view * xform_model * position;
  
  vp_out.position_wc =                            (xform_model   * position).xyz;
  vp_out.normal_wc   = normalize(transpose(inverse(xform_model)) * normal).xyz;
  vp_out.tcoords     = tcoords;
  vp_out.mtl_id      = mtl_id;
}

#endif /* #if !defined(UKACHULLDCS_08961_SHADER_GLSL_PHONG_VP_GLSL) */
