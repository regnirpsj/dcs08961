# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

FIND_PACKAGE(GLEW    REQUIRED)
FIND_PACKAGE(OGLplus REQUIRED)

SET(LIB "platform_oglplus")

SET(SRC)

LIST(APPEND SRC "application.cpp")

INCLUDE_DIRECTORIES(${GLEW_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${OGLplus_INCLUDE_DIRS})

SET(LIBS)
LIST(APPEND LIBS support)

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)

ADD_DEPENDENCIES(platform_all ${LIB})
