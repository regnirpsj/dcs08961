# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

FIND_PACKAGE(OpenGL REQUIRED)
FIND_PACKAGE(GLEW REQUIRED)

IF(NOT WIN32 AND NOT WIN64)
  FIND_PACKAGE(GLUT REQUIRED)
ENDIF()

SET(LIB "platform_glut")

SET(SRC)

LIST(APPEND SRC "application/base.cpp")
LIST(APPEND SRC "io.cpp")
LIST(APPEND SRC "utilities.cpp")
LIST(APPEND SRC "window/base.cpp")
LIST(APPEND SRC "window/helper.cpp")
LIST(APPEND SRC "window/manager.cpp")
LIST(APPEND SRC "window/simple.cpp")

#ADD_DEFINITIONS("-DUKACHULLDCS_ALL_TRACE")
#ADD_DEFINITIONS("-DGLEW_MX")

IF(WIN32 OR WIN64)
  ADD_DEFINITIONS("-DFREEGLUT_STATIC -DFREEGLUT_LIB_PRAGMAS=1")
ENDIF()

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${GLUT_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${GLEW_INCLUDE_DIRS})

SET(LIBS)
LIST(APPEND LIBS platform)
LIST(APPEND LIBS support)
LIST(APPEND LIBS ${GLUT_LIBRARIES})
LIST(APPEND LIBS ${GLEW_LIBRARIES})
LIST(APPEND LIBS ${OPENGL_gl_LIBRARY})

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)

ADD_DEPENDENCIES(platform_all ${LIB})
