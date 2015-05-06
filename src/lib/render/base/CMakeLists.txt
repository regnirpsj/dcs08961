# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(Boost ${BOOST_MINIMUM_VERSION} REQUIRED)
find_package(GLM   ${GLM_MINIMUM_VERSION}   REQUIRED)

include_directories(SYSTEM ${Boost_INCLUDE_DIR})
include_directories(SYSTEM ${GLM_INCLUDE_DIR})

set(SRC)
list(APPEND SRC "context.cpp")
list(APPEND SRC "pass/base.cpp")
list(APPEND SRC "pass/container.cpp")
list(APPEND SRC "stage/base.cpp")
list(APPEND SRC "stage/clear.cpp")
list(APPEND SRC "stage/draw.cpp")
list(APPEND SRC "stage/null.cpp")
list(APPEND SRC "stage/setup.cpp")
list(APPEND SRC "stage/swap.cpp")
list(APPEND SRC "window.cpp")

#add_definitions("-DUKACHULLDCS_ALL_TRACE")

set(LIBS)
list(APPEND LIBS scene)
list(APPEND LIBS support)

set(LIB "render")

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
cma_setup_export("render")

add_subdirectory(test EXCLUDE_FROM_ALL)

add_dependencies(render_all ${LIB})
