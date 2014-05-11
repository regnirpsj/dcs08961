# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

SET(LIB "render")

SET(SRC)

LIST(APPEND SRC "api.cpp")

LIST(APPEND SRC "base/context.cpp")
LIST(APPEND SRC "base/pass.cpp")
LIST(APPEND SRC "base/stage.cpp")

SET(LIBS)
LIST(APPEND LIBS support)

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

ADD_SUBDIRECTORY(d3d)
ADD_SUBDIRECTORY(null)
ADD_SUBDIRECTORY(ogl)
ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)