/* -*- Mode:C -*- */

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  shader/glsl/common/config.glsl                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SHADER_GLSL_COMMON_CONFIG_GLSL)

#define UKACHULLDCS_08961_SHADER_GLSL_COMMON_CONFIG_GLSL

#pragma optionNV(strict on)

#define MAXIMUM_PERFORMANCE

#if defined(MAXIMUM_PERFORMANCE)
#  pragma optimize(on)
#  pragma optionNV(fastmath      on)
#  pragma optionNV(fastprecision on)
#  pragma optionNV(unroll        all)
#  pragma optionNV(inline        all)
#  pragma optionNV(ifcvt         all)
#else
#  pragma optimize(off)
#  pragma optionNV(fastmath      off)
#  pragma optionNV(fastprecision off)
#  pragma optionNV(ifcvt         none)
#endif

#endif /* #if !defined(UKACHULLDCS_08961_SHADER_GLSL_COMMON_CONFIG_GLSL) */
