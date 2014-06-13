# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

FIND_PACKAGE(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS thread)

SET(LIB "field")

SET(SRC)

LIST(APPEND SRC "adapter/multi.cpp")
LIST(APPEND SRC "adapter/single.cpp")
LIST(APPEND SRC "base.cpp")
LIST(APPEND SRC "connection/manager.cpp")
LIST(APPEND SRC "connection/transform.cpp")
LIST(APPEND SRC "container.cpp")
LIST(APPEND SRC "defaults.cpp")
LIST(APPEND SRC "multi/base.cpp")
LIST(APPEND SRC "single/base.cpp")
LIST(APPEND SRC "value/multi.cpp")
LIST(APPEND SRC "value/single.cpp")

SET(LIBS)
LIST(APPEND LIBS support)
LIST(APPEND LIBS ${Boost_LIBRARIES})

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)
