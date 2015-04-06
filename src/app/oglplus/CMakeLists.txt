# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

FIND_PACKAGE(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS filesystem system)
FIND_PACKAGE(OpenGL REQUIRED)
#FIND_PACKAGE(GLUT REQUIRED)
FIND_PACKAGE(GLEW REQUIRED)
FIND_PACKAGE(OGLplus REQUIRED)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../common)
INCLUDE_DIRECTORIES(${OGLplus_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${GLUT_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${GLEW_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})

SET(LIBS)

LIST(APPEND LIBS app_common)
LIST(APPEND LIBS support)
# LIST(APPEND LIBS ${OGLplus_LIBRARIES})
LIST(APPEND LIBS ${GLUT_LIBRARIES})
LIST(APPEND LIBS ${GLEW_LIBRARIES})
LIST(APPEND LIBS ${OPENGL_gl_LIBRARY})
LIST(APPEND LIBS ${Boost_LIBRARIES})

FOREACH(APP "01" "02")
  APPLICATION_SETUP(oglplus_${APP} SOURCES ${APP}.cpp DEPENDENCIES ${LIBS})
  ADD_DEPENDENCIES(app_oglplus_${APP} glsl/oglplus_${APP}.vs.glsl)
  ADD_DEPENDENCIES(app_oglplus_${APP} glsl/oglplus_${APP}.fs.glsl)
ENDFOREACH()

APPLICATION_SETUP(oglplus_03 SOURCES 03.cpp DEPENDENCIES ${LIBS})
ADD_DEPENDENCIES(app_oglplus_03 share/shader/glsl/*.glsl)
ADD_DEPENDENCIES(app_oglplus_03 share/shader/glsl/common/*.glsl)

SET(SHADER_SRC)
FILE(GLOB_RECURSE SHADER_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} glsl/*.glsl)

FOREACH(file ${SHADER_SRC})
  CONFIGURE_FILE(${file} ${CMAKE_SHADER_OUTPUT_DIRECTORY}/${file} COPYONLY)
ENDFOREACH()
