# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014-2015 University of Hull                                                       #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS unit_test_framework)

include_directories(SYSTEM ${Boost_INLCUDE_DIR})

set(SRC)
list(APPEND SRC "api.cpp")

set(LIBS)
LIST(APPEND LIBS ${LIB}_d3d)
LIST(APPEND LIBS ${LIB}_null)
LIST(APPEND LIBS ${LIB}_ogl)
list(APPEND LIBS ${Boost_LIBRARIES})

cma_setup_test(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
