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

#version 430 core
#extension GL_ARB_shading_language_include : require

/* includes, system */

#include <app_oglplus_02.uniforms.glsl>

/* includes, project */

//#include <>

/* constants */

/* types, internal (enum, struct, union, typedef) */

/* variables, uniform */

/* variables, global */

in vec4 position;
in vec4 normal;
in vec2  tcoords;
in float mtl_id;

out vs_out_t {
       vec3 position_wc;
       vec3 normal_wc;
       vec2 tcoords;
  flat int  mtl_id;
} vs_out;

/* functions */

void
main()
{
  gl_Position = proj * view * model * position;

  vs_out.position_wc =                            (model   * position).xyz;
  vs_out.normal_wc   = normalize(transpose(inverse(model)) * normal).xyz;
  vs_out.tcoords     = tcoords;
  vs_out.mtl_id      = int(mtl_id);
}

#endif /* #if !defined(UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_02_VS_GLSL) */
