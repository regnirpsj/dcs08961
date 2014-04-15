# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

FIND_PACKAGE(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS filesystem program_options)

SET(LIB "gli")

SET(SRC)

LIST(APPEND SRC "gtx/io.cpp")

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES)

ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)
