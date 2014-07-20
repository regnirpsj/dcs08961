/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/glsl/app_oglplus_02.vs.glsl                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_02_VS_GLSL)

#define UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_02_VS_GLSL

#version 420 core
// #extension GL_ARB_shading_language_include : require

/* includes, system */

//#include <>

/* includes, project */

//#include <>

/* constants */

/* types, internal (enum, struct, union, typedef) */

/* variables, uniform */

uniform mat4x4 model;
uniform mat4x4 view;
uniform mat4x4 proj;
uniform uvec2  screen;
uniform uint   mtl_id;

/* variables, global */

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 normal;

out vs_out_t {
       vec3 position_wc;
       vec3 normal_wc;
  flat uint mtl_id;
} vs_out;

/* functions */

void
main()
{
  gl_Position = proj * view * model * position;

  vs_out.position_wc =                            (model   * position).xyz;
  vs_out.normal_wc   = normalize(transpose(inverse(model)) * normal).xyz;
  vs_out.mtl_id      = mtl_id;
}

#endif /* #if !defined(UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_02_VS_GLSL) */
