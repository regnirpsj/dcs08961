# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

FIND_PACKAGE(OpenGL REQUIRED)
#FIND_PACKAGE(GLUT REQUIRED)
FIND_PACKAGE(GLEW REQUIRED)
FIND_PACKAGE(OGLplus REQUIRED)

SET(LIB "app_common")

SET(SRC)

LIST(APPEND SRC "glut.cpp")
LIST(APPEND SRC "light.cpp")
LIST(APPEND SRC "model.cpp")
LIST(APPEND SRC "stats.cpp")

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${OGLplus_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${GLUT_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${GLEW_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})

SET(LIBS)
LIST(APPEND LIBS support)
# LIST(APPEND LIBS ${OGLplus_LIBRARIES})
LIST(APPEND LIBS ${GLUT_LIBRARIES})
LIST(APPEND LIBS ${GLEW_LIBRARIES})
LIST(APPEND LIBS ${OPENGL_gl_LIBRARY})

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)
