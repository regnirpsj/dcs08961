# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014-2015 University of Hull                                                       #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(GLI ${GLI_MINIMUM_VERSION} REQUIRED)
find_package(GLM ${GLM_MINIMUM_VERSION} REQUIRED)

include_directories(SYSTEM ${GLI_INCLUDE_DIR})
include_directories(SYSTEM ${GLM_INCLUDE_DIR})

set(SRC)
list(APPEND SRC "gtx/io.cpp")

set(LIB "gli")

cma_setup_library(${LIB} SOURCES ${SRC})

add_subdirectory(test EXCLUDE_FROM_ALL)
