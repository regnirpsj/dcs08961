# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(GLEW    REQUIRED)
find_package(OGLplus REQUIRED)

include_directories(SYSTEM ${GLEW_INCLUDE_DIRS})
include_directories(SYSTEM ${OGLplus_INCLUDE_DIRS})

set(SRC)
list(APPEND SRC "application.cpp")

set(LIBS)
list(APPEND LIBS platform)
list(APPEND LIBS support)

set(LIB "${LIB}_oglplus")

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
cma_setup_export(${LIB})

add_subdirectory(test EXCLUDE_FROM_ALL)

add_dependencies(platform_all ${LIB})
