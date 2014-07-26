/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  shader/glsl/common/uniforms.glsl                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SHADER_GLSL_COMMON_UNIFORMS_GLSL)

#define UKACHULLDCS_08961_SHADER_GLSL_COMMON_UNIFORMS_GLSL

/* includes, system */

//#include <>

/* includes, project */

//#include <>

/* constants */

/* types, internal (enum, struct, union, typedef) */

/* variables, uniform */

uniform mat4x4 xform_model;
uniform mat4x4 xform_view;
uniform mat4x4 xform_projection;
uniform uvec2  screen_size;

/* variables, global */

/* functions */

#endif /* #if !defined(UKACHULLDCS_08961_SHADER_GLSL_COMMON_UNIFORMS_GLSL) */
