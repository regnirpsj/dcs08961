# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014-2015 University of Hull                                                       #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(GLM ${GLM_MINIMUM_VERSION} REQUIRED)

include_directories(SYSTEM ${GLM_INCLUDE_DIR})

set(SRC)
list(APPEND SRC "gtx/limits.cpp")
list(APPEND SRC "gtx/utilities.cpp")

set(LIBS)
list(APPEND LIBS support)
list(APPEND LIBS ${Boost_LIBRARIES})

set(LIB "glm")

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
cma_setup_export(${LIB})

add_subdirectory(test EXCLUDE_FROM_ALL)
