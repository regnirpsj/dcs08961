/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  shader/glsl/common/phong.glsl                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SHADER_GLSL_COMMON_PHONG_GLSL)

#define UKACHULLDCS_08961_SHADER_GLSL_COMMON_PHONG_GLSL

/* includes, system */

//#include <>

/* includes, project */

#include <common/constants.glsl>
#include <common/functions.glsl>
#include <common/light.glsl>
#include <common/material.glsl>

/* constants */

const light_t default_light = {
  /* psition     */ vec4(0.0, 0.0, 1.0, 0.0),
  /* direction   */ vec3(0.0, 0.0,-1.0),
  /* enabled     */ false,
  /* ambient     */ vec3(0.0, 0.0, 0.0),
  /* exponent    */ 0.0,
  /* diffuse     */ vec3(1.0, 1.0, 1.0),
  /* cutoff      */ const_pi,
  /* specular    */ vec3(1.0, 1.0, 1.0),
  /* pad0        */ -1.0,
  /* attenuation */ vec3(1.0, 0.0, 0.0),
  /* pad1        */ -1.0,
};

const material_t default_material = {
  /* ambient      */ vec3(0.2, 0.2, 0.2),
  /* refraction   */ 1.0,
  /* diffuse      */ vec3(0.8, 0.8, 0.8),
  /* shininess    */ 0.0,
  /* emission     */ vec3(0.0, 0.0, 0.0),
  /* alpha        */ 1.0,
  /* specular     */ vec3(0.0, 0.0, 0.0),
  /* front        */ true,
  /* transmission */ vec3(0.0, 0.0, 0.0),
  /* back         */ false,
};

/* types, internal (enum, struct, union, typedef) */

struct light_cone_parameter_t {
  float cos_inner_angle;
  float cos_outer_angle;
  float diff_inner_outer;
  bool  compute_falloff_spot;
};

const light_cone_parameter_t default_light_cone_parameters = {
  0.0,
  0.0,
  0.0,
  false,
};

/* variables, uniform */

layout (std430) buffer light_list_t {
  light_t light_list[];
};

layout (std430) buffer material_list_t {
  material_t material_list[];
};

/* variables, global */

/* functions */

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
  light_cone_parameter_t result = default_light_cone_parameters;

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

material_t
material_get(in int idx)
{
  material_t result = default_material;

  if ((material_list.length() > idx) && (0 <= idx)) {
    result = material_list[idx];
  }

  return result;
}

vec4
material_shading(in material_t mtl,
                 in vec3       light_ambient,
                 in vec3       light_diffuse,
                 in vec3       light_specular,
                 in vec3       mtl_tex_diffuse,
                 in vec3       mtl_tex_environment,
                 in float      fresnel_factor)
{
  vec4 result = vec4(mtl.emission, mtl.alpha);

  result.rgb  += mtl.ambient  * light_ambient;
  result.rgb  += mtl.diffuse  * light_diffuse;
  result.rgb  *= mtl_tex_diffuse;
  result.rgb  += mtl.specular * light_specular;
  result.rgb   = mix(result.rgb, mtl_tex_environment, fresnel_factor);
  
  return result;
}

#endif /* #if !defined(UKACHULLDCS_08961_SHADER_GLSL_COMMON_PHONG_GLSL) */
