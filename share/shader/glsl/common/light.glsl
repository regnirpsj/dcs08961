/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  shader/glsl/common/light.glsl                                                   */
/*  project    :                                                                                  */
/*  description:  types only for inclusion in both c++ and glsl                                   */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SHADER_GLSL_COMMON_LIGHT_GLSL)

#define UKACHULLDCS_08961_SHADER_GLSL_COMMON_LIGHT_GLSL

/* includes, system */

//#include <>

/* includes, project */

//#include <>

/* constants */

/* types, internal (enum, struct, union, typedef) */

struct light_t {
  vec4  position;    // [x,y,z,w] w=0:directional, w=1:positional
  vec3  direction;   // [x,y,z]
  bool  enabled;     // no default in opengl
  vec3  ambient;     // ka
  float exponent;    // [0, 128], spot exponent describes light distribution in the spot cone
  vec3  diffuse;     // kd
  float cutoff;      // [0, 90] || 180 ([0, PI/2] || PI), this is the half-angle of the spot cone
  vec3  specular;    // ks
  float pad0;
  vec3  attenuation; // [c,l,q], for 1/((q*d^2) + (l*d) + c)
  float pad1;
};

/* variables, uniform */

/* variables, global */

/* functions */

#endif /* #if !defined(UKACHULLDCS_08961_SHADER_GLSL_COMMON_LIGHT_GLSL) */
