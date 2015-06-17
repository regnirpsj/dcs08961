/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/glsl/app_oglplus_01.fs.glsl                                         */
/*  project    :                                                                                  */
/*  description:  liberated from oglplus example '007_glm_boxes.cpp'                              */
/*                                                                                                */
/**************************************************************************************************/

#version 430 core

#if !defined(UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_01_FS_GLSL)

#define UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_01_FS_GLSL

/* constants */

/* types, internal (enum, struct, union, typedef) */

/* variables, uniform */

layout (std430) buffer DiffuseListBuf {
  vec3 DiffuseList[];
};

/* variables, global */

in  vec3 vertColor;
out vec3 fragColor;

/* functions */

void
main()
{
  fragColor = vertColor;

  if (0 < DiffuseList.length()) {
    fragColor.xyz *= DiffuseList[0];
  } else {
    fragColor.xyz *= 1.05;
  }
}

#endif /* #if !defined(UKACHULLDCS_08961_APP_OGLPLUS_GLSL_APP_OGLPLUS_01_FS_GLSL) */
