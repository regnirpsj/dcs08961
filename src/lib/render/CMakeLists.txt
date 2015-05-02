# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014-2015 University of Hull                                                       #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(Boost ${BOOST_MINIMUM_VERSION} REQUIRED)
find_package(GLM   ${GLM_MINIMUM_VERSION}   REQUIRED)

include_directories(SYSTEM ${Boost_INCLUDE_DIR})
include_directories(SYSTEM ${GLM_INCLUDE_DIR})

set(SRC)
list(APPEND SRC "api.cpp")
list(APPEND SRC "base/context.cpp")
list(APPEND SRC "base/pass/base.cpp")
list(APPEND SRC "base/pass/container.cpp")
list(APPEND SRC "base/pass/gui.cpp")
list(APPEND SRC "base/pass/null.cpp")
list(APPEND SRC "base/stage/base.cpp")
list(APPEND SRC "base/stage/clear.cpp")
list(APPEND SRC "base/stage/draw.cpp")
list(APPEND SRC "base/stage/null.cpp")
list(APPEND SRC "base/stage/setup.cpp")
list(APPEND SRC "base/stage/swap.cpp")
list(APPEND SRC "base/statistics/base.cpp")
list(APPEND SRC "base/statistics/cpu.cpp")
list(APPEND SRC "base/statistics/gpu.cpp")
list(APPEND SRC "base/window.cpp")

# ADD_DEFINITIONS("-DUKACHULLDCS_ALL_TRACE")

set(LIBS)
list(APPEND LIBS scene)
list(APPEND LIBS support)

set(LIB "render")

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
cma_setup_export(${LIB})

add_custom_target(${LIB}_all)
add_custom_target(test_${LIB}_all)

add_subdirectory(d3d)
add_subdirectory(null)
add_subdirectory(ogl)
add_subdirectory(test EXCLUDE_FROM_ALL)
