# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

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

  MESSAGE(STATUS "Setting architecture to ${ARCH}")
ENDIF()

# Boost
SET(BOOST_MINIMUM_VERSION "1.53.0")

# defaults for 3rd-party tools
IF(UNIX)
  # GLM
  SET(GLM_INCLUDE_DIR "~/Projects/others/glm-regnirpsj-git")
  # GLI
  SET(GLI_INCLUDE_DIR "~/Projects/others/gli-regnirpsj-git")
ENDIF()

IF(WIN32 OR WIN64)
  # AntTweakBar
  SET(ATB_ROOT_DIR "C:/Tools/anttweakbar/1.16")

  # Boost
  SET(BOOST_ROOT "C:/Tools/boost/1.54.0")
  IF(WIN64)
    SET(BOOST_LIBRARYDIR "${BOOST_ROOT}/stage/lib64")
  ELSE()
    SET(BOOST_LIBRARYDIR "${BOOST_ROOT}/stage/lib32")
  ENDIF()
  IF(NOT EXISTS "${BOOST_LIBRARYDIR}" OR NOT IS_DIRECTORY "${BOOST_LIBRARYDIR}")
    UNSET(BOOST_LIBRARYDIR)
  ENDIF()

  # GLM
  SET(GLM_INCLUDE_DIR "C:/Tools/glm/0.9.4.1")

  # GLI
  SET(GLI_INCLUDE_DIR "C:/Tools/gli/gli-git")
ENDIF()

IF(DCSC08961_TRACE_ALL)
  ADD_DEFINITIONS("-DUKACHULLDCS_ALL_TRACE")
ENDIF()
