# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

if(VERBOSE)
  message(STATUS "Loading ${PROJECT_NAME} variables")
endif()

include(CMakeAddons_SetupVariables)

# AntTweakBar
if(CMAKE_HOST_WIN32)
  set(AntTweakBar_ROOT_DIR "C:/Tools/anttweakbar/1.16")
endif()

# Freeglut
set(FREEGLUT_MINIMUM_VERSION "2.8")
if(CMAKE_HOST_WIN32)
  set(FreeGLUT_ROOT_DIR "C:/Tools/freeglut/3.0.0-src/install/${ARCH}")
endif()

# GLEW
if(CMAKE_HOST_WIN32)
  set(GLEW_ROOT_DIR "C:/Tools/glew/1.12.0")
  set(GLEW_COMPONENTS "COMPONENTS STATIC")
endif()

# GL[I|M]
set(GLI_MINIMUM_VERSION "0.8.0")
set(GLM_MINIMUM_VERSION "0.9.7")
if(CMAKE_HOST_WIN32)
  set(GLI_ROOT_DIR "C:/Tools/gli/gli-git")
  set(GLM_ROOT_DIR "C:/Tools/glm/glm-git")
elseif(CMAKE_HOST_UNIX)
  set(GLI_ROOT_DIR "~/Projects/others/gli-git")
  set(GLM_ROOT_DIR "~/Projects/others/glm-regnirpsj-git")
endif()

# OGLplus
if(CMAKE_HOST_WIN32)
  set(OGLplus_ROOT_DIR "C:/Tools/oglplus/oglplus-develop-git/_install")
elseif(CMAKE_HOST_UNIX)
  # set(OGLplus_ROOT_DIR "~/Projects/others/oglplus-master-git/_install")
  set(OGLplus_ROOT_DIR "~/Projects/others/oglplus-develop-git/_install")
  # set(OGLplus_ROOT_DIR "~/Projects/others/oglplus-regnirpsj-git/_install")
endif()

# WindowsSDK
if(CMAKE_HOST_WIN32)
  set(WINSDK_MINIMUM_VERSION 8.0)
endif()

if(DCS08961_TRACE_ALL)
  if(VERBOSE)
    message(STATUS "Enabling run-time tracing for complete project!")
  endif()
  add_definitions("-DUKACHULLDCS_ALL_TRACE")
endif()
