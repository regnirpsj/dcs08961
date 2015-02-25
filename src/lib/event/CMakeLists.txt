# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

#FIND_PACKAGE(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS thread)

SET(LIB "event")

SET(SRC)

LIST(APPEND SRC "event/base.cpp")
LIST(APPEND SRC "event/event.cpp")

SET(LIBS)
LIST(APPEND LIBS support)
#LIST(APPEND LIBS ${Boost_LIBRARIES})

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
EXPORT_SETUP(${LIB})

ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)
