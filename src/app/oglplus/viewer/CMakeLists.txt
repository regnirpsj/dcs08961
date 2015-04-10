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

SET(oglplus_viewer_SRC)
LIST(APPEND oglplus_viewer_SRC "application.cpp")
LIST(APPEND oglplus_viewer_SRC "main.cpp")
LIST(APPEND oglplus_viewer_SRC "model.cpp")
LIST(APPEND oglplus_viewer_SRC "stats.cpp")
LIST(APPEND oglplus_viewer_SRC "window.cpp")

APPLICATION_SETUP(oglplus_viewer SOURCES ${oglplus_viewer_SRC} DEPENDENCIES ${LIBS})
ADD_DEPENDENCIES(app_oglplus_viewer share/shader/glsl/*.glsl)
ADD_DEPENDENCIES(app_oglplus_viewer share/shader/glsl/common/*.glsl)
