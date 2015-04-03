# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

FIND_PACKAGE(GLEW REQUIRED)
FIND_PACKAGE(GLUT REQUIRED)

SET(LIB "platform_glut")

SET(SRC)

LIST(APPEND SRC "application/base.cpp")
LIST(APPEND SRC "window/base.cpp")
LIST(APPEND SRC "window/manager.cpp")
LIST(APPEND SRC "window/simple.cpp")

#ADD_DEFINITIONS("-DGLEW_MX")

INCLUDE_DIRECTORIES(${GLEW_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${GLUT_INCLUDE_DIR})

SET(LIBS)
LIST(APPEND LIBS platform)
LIST(APPEND LIBS support)
LIST(APPEND LIBS ${GLEW_LIBRARIES})
LIST(APPEND LIBS ${GLUT_LIBRARIES})

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)
