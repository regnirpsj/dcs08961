# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014-2015 University of Hull                                                       #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(Boost    ${BOOST_MINIMUM_VERSION}    REQUIRED COMPONENTS filesystem system)
find_package(FreeGLUT ${FREEGLUT_MINIMUM_VERSION} REQUIRED)
find_package(GLEW                                 REQUIRED ${GLEW_COMPONENTS})
find_package(GLM      ${GLM_MINIMUM_VERSION}      REQUIRED)
find_package(OGLplus                              REQUIRED)

include_directories(SYSTEM ${Boost_INCLUDE_DIR})
include_directories(SYSTEM ${FreeGLUT_INCLUDE_DIR})
include_directories(SYSTEM ${GLEW_INCLUDE_DIR})
include_directories(SYSTEM ${GLM_INCLUDE_DIR})
include_directories(SYSTEM ${OGLplus_INCLUDE_DIRS})
include_directories(       ${CMAKE_CURRENT_SOURCE_DIR})

set(SRC)
list(APPEND SRC "application.cpp")
list(APPEND SRC "main.cpp")
list(APPEND SRC "model.cpp")
list(APPEND SRC "stats.cpp")
list(APPEND SRC "window.cpp")

add_definitions(${GLEW_DEFINITIONS})

if("xClang" STREQUAL "x${CMAKE_CXX_COMPILER_ID}")
  add_definitions("-DOGLPLUS_NO_INITIALIZER_LISTS=0")
endif()

set(LIBS)
list(APPEND LIBS platform_glut)
list(APPEND LIBS platform_oglplus)
list(APPEND LIBS platform)
list(APPEND LIBS support)
list(APPEND LIBS ${FreeGLUT_LIBRARY})
list(APPEND LIBS ${GLEW_LIBRARY})
list(APPEND LIBS ${Boost_LIBRARIES})

set(APP "oglplus_viewer")

cma_setup_application(${APP} SOURCES ${SRC} DEPENDENCIES ${LIBS})

add_dependencies(app_${APP} glsl_shader)
