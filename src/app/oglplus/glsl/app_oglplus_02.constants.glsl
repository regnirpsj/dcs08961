/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/glsl/app_oglplus_02.constants.glsl                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_02_CONSTANTS_GLSL)

#define UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_02_CONSTANTS_GLSL

#version 430 core
// #extension GL_ARB_shading_language_include : require

/* includes, system */

//#include <>

/* includes, project */

//#include <>

/* constants */

const vec4 const_color_ambient = vec4(0.2, 0.2, 0.2, 1.0); // <= gl_LightModel.ambient
const vec4 const_color_black   = vec4(0.0, 0.0, 0.0, 1.0);
const vec4 const_color_white   = vec4(1.0, 1.0, 1.0, 1.0);

/* types, internal (enum, struct, union, typedef) */

/* variables, uniform */

/* variables, global */

/* functions */

#endif /* #if !defined(UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_02_CONSTANTS_GLSL) */
