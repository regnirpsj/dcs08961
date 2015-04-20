# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014-2015 University of Hull                                                       #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(GLI   ${GLI_MINIMUM_VERSION}   REQUIRED)
find_package(GLM   ${GLM_MINIMUM_VERSION}   REQUIRED)

include_directories(SYSTEM ${GLI_INCLUDE_DIR})
include_directories(SYSTEM ${GLM_INCLUDE_DIR})
include_directories(       ${CMAKE_CURRENT_SOURCE_DIR})

set(SRC)
list(APPEND SRC "context.cpp")
list(APPEND SRC "pass/container.cpp")
list(APPEND SRC "stage/clear.cpp")
list(APPEND SRC "stage/draw.cpp")
list(APPEND SRC "stage/setup.cpp")
list(APPEND SRC "stage/swap.cpp")
list(APPEND SRC "statistics.cpp")

set(LIBS)
list(APPEND LIBS render)
list(APPEND LIBS support)

set(LIB "${LIB}_null")

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

add_subdirectory(test EXCLUDE_FROM_ALL)

add_dependencies(render_all ${LIB})
