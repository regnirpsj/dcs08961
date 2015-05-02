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
list(APPEND SRC "main.cpp")

set(LIBS)
list(APPEND LIBS glm)
list(APPEND LIBS scene)
list(APPEND LIBS support)

set(APP "projection")

cma_setup_application(${APP} SOURCES ${SRC} DEPENDENCIES ${LIBS})
