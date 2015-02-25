# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

# FIND_PACKAGE(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS )

SET(LIB "window")

SET(SRC)

LIST(APPEND SRC "base.cpp")

SET(LIBS)
LIST(APPEND LIBS field)
LIST(APPEND LIBS support)

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
EXPORT_SETUP(${LIB})

ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)
