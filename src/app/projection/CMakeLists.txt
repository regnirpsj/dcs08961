# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

SET(APP "projection")

SET(SRC)

LIST(APPEND SRC "main.cpp")

SET(LIBS)

LIST(APPEND LIBS support)

APPLICATION_SETUP(${APP} SOURCES ${SRC} DEPENDENCIES ${LIBS})
