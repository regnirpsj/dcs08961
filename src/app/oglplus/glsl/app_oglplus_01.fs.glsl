/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/01.fs.glsl                                                          */
/*  project    :                                                                                  */
/*  description:  liberated from oglplus example '007_glm_boxes.cpp'                              */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_APP_OGLPLUS_01_FS_GLSL)

#define UKACHULLDCS_08961_APP_OGLPLUS_01_FS_GLSL

#version 330

/* constants */

/* types, internal (enum, struct, union, typedef) */

/* variables, uniform */

/* variables, global */

in  vec3 vertColor;
out vec3 fragColor;

/* functions */

void
main()
{
  fragColor      = vertColor;
  fragColor.xyz *= 1.05;
}

#endif /* #if !defined(UKACHULLDCS_08961_APP_OGLPLUS_01_FS_GLSL) */
