# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

SET(LIB "platform_posix")

SET(SRC)

LIST(APPEND SRC "application/base.cpp")

SET(LIBS)
LIST(APPEND LIBS platform)
LIST(APPEND LIBS support)

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)

ADD_DEPENDENCIES(platform_all ${LIB})
