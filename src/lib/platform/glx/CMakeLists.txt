# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

find_package(X11)

if(NOT X11_FOUND)
  return()
endif()

cma_print_current_directory()

find_package(GLEW                          REQUIRED ${GLEW_COMPONENTS})
find_package(GLM    ${GLM_MINIMUM_VERSION} REQUIRED)
find_package(OpenGL                        REQUIRED)

include_directories(SYSTEM ${GLEW_INCLUDE_DIR})
include_directories(SYSTEM ${GLM_INCLUDE_DIR})
include_directories(SYSTEM ${OPENGL_INCLUDE_DIR})
include_directories(SYSTEM ${X11_X11_INCLUDE_PATH})

set(SRC)
list(APPEND SRC "io.cpp")
list(APPEND SRC "window/base.cpp")
list(APPEND SRC "window/manager.cpp")
list(APPEND SRC "window/simple.cpp")

#add_definitions("-DUKACHULLDCS_ALL_TRACE")
add_definitions(${GLEW_DEFINITIONS})

set(LIBS)
list(APPEND LIBS platform)
list(APPEND LIBS support)
list(APPEND LIBS ${GLEW_LIBRARY})
list(APPEND LIBS ${X11_X11_LIB})

set(LIB "${LIB}_glx")

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

add_subdirectory(test EXCLUDE_FROM_ALL)
