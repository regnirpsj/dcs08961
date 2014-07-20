/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/glsl/app_oglplus_02_fs.glsl                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_02_FS_GLSL)

#define UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_02_FS_GLSL

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

/* variables, global */

in vs_out_t {
       vec3 position_wc;
       vec3 normal_wc;
  flat uint mtl_id;
} fs_in;

layout (location = 0) out vec4 color;

/* functions */

void
main()
{
  color  = vec4(0.5, 0.5, 0.5, 1.0);
  color *= dot(vec4(0.0, 0.0, -1.0, 1.0), vec4(fs_in.normal_wc, 1.0));
}

#endif /* #if !defined(UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_02_FS_GLSL) */
