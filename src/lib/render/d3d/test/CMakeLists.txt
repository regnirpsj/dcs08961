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
list(APPEND SRC "context.cpp")
list(APPEND SRC "pass_container.cpp")
list(APPEND SRC "stage_clear.cpp")
list(APPEND SRC "stage_draw.cpp")
list(APPEND SRC "stage_swap.cpp")

set(LIBS)
list(APPEND LIBS ${LIB})
list(APPEND LIBS ${Boost_LIBRARIES})

if(FALSE)
  cma_setup_test(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

  add_dependencies(test_render_all test_${LIB})
else()
  message(STATUS "Target 'test_render_d3d' disabled")
endif()
