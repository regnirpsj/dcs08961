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
#extension GL_ARB_shading_language_include : require

/* includes, system */

//#include <>

/* includes, project */

#include <common/phong.glsl>
#include <common/uniforms.glsl>

/* constants */

/* types, internal (enum, struct, union, typedef) */

/* variables, uniform */

uniform sampler2D tex_diffuse;

/* variables, global */

in fp_in_t {
       vec3 position_wc;
       vec3 normal_wc;
       vec2 tcoords;
  flat int  mtl_id;
} fp_in;

out vec4 fp_out;

/* functions */

void
main()
{
  vec3 ambient  = const_color_black.rgb;
  vec3 diffuse  = const_color_black.rgb;
  vec3 specular = const_color_black.rgb;

  light_accumulate(/* in */     fp_in.position_wc,
                   /* in */     normalize(fp_in.normal_wc),
                   /* in */     material_get(fp_in.mtl_id).shininess,
                   /* in/out */ ambient, diffuse, specular);
  
  fp_out = material_shading(/* in */ fp_in.mtl_id,
                            /* in */ ambient, diffuse, specular,
                            /* in */ texture(tex_diffuse, fp_in.tcoords).rgb);
}

#endif /* #if !defined(UKACHULLDCS_08961_SHADER_GLSL_PHONG_FP_GLSL) */
