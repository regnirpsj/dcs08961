# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS unit_test_framework)

include_directories(SYSTEM ${Boost_INLCUDE_DIR})
include_directories(       ${CMAKE_CURRENT_SOURCE_DIR}/../../glut/test)

set(SRC)
list(APPEND SRC "application.cpp")

set(LIBS)
list(APPEND LIBS ${LIB})
list(APPEND LIBS test_platform_glut_helper)
list(APPEND LIBS platform_glut)
list(APPEND LIBS ${Boost_LIBRARIES})

cma_setup_test(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

add_dependencies(test_platform_all test_${LIB})
