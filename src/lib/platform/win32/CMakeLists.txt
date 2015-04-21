# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(GLM ${GLM_MINIMUM_VERSION} REQUIRED)

include_directories(SYSTEM ${GLM_INCLUDE_DIR})

set(SRC)
list(APPEND SRC "application/base.cpp")
list(APPEND SRC "application/console.cpp")
list(APPEND SRC "application/windows.cpp")
list(APPEND SRC "io.cpp")
list(APPEND SRC "utilities.cpp")
list(APPEND SRC "window/base.cpp")
list(APPEND SRC "window/manager.cpp")
list(APPEND SRC "window/rect.cpp")
list(APPEND SRC "window/simple.cpp")

set(LIBS)
list(APPEND LIBS platform)
list(APPEND LIBS support)

set(LIB "${LIB}_win32")

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

add_subdirectory(test EXCLUDE_FROM_ALL)

add_dependencies(platform_all ${LIB})
