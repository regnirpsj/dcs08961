# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

set(SRC)
list(APPEND SRC "application/base.cpp")
list(APPEND SRC "application/desktop.cpp")
list(APPEND SRC "application/store.cpp")
list(APPEND SRC "application/universal.cpp")
list(APPEND SRC "window/base.cpp")
list(APPEND SRC "window/simple.cpp")

set(LIBS)
list(APPEND LIBS platform)
list(APPEND LIBS support)

set(LIB "${LIB}_winrt")

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

add_subdirectory(test EXCLUDE_FROM_ALL)

add_dependencies(platform_all ${LIB})
