# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014-2015  University of Hull                                                      #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(GLEW REQUIRED)

include_directories(SYSTEM ${GLEW_INCLUDE_DIR})

set(SRC)
list(APPEND SRC "context.cpp")
list(APPEND SRC "pass/container.cpp")
list(APPEND SRC "stage/clear.cpp")
list(APPEND SRC "stage/draw.cpp")
list(APPEND SRC "stage/swap.cpp")

set(LIBS)
list(APPEND LIBS render)
list(APPEND LIBS support)
list(APPEND LIBS ${GLEW_LIBRARY})

set(LIB "${LIB}_ogl")

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
cma_setup_export(${LIB} PATH render/ogl)

add_subdirectory(test EXCLUDE_FROM_ALL)
