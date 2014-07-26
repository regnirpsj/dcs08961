/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  shader/glsl/common/material.glsl                                                */
/*  project    :                                                                                  */
/*  description:  types only for inclusion in both c++ and glsl                                   */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SHADER_GLSL_COMMON_MATERIAL_GLSL)

#define UKACHULLDCS_08961_SHADER_GLSL_COMMON_MATERIAL_GLSL

/* includes, system */

//#include <>

/* includes, project */

//#include <>

/* constants */

/* types, internal (enum, struct, union, typedef) */

struct material_t {
  vec3  ambient;      // Ka
  float refraction;   // idx
  vec3  diffuse;      // Kd
  float shininess;    // exp
  vec3  emission;     // Ke
  float alpha;        // 1 - Tr (?)
  vec3  specular;     // Ks
  bool  front;
  vec3  transmission; // Tr
  bool  back;
};

/* variables, uniform */

/* variables, global */

/* functions */

#endif /* #if !defined(UKACHULLDCS_08961_SHADER_GLSL_COMMON_MATERIAL_GLSL) */
