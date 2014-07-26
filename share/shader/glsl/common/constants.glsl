/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  shader/glsl/common/constants.glsl                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SHADER_GLSL_COMMON_CONSTANTS_GLSL)

#define UKACHULLDCS_08961_SHADER_GLSL_COMMON_CONSTANTS_GLSL

/* includes, system */

//#include <>

/* includes, project */

//#include <>

/* constants */

const float const_pi = 3.14159265358979323844;

const vec4 const_color_ambient = vec4(0.2, 0.2, 0.2, 1.0); // <= gl_LightModel.ambient
const vec4 const_color_black   = vec4(0.0, 0.0, 0.0, 1.0);
const vec4 const_color_blue    = vec4(0.0, 0.0, 1.0, 1.0);
const vec4 const_color_green   = vec4(0.0, 1.0, 0.0, 1.0);
const vec4 const_color_red     = vec4(1.0, 0.0, 0.0, 1.0);
const vec4 const_color_white   = vec4(1.0, 1.0, 1.0, 1.0);

// see RTR3 p.215f
const vec3 intensity_conv = vec3(0.212671, 0.715160, 0.072169);

/* types, internal (enum, struct, union, typedef) */

/* variables, uniform */

/* variables, global */

/* functions */

#endif /* #if !defined(UKACHULLDCS_08961_SHADER_GLSL_COMMON_CONSTANTS_GLSL) */
