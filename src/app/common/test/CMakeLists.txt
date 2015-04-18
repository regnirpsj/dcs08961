# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS unit_test_framework)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${Boost_INCLUDE_DIR})

set(SRC)
list(APPEND SRC "glut.cpp")

set(LIBS)
list(APPEND LIBS ${LIB})
list(APPEND LIBS ${Boost_LIBRARIES})

cma_setup_test(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
