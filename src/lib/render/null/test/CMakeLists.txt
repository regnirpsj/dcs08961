# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

FIND_PACKAGE(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS unit_test_framework)

SET(SRC)

LIST(APPEND SRC "context.cpp")
LIST(APPEND SRC "pass_container.cpp")
LIST(APPEND SRC "stage_clear.cpp")
LIST(APPEND SRC "stage_draw.cpp")
LIST(APPEND SRC "stage_setup.cpp")
LIST(APPEND SRC "stage_swap.cpp")

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

SET(LIBS)
LIST(APPEND LIBS ${LIB})
LIST(APPEND LIBS ${Boost_LIBRARIES})

IF(UNIX)
  LIST(APPEND LIBS rt)
ENDIF()

TEST_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
