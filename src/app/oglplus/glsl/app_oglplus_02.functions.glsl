/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/glsl/app_oglplus_02.functions.glsl                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_02_FUNCTIONS_GLSL)

#define UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_02_FUNCTIONS_GLSL

// #version 430 core
// #extension GL_ARB_shading_language_include : require

/* includes, system */

//#include <>

/* includes, project */

//#include <>

/* constants */

/* types, internal (enum, struct, union, typedef) */

/* variables, uniform */

/* variables, global */

/* functions */

vec4
lit(in float NdotL, in float NdotH, in float m)
{ 
  float ambient  = 1.0;
  float diffuse  = max(NdotL, 0.0);
  float specular = step(0.0, NdotL) * max(NdotH * m, 0.0);
 
  return vec4(ambient, diffuse, specular, 1.0);
}

float saturate(in float a) { return clamp(a, 0.0, 1.0); }
vec2  saturate(in vec2 a)  { return clamp(a, 0.0, 1.0); }
vec3  saturate(in vec3 a)  { return clamp(a, 0.0, 1.0); }
vec4  saturate(in vec4 a)  { return clamp(a, 0.0, 1.0); }

#endif /* #if !defined(UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_02_FUNCTIONS_GLSL) */
