/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
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

//#include <>

/* constants */

/* types, internal (enum, struct, union, typedef) */

/* variables, uniform */

/* variables, global */

/* functions */

float
fresnel_factor(in float shininess, in vec3 reflection, const in vec3 normal)
{
  float result = 0.0;
  
  if (0.0 < shininess) {
    float exponent = 128.0 / shininess;
    
    result = pow(max(0.0, (1.0 - max(dot(normal, reflection), 0.0))), exponent);
  }
  
  return result;
}

vec3
gamma_correction(in vec3 color, in float exponent)
{
  return pow(clamp(color, vec3(0.0, 0.0, 0.0), color), vec3(exponent));
}

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

vec2
texcoord_sphere(in vec3 reflection)
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
