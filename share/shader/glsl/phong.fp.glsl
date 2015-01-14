/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  shader/gls/phong.fp.glsl                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#version 430 core

#if !defined(UKACHULLDCS_08961_SHADER_GLSL_PHONG_FP_GLSL)

#define UKACHULLDCS_08961_SHADER_GLSL_PHONG_FP_GLSL

#extension GL_ARB_shading_language_include : enable

/* includes, system */

//#include <>

/* includes, project */

#include <common/config.glsl>
#include <common/phong.glsl>
#include <common/uniforms.glsl>

/* constants */

/* types, internal (enum, struct, union, typedef) */

/* variables, uniform */

/* variables, global */

in vp_out_t {
       vec3  position_wc;
       vec3  normal_wc;
       vec2  tcoords;
  flat int   mtl_id;
} vp_out;

out vec4 fp_out;

/* functions */

void
main()
{
  material_t material     = material_get(vp_out.mtl_id);
  vec3       ambient      = const_color_black.rgb;
  vec3       diffuse      = const_color_black.rgb;
  vec3       specular     = const_color_black.rgb;
  mat4       xform_camera = inverse(xform_view);
  
  vp_out.normal_wc = normalize(vp_out.normal_wc);
  
  light_accumulate(/* in */     vp_out.position_wc,
                   /* in */     vp_out.normal_wc,
                   /* in */     xform_camera,
                   /* in */     material.shininess,
                   /* in/out */ ambient, diffuse, specular);

  vec3  incident       = xform_camera[3].xyz - vp_out.position_wc;
  vec3  reflection     = normalize(reflect(incident, vp_out.normal_wc));
  float fresnel_factor = fresnel_factor(material.shininess, reflection, vp_out.normal_wc);
  
  fp_out = material_shading(/* in */ material, ambient, diffuse, specular,
                            /* in */ material_tex_diffuse_enabled,
                            /* in */ texture(material_tex_diffuse, vp_out.tcoords).rgb,
                            /* in */ material_tex_envmap_enabled,
                            /* in */ texture(material_tex_envmap,  reflection)    .rgb,
                            /* in */ fresnel_factor);
}

#endif /* #if !defined(UKACHULLDCS_08961_SHADER_GLSL_PHONG_FP_GLSL) */
