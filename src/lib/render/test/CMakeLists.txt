# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS unit_test_framework)

include_directories(SYSTEM ${Boost_INLCUDE_DIR})

set(SRC)
list(APPEND SRC "context.cpp")
list(APPEND SRC "pass_container.cpp")
list(APPEND SRC "shader_program.cpp")
list(APPEND SRC "stage_clear.cpp")
list(APPEND SRC "stage_draw.cpp")
list(APPEND SRC "stage_null.cpp")
list(APPEND SRC "stage_setup.cpp")
list(APPEND SRC "stage_swap.cpp")
list(APPEND SRC "window.cpp")

set(LIBS)
list(APPEND LIBS ${LIB})
list(APPEND LIBS ${Boost_LIBRARIES})

cma_setup_test(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

add_dependencies(test_render_all test_${LIB})
