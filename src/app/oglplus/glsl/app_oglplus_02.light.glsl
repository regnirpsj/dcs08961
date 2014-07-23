/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/glsl/app_oglplus_02.light.glsl                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_02_LIGHT_GLSL)

#define UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_02_LIGHT_GLSL

//#version 430 core
//#extension GL_ARB_shading_language_include : require

/* includes, system */

//#include <>

/* includes, project */

#include <app_oglplus_02.constants.glsl>

/* constants */

/* types, internal (enum, struct, union, typedef) */

struct light_t {
  vec4  position;
  vec3  direction;
  bool  enabled;
  vec3  ambient;
  float exponent;    // [0, 128], spot exponent describes light distribution in the spot cone
  vec3  diffuse;
  float cutoff;      // [0, 90] || 180, this is the half-angle of the spot cone
  vec3  specular;    
  float pad0;
  vec3  attenuation; // [c,l,q], for 1/(q*d^2+l*d+c)
  float pad1;
};

struct light_cone_parameter_t {
  float cos_inner_angle;
  float cos_outer_angle;
  float diff_inner_outer;
  bool  compute_falloff_spot;
};

/* variables, uniform */

layout (std430) buffer light_list_t {
  light_t light_list[];
};

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

vec3
light_vector(in light_t l, in vec3 P)
{
  vec4 result = l.position; // directional: lvec = lpos
  
  if (0.0 != result.w) {
    result.xyz -= P;        // positional:  lvec = lpos - opos
  } 
  
  return result.xyz;
} 

float
light_attenuation(in light_t l, in float d)
{
  float attenuation_at_lpos_infty = 1.0;
  
  return ((0.0 != l.position.w)
          ? 1.0 / ((l.attenuation.x        ) +
                   (l.attenuation.y * d    ) +
                   (l.attenuation.z * d * d))
          : attenuation_at_lpos_infty); 
}

light_cone_parameter_t
setup_light_cone(in light_t l)
{
  light_cone_parameter_t result = { 0.0, 0.0, 0.0, false };

  result.compute_falloff_spot = ((0.0 != l.position.w) && (180.0 != l.cutoff));

  if (result.compute_falloff_spot) {
    float cos_cutoff = cos(radians(l.cutoff));

    result.cos_outer_angle  = saturate(cos_cutoff);

    // inner = (1 - (spotExp / 128)) * outer
    result.cos_inner_angle  = saturate(cos(radians((1.0 - (l.exponent / 128.0)) * cos_cutoff)));
    result.diff_inner_outer = (result.cos_inner_angle - result.cos_outer_angle);
  }

  return result;
}

void
light_accumulate(in    vec3  P, // fragment position (wc)
                 in    vec3  N, // fragment normal (wc)
                 in    float material_shininess,
                 inout vec3  ambient,
                 inout vec3  diffuse,
                 inout vec3  specular)
{
  for (uint i = 0; i < light_list.length(); ++i) {
    if (light_list[i].enabled) {
      vec3  L           = light_vector     (light_list[i], P);
      float attenuation = light_attenuation(light_list[i], length(L));

      L = normalize(L);

      float NdotL = dot(N, L);

      if (0.0 < NdotL) {
        light_cone_parameter_t lcp = setup_light_cone(light_list[i]);

        if (lcp.compute_falloff_spot) {
          float cos_cur_angle = dot(-L, normalize(light_list[i].direction));

          // avoids dynamic branching
          attenuation *= saturate((cos_cur_angle - lcp.cos_outer_angle) / lcp.diff_inner_outer);
        }

        vec3  H          = normalize(L - normalize(P));
        float NdotH      = max(dot(N, H), 0.0);
        float exponent   = max(128.0 / material_shininess, 0.0);
        vec4  lit_result = lit(NdotL, NdotH, exponent);

        diffuse  += (attenuation * light_list[i].diffuse  * lit_result.y);
        specular += (attenuation * light_list[i].specular * lit_result.z);
      }

      ambient += attenuation * light_list[i].ambient;
    }
  }
}

#endif /* #if !defined(UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_02_LIGHT_GLSL) */
