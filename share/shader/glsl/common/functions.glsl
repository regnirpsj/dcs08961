/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  shader/glsl/common/functions.glsl                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SHADER_GLSL_COMMON_FUNCTIONS_GLSL)

#define UKACHULLDCS_08961_SHADER_GLSL_COMMON_FUNCTIONS_GLSL

/* includes, system */

//#include <>

/* includes, project */

#include <common/constants.glsl>

/* constants */

/* types, internal (enum, struct, union, typedef) */

/* variables, uniform */

/* variables, global */

/* functions */

float
fresnel_factor(in const float shininess, in const vec3 reflection, in const vec3 normal)
{
  float result = 0.0;
  
  if (0.0 < shininess) {
    float exponent = 128.0 / shininess;
    
    result = pow(max(0.0, (1.0 - max(dot(normal, reflection), 0.0))), exponent);
  }
  
  return result;
}

vec3
gamma_correction(in const vec3 color, in const float exponent)
{
  return pow(clamp(color, const_color_black.rgb, color), vec3(exponent));
}

vec4
lit(in const float NdotL, in const float NdotH, in const float exponent)
{ 
  float ambient  = 1.0;
  float diffuse  = max(NdotL, 0.0);

#if 0
  float specular = step(0.0, NdotL) * max(NdotH * exponent, 0.0);
#else
  float specular = (min(NdotL, NdotH) < 0.0) ? 0.0 : pow(NdotH, exponent);
#endif
  
  return vec4(ambient, diffuse, specular, 1.0);
}

float saturate(in const float a) { return clamp(a, 0.0, 1.0); }
vec2  saturate(in const vec2 a)  { return clamp(a, 0.0, 1.0); }
vec3  saturate(in const vec3 a)  { return clamp(a, 0.0, 1.0); }
vec4  saturate(in const vec4 a)  { return clamp(a, 0.0, 1.0); }

vec2
texcoord_sphere(in const vec3 reflection)
{
#if 0
  float m = 2.0 * sqrt(dot(reflection + vec3(0.0, 0.0, 1.0),
                           reflection + vec3(0.0, 0.0, 1.0)));
#else
  float m = 2.0 * sqrt(((reflection.x + 0.0) * (reflection.x + 0.0)) +
                       ((reflection.y + 0.0) * (reflection.y + 0.0)) +
                       ((reflection.z + 1.0) * (reflection.z + 1.0)));
#endif
  
  return (reflection.xy / m) + 0.5;
}

#endif /* #if !defined(UKACHULLDCS_08961_SHADER_GLSL_COMMON_FUNCTIONS_GLSL) */
