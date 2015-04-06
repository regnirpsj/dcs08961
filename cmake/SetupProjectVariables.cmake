# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

SET(ARCH "unknown")

IF(UNIX)
  EXECUTE_PROCESS(COMMAND uname -m OUTPUT_VARIABLE ARCH OUTPUT_STRIP_TRAILING_WHITESPACE)
ENDIF()

# 32-bit vs. 64-bit platform
# unfortunatly, M$ are completely inconsistent in how they name directories (e.g., x64 vs. amd64),
# which is why no architecture variable is set here as well
IF(MSVC AND CMAKE_CL_64)
  MESSAGE(STATUS "Enabling settings for WIN64")
  SET(WIN64 1)
ELSE()
  SET(WIN64 0)
ENDIF()

IF(WIN32 OR WIN64)
  SET(ARCH x86)

  IF(WIN64)
    SET(ARCH x64)
  ENDIF()
ENDIF()

# Boost
SET(BOOST_MINIMUM_VERSION "1.55.0")

# defaults
IF(UNIX)
  # GLM
  SET(GLM_INCLUDE_DIR "~/Projects/others/glm-regnirpsj-git")

  # GLI
  SET(GLI_INCLUDE_DIR "~/Projects/others/gli-git")

  # OGL+
  SET(OGLplus_ROOT_DIR "~/Projects/others/oglplus-develop-git/_install")
  # SET(OGLplus_ROOT_DIR "~/Projects/others/oglplus-regnirpsj-git/_install")
ENDIF()

IF(WIN32 OR WIN64)
  # install: CMAKE_INSTALL_PREFIX
  STRING(TOLOWER ${CMAKE_PROJECT_NAME} PREFIX)
  SET(CMAKE_INSTALL_PREFIX "C:/Tools/${PREFIX}")

  # AntTweakBar
  SET(ATB_ROOT_DIR "C:/Tools/anttweakbar/1.16")

  # Boost
  SET(BOOST_ROOT "C:/Tools/boost/1.57.0")
  IF(WIN64)
    SET(BOOST_LIBRARYDIR "${BOOST_ROOT}/lib64-msvc-12.0")
  ELSE()
    SET(BOOST_LIBRARYDIR "${BOOST_ROOT}/lib32-msvc-12.0")
  ENDIF()
  IF(NOT EXISTS "${BOOST_LIBRARYDIR}" OR NOT IS_DIRECTORY "${BOOST_LIBRARYDIR}")
    UNSET(BOOST_LIBRARYDIR)
  ENDIF()

  # GLM
  SET(GLM_INCLUDE_DIR "C:/Tools/glm/regnirpsj-git")

  # GLI
  SET(GLI_INCLUDE_DIR "C:/Tools/gli/regnirpsj-git")
  
  # GLEW
  SET(GLEW_ROOT_PATH "C:/Tools/glew/1.12.0")
  SET(CMAKE_LIBRARY_PATH "${GLEW_ROOT_PATH}/lib/Release/${ARCH}")
  set(CMAKE_PREFIX_PATH  "${GLEW_ROOT_PATH}")

  # GLUT
  SET(GLUT_ROOT_PATH "C:/Tools/freeglut/3.0.0-src/install/${ARCH}")
  SET(GLUT_INCLUDE_DIR "${GLUT_ROOT_PATH}/include")
  SET(GLUT_LIBRARIES   "${GLUT_ROOT_PATH}/lib/freeglut_staticd.lib")
  
  # OGL+
  SET(OGLplus_ROOT_DIR "C:/Tools/oglplus/oglplus-git")
ENDIF()

IF(DCS08961_TRACE_ALL)
  ADD_DEFINITIONS("-DUKACHULLDCS_ALL_TRACE")
ENDIF()

IF(TRUE OR VERBOSE)
  MESSAGE(STATUS "Project ${CMAKE_PROJECT_NAME} defaults:\n"
    "   ARCH                  = ${ARCH}\n"
    "   CMAKE_INSTALL_PREFIX  = ${CMAKE_INSTALL_PREFIX}\n"
    "   ATB_ROOT_DIR          = ${ATB_ROOT_DIR}\n"
    "   BOOST_MINIMUM_VERSION = ${BOOST_MINIMUM_VERSION}\n"
    "   BOOST_ROOT            = ${BOOST_ROOT}\n"
    "   GLEW_ROOT_PATH        = ${GLEW_ROOT_PATH}\n"
    "   GLI_INCLUDE_DIR       = ${GLI_INCLUDE_DIR}\n"
    "   GLM_INCLUDE_DIR       = ${GLM_INCLUDE_DIR}\n"
    "   GLUT_ROOT_PATH        = ${GLUT_ROOT_PATH}\n"
    "   OGLplus_ROOT_DIR      = ${OGLplus_ROOT_DIR}\n"
    "   DCS08961_TRACE_ALL    = ${DCS08961_TRACE_ALL}")
ENDIF()
