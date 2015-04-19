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

# GL[I|M]
set(GLI_MINIMUM_VERSION "0.6.0")
set(GLM_MINIMUM_VERSION "0.9.7")
if(CMAKE_HOST_WIN32)
  set(GLI_ROOT_DIR "C:/Tools/gli/gli-git")
  set(GLM_ROOT_DIR "C:/Tools/glm/glm-git")
elseif(UNIX)
  set(GLI_ROOT_DIR "~/Projects/others/gli-git")
  set(GLM_ROOT_DIR "~/Projects/others/glm-git")
endif()

# freeglut
set(FREEGLUT_MINIMUM_VERSION "2.8")
if(CMAKE_HOST_WIN32)
  set(FreeGLUT_ROOT_DIR "C:/Tools/freeglut/3.0.0-src/install/${ARCH}")
endif()

# OGLplus
if(CMAKE_HOST_WIN32)
  set(OGLplus_ROOT_DIR "C:/Tools/oglplus/oglplus-git")
else()
  if(UNIX)
    set(OGLplus_ROOT_DIR "~/Projects/others/oglplus-develop-git/_install")
  endif()
endif()

# GLEW
# keeping this last because of 'CMAKE_*_PATH' tinkering
if(CMAKE_HOST_WIN32)
  set(GLEW_ROOT_PATH "C:/Tools/glew/1.12.0")
  set(CMAKE_PREFIX_PATH  "${GLEW_ROOT_PATH}")
  set(CMAKE_LIBRARY_PATH "${GLEW_ROOT_PATH}/lib/Release/${ARCH}")
endif()

if(DCS08961_TRACE_ALL)
  if(VERBOSE)
    message(STATUS "Enabling run-time tracing for complete project!")
  endif()
  add_definitions("-DUKACHULLDCS_ALL_TRACE")
endif()
