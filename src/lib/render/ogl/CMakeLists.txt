# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

SET(LIB "render_ogl")

SET(SRC)

LIST(APPEND SRC "context.cpp")
LIST(APPEND SRC "pass.cpp")
LIST(APPEND SRC "stage.cpp")

SET(LIBS)
LIST(APPEND LIBS render)
LIST(APPEND LIBS support)

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)
