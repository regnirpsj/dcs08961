# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

FIND_PACKAGE(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS unit_test_framework)

SET(SRC)
LIST(APPEND SRC "application.cpp")

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../../glut/test)

SET(LIBS)
LIST(APPEND LIBS ${LIB})
LIST(APPEND LIBS platform_glut)
LIST(APPEND LIBS test_platform_glut_helper)
LIST(APPEND LIBS ${Boost_LIBRARIES})

IF(UNIX)
  LIST(APPEND LIBS rt)
ENDIF()

TEST_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

ADD_DEPENDENCIES(test_platform_all test_${LIB})
