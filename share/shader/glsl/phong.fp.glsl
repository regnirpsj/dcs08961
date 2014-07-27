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

#if !defined(UKACHULLDCS_08961_SHADER_GLSL_PHONG_FP_GLSL)

#define UKACHULLDCS_08961_SHADER_GLSL_PHONG_FP_GLSL

#version 430 core
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

in fp_in_t {
       vec3  position_wc;
       vec3  normal_wc;
       vec2  tcoords;
  flat int   mtl_id;
} fp_in;

out vec4 fp_out;

/* functions */

void
main()
{
  material_t material = material_get(fp_in.mtl_id);
  vec3       ambient  = const_color_black.rgb;
  vec3       diffuse  = const_color_black.rgb;
  vec3       specular = const_color_black.rgb;

  fp_in.normal_wc = normalize(fp_in.normal_wc);
  
  light_accumulate(/* in */     fp_in.position_wc, fp_in.normal_wc, material.shininess,
                   /* in/out */ ambient, diffuse, specular);

  vec3  incident       = inverse(xform_view)[3].xyz - fp_in.position_wc;
  vec3  reflection     = normalize(reflect(incident, fp_in.normal_wc));
  float fresnel_factor = fresnel_factor(material.shininess, reflection, fp_in.normal_wc);
  
  fp_out = material_shading(/* in */ material, ambient, diffuse, specular,
                            /* in */ texture(material_tex_diffuse, fp_in.tcoords).rgb,
                            /* in */ texture(material_tex_envmap,  reflection)   .rgb,
                            /* in */ fresnel_factor);
}

#endif /* #if !defined(UKACHULLDCS_08961_SHADER_GLSL_PHONG_FP_GLSL) */
