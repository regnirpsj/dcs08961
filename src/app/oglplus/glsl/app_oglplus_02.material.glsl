/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/glsl/app_oglplus_02.material.glsl                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_02_MATERIAL_GLSL)

#define UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_02_MATERIAL_GLSL

#version 430 core
#extension GL_ARB_shading_language_include : require

/* includes, system */

//#include <>

/* includes, project */

#include <app_oglplus_02.constants.glsl>

/* constants */

/* types, internal (enum, struct, union, typedef) */

struct material_t {
  vec3  ambient;
  float refraction;
  vec3  diffuse;
  float shininess;
  vec3  emission;
  float alpha;
  vec3  specular;
  bool  front;
  vec3  transmission;
  bool  back;
};

/* variables, uniform */

layout (std430) buffer material_list_t {
  material_t material_list[];
};

/* variables, global */

/* functions */

vec4
material_shading(in int  idx,
                 in vec3 light_ambient,
                 in vec3 light_diffuse,
                 in vec3 light_specular)
{
  material_t mtl    = material_list[(0 > idx) ? 0 : idx];
  vec4       result = vec4(mtl.emission, mtl.alpha);

  result.rgb  += mtl.ambient  * light_ambient;
  result.rgb  += mtl.diffuse  * light_diffuse;
  result.rgb  += mtl.specular * light_specular;

  return result;
}

#endif /* #if !defined(UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_02_MATERIAL_GLSL) */
