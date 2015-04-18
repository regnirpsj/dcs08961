# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014-2015 University of Hull                                                       #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(FreeGLUT ${FREEGLUT_MINIMUM_VERSION} REQUIRED)
find_package(GLEW                                 REQUIRED)
find_package(GLM      ${GLM_MINIMUM_VERSION}      REQUIRED)
find_package(OGLplus                              REQUIRED)

include_directories(SYSTEM ${FreeGLUT_INCLUDE_DIR})
include_directories(SYSTEM ${GLEW_INCLUDE_DIRS})
include_directories(SYSTEM ${GLM_INCLUDE_DIR})
include_directories(SYSTEM ${OGLplus_INCLUDE_DIRS})
include_directories(       ${CMAKE_CURRENT_SOURCE_DIR})

set(SRC)
list(APPEND SRC "glut.cpp")
list(APPEND SRC "light.cpp")
list(APPEND SRC "model.cpp")
list(APPEND SRC "stats.cpp")

set(LIBS)
list(APPEND LIBS support)
list(APPEND LIBS ${FreeGLUT_LIBRARY})
list(APPEND LIBS ${GLEW_LIBRARY})

set(LIB "app_common")

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

add_subdirectory(test EXCLUDE_FROM_ALL)
