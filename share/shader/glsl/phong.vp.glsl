/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  shader/gls/phong.vp.glsl                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#version 430 core

#if !defined(UKACHULLDCS_08961_SHADER_GLSL_PHONG_VP_GLSL)

#define UKACHULLDCS_08961_SHADER_GLSL_PHONG_VP_GLSL

#extension GL_ARB_shading_language_include : enable

/* includes, system */

//#include <>

/* includes, project */

#include <common/config.glsl>
#include <common/phong.glsl>
#include <common/uniforms.glsl>

/* constants */

/* types, internal (enum, struct, union, typedef) */

/* variables, uniform */

/* variables, global */

in vec4 position;
in vec4 normal;
in vec2 tcoords;

out vp_out_t {
       vec3  position_wc;
       vec3  normal_wc;
       vec2  tcoords;
  flat int   mtl_id;
} vp_out;

// to avoid removal/deactivation of attributes ARB_separate_shader_objects is used, which
// requires redeclaration of 'gl_PerVertex'
// see [http://www.gamedev.net/topic/638043-gl-pervertex-opengl-error/]
out gl_PerVertex {
  vec4  gl_Position;
  float gl_PointSize;
  float gl_ClipDistance[];
};

/* functions */

void
main()
{
  gl_Position        = xform_projection * xform_view * xform_model * position;
  
  vp_out.position_wc =                            (xform_model   * position).xyz;
  vp_out.normal_wc   = normalize(transpose(inverse(xform_model)) * normal).xyz;
  vp_out.tcoords     = tcoords;
  vp_out.mtl_id      = material_id;
}

#endif /* #if !defined(UKACHULLDCS_08961_SHADER_GLSL_PHONG_VP_GLSL) */
