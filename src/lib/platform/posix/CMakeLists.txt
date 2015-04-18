# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS thread)

include_directories(SYSTEM ${Boost_INCLUDE_DIR})

set(SRC)
list(APPEND SRC "application/base.cpp")

set(LIBS)
list(APPEND LIBS platform)
list(APPEND LIBS support)

set(LIB "${LIB}_posix")

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
cma_setup_export(${LIB})

add_subdirectory(test EXCLUDE_FROM_ALL)

add_dependencies(platform_all ${LIB})
