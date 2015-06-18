/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
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

uniform uvec2  screen_size; // in pixel

uniform mat4x4 xform_model;
uniform mat4x4 xform_view;
uniform mat4x4 xform_projection;

uniform int         material_id                  = -1;
uniform bool        material_tex_diffuse_enabled = false;
uniform sampler2D   material_tex_diffuse;
uniform bool        material_tex_envmap_enabled  = false;
uniform samplerCube material_tex_envmap;

/* variables, global */

/* functions */

#endif /* #if !defined(UKACHULLDCS_08961_SHADER_GLSL_COMMON_UNIFORMS_GLSL) */
