/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/01.vs.glsl                                                          */
/*  project    :                                                                                  */
/*  description:  liberated from oglplus example '007_glm_boxes.cpp'                              */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_APP_OGLPLUS_01_VS_GLSL)

#define UKACHULLDCS_08961_APP_OGLPLUS_01_VS_GLSL

#version 330

/* constants */

/* types, internal (enum, struct, union, typedef) */

/* variables, uniform */

uniform mat4  CameraMatrix;
uniform mat4  ScaleMatrix;
uniform vec3  LightPos;
uniform float Time;

/* variables, global */

in  vec4 Position;
in  vec3 Normal;
out vec3 vertColor;

/* functions */

void
main()
{
  float angle       = gl_InstanceID * 10 * 2 * 3.14159 / 360.0;
  float ct          = cos(angle + Time);
  float st          = sin(angle + Time);
  mat4  ModelMatrix = (mat4(  ct, 0.0,  st, 0.0,
                             0.0, 1.0, 0.0, 0.0,
                             -st, 0.0,  ct, 0.0,
                             0.0, 0.0, 0.0, 1.0) *
                       mat4( 1.0, 0.0, 0.0, 0.0,
                             0.0, 1.0, 0.0, 0.0,
                             0.0, 0.0, 1.0, 0.0,
                            12.0, 0.0, 0.0, 1.0) *
                       mat4(  ct, -st, 0.0, 0.0,
                              st,  ct, 0.0, 0.0,
                             0.0, 0.0, 1.0, 0.0,
                             0.0, 0.0, 0.0, 1.0));
  
  gl_Position = ModelMatrix * ScaleMatrix * Position;

  vec3 vertLightDir = normalize(LightPos - gl_Position.xyz);
  vec3 vertNormal   = normalize((ModelMatrix * vec4(Normal, 0.0)).xyz);

  gl_Position = CameraMatrix * gl_Position;
    
  vertColor = (abs(normalize(Normal - vec3(1.0, 1.0, 1.0) +
                             (Position.xyz * 0.2))) *
               (0.7 + 0.5 * max(dot(vertNormal, vertLightDir), 0.0)));
}

#endif /* #if !defined(UKACHULLDCS_08961_APP_OGLPLUS_01_VS_GLSL) */
