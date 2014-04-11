# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

FIND_PACKAGE(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS unit_test_framework)

SET(SRC)
LIST(APPEND SRC "io.cpp")

SET(LIBS)
LIST(APPEND LIBS ${LIB})
LIST(APPEND LIBS support)
LIST(APPEND LIBS ${Boost_LIBRARIES})

IF(UNIX)
  LIST(APPEND LIBS rt)
ENDIF()

TEST_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
