# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

# helper
SET(SRC_HELPER)
LIST(APPEND SRC_HELPER "window.cpp")

SET(LIB_HELPER "test_${LIB}_helper")

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

SET(LIBS_HELPER)
LIST(APPEND LIBS_HELPER ${LIB})
LIST(APPEND LIBS_HELPER support)

LIBRARY_SETUP(${LIB_HELPER} SOURCES ${SRC_HELPER} DEPENDENCIES ${LIBS_HELPER})

# tests
FIND_PACKAGE(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS unit_test_framework)

SET(SRC)
LIST(APPEND SRC "application.cpp")
LIST(APPEND SRC "window_simple.cpp")

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

SET(LIBS)
LIST(APPEND LIBS ${LIB_HELPER})
LIST(APPEND LIBS ${LIB})
LIST(APPEND LIBS ${Boost_LIBRARIES})

IF(UNIX)
  LIST(APPEND LIBS rt)
ENDIF()

TEST_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

ADD_DEPENDENCIES(test_platform_all test_${LIB})
