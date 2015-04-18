# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS unit_test_framework)

include_directories(SYSTEM ${Boost_INLCUDE_DIR})
include_directories(       ${CMAKE_CURRENT_SOURCE_DIR})

# helper
set(SRC_HELPER)
list(APPEND SRC_HELPER "window.cpp")

set(LIBS_HELPER)
list(APPEND LIBS_HELPER ${LIB})
list(APPEND LIBS_HELPER support)

set(LIB_HELPER "test_${LIB}_helper")

cma_setup_library(${LIB_HELPER} SOURCES ${SRC_HELPER} DEPENDENCIES ${LIBS_HELPER})

# tests
set(SRC)
list(APPEND SRC "application.cpp")
list(APPEND SRC "window_simple.cpp")

set(LIBS)
list(APPEND LIBS ${LIB_HELPER})
list(APPEND LIBS ${LIB})
list(APPEND LIBS ${Boost_LIBRARIES})

cma_setup_test(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

add_dependencies(test_platform_all test_${LIB})
