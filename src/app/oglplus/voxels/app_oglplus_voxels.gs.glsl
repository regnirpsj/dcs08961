/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/voxels/app_oglplus_voxels.gs.glsl                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#version 430 core

#if !defined(UKACHULLDCS_08961_APP_OGLPLUS_VOXELS_APP_OGLPLUS_VOXELS_GS_GLSL)

#define UKACHULLDCS_08961_APP_OGLPLUS_VOXELS_APP_OGLPLUS_VOXELS_GS_GLSL

/* includes, system */

//#include <>

/* includes, project */

//#include <>

/* constants */

/* types, internal (enum, struct, union, typedef) */

/* variables, uniform */

/* variables, global */

/* out vp_out_t { */
/*        vec3  position_wc; */
/*        vec3  normal_wc; */
/*        vec2  tcoords; */
/*   flat int   mtl_id; */
/* } vp_out; */

layout(triangles)                        in;
layout(triangle_strip, max_vertices = 3) out;
                  
/* functions */

void
main()
{
  for (uint i = 0; i < 3; ++i) {
    gl_Position = gl_in[i].gl_Position;
    EmitVertex();
  }
  
  EndPrimitive();
}

#endif /* #if !defined(UKACHULLDCS_08961_APP_OGLPLUS_VOXELS_APP_OGLPLUS_VOXELS_GS_GLSL) */
