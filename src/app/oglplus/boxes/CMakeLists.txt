# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

FIND_PACKAGE(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS filesystem system)
FIND_PACKAGE(OpenGL  REQUIRED)
FIND_PACKAGE(GLEW    REQUIRED)
FIND_PACKAGE(GLUT    REQUIRED)
FIND_PACKAGE(OGLplus REQUIRED)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${OGLplus_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${GLEW_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${GLUT_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})

SET(LIBS)
LIST(APPEND LIBS platform_glut)
LIST(APPEND LIBS platform_oglplus)
LIST(APPEND LIBS support)
LIST(APPEND LIBS ${GLUT_LIBRARIES})
LIST(APPEND LIBS ${GLEW_LIBRARIES})
LIST(APPEND LIBS ${OPENGL_gl_LIBRARY})
LIST(APPEND LIBS ${Boost_LIBRARIES})

SET(oglplus_boxes_SRC)
LIST(APPEND oglplus_boxes_SRC "main.cpp")

APPLICATION_SETUP(oglplus_boxes SOURCES ${oglplus_boxes_SRC} DEPENDENCIES ${LIBS})
ADD_DEPENDENCIES(app_oglplus_boxes glsl/oglplus_boxes.vs.glsl)
ADD_DEPENDENCIES(app_oglplus_boxes glsl/oglplus_boxes.fs.glsl)

SET(SHADER_SRC)
FILE(GLOB_RECURSE SHADER_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.glsl)

FOREACH(file ${SHADER_SRC})
  CONFIGURE_FILE(${file} ${CMAKE_SHADER_OUTPUT_DIRECTORY}/glsl/${file} COPYONLY)
ENDFOREACH()
