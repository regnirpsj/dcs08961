# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(GLEW                           REQUIRED ${GLEW_COMPONENTS})
find_package(GLM     ${GLM_MINIMUM_VERSION} REQUIRED)
find_package(OGLplus                        REQUIRED)

include_directories(SYSTEM ${GLEW_INCLUDE_DIR})
include_directories(SYSTEM ${GLM_INCLUDE_DIR})
include_directories(SYSTEM ${OGLplus_INCLUDE_DIRS})

set(SRC)
list(APPEND SRC "application.cpp")

add_definitions(${GLEW_DEFINITIONS})

set(LIBS)
list(APPEND LIBS platform)
list(APPEND LIBS support)
list(APPEND LIBS ${GLEW_LIBRARY})

set(LIB "${LIB}_oglplus")

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

add_subdirectory(test EXCLUDE_FROM_ALL)

add_dependencies(platform_all ${LIB})
