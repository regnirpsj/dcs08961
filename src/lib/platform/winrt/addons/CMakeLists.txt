# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

set(SRC)
list(APPEND SRC "getenv.c")

set(LIBS)
list(APPEND LIBS support)

set(LIB "${LIB}_addons")

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS} WINRT)
