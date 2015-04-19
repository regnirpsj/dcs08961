# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014-2015 University of Hull                                                       #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(Boost    ${BOOST_MINIMUM_VERSION}    REQUIRED COMPONENTS filesystem system)
find_package(FreeGLUT ${FREEGLUT_MINIMUM_VERSION} REQUIRED)
find_package(GLEW                                 REQUIRED)
find_package(GLM      ${GLM_MINIMUM_VERSION}      REQUIRED)
find_package(OGLplus                              REQUIRED)

include_directories(SYSTEM ${Boost_INCLUDE_DIR})
include_directories(SYSTEM ${FreeGLUT_INCLUDE_DIR})
include_directories(SYSTEM ${GLEW_INCLUDE_DIRS})
include_directories(SYSTEM ${GLM_INCLUDE_DIR})
include_directories(SYSTEM ${OGLplus_INCLUDE_DIRS})
include_directories(       ${CMAKE_CURRENT_SOURCE_DIR})

set(SRC)
list(APPEND SRC "main.cpp")

set(LIBS)
list(APPEND LIBS platform_glut)
list(APPEND LIBS platform_oglplus)
list(APPEND LIBS support)
list(APPEND LIBS ${FreeGLUT_LIBRARY})
list(APPEND LIBS ${GLEW_LIBRARY})
list(APPEND LIBS ${Boost_LIBRARIES})

set(APP "oglplus_boxes")

cma_setup_application(${APP} SOURCES ${SRC} DEPENDENCIES ${LIBS})

file(GLOB_RECURSE SHADER_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.glsl)

cma_setup_file_target(app_${APP}_shaders
                      SOURCES     ${SHADER_SRC}
		      DESTINATION ${CMAKE_SHADER_OUTPUT_DIRECTORY}/glsl)

add_dependencies(app_${APP} app_${APP}_shaders)
