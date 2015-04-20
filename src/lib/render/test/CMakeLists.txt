# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014-2015 University of Hull                                                       #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS unit_test_framework)
find_package(GLI   ${GLI_MINIMUM_VERSION}   REQUIRED)
find_package(GLM   ${GLM_MINIMUM_VERSION}   REQUIRED)

include_directories(SYSTEM ${Boost_INLCUDE_DIR})
include_directories(SYSTEM ${GLI_INCLUDE_DIR})
include_directories(SYSTEM ${GLM_INCLUDE_DIR})

set(SRC)
list(APPEND SRC "api.cpp")

set(LIBS)
LIST(APPEND LIBS ${LIB}_d3d)
LIST(APPEND LIBS ${LIB}_null)
LIST(APPEND LIBS ${LIB}_ogl)
list(APPEND LIBS ${Boost_LIBRARIES})

if(FALSE)
  cma_setup_test(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

  add_dependencies(test_render_all test_${LIB})
else()
  message(STATUS "Target 'test_render' disabled")
endif()
