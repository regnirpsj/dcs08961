# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(FreeGLUT ${FREEGLUT_MINIMUM_VERSION} REQUIRED)
find_package(GLEW                                 REQUIRED)
find_package(GLM      ${GLM_MINIMUM_VERSION}      REQUIRED)
find_package(OpenGL                               REQUIRED)

include_directories(SYSTEM ${FreeGLUT_INCLUDE_DIR})
include_directories(SYSTEM ${GLEW_INCLUDE_DIR})
include_directories(SYSTEM ${GLM_INCLUDE_DIR})
include_directories(SYSTEM ${OPENGL_INCLUDE_DIR})
include_directories(       ${CMAKE_CURRENT_SOURCE_DIR})

set(SRC)
list(APPEND SRC "application/base.cpp")
list(APPEND SRC "io.cpp")
list(APPEND SRC "utilities.cpp")
list(APPEND SRC "window/base.cpp")
list(APPEND SRC "window/controller.cpp")
list(APPEND SRC "window/helper.cpp")
list(APPEND SRC "window/manager.cpp")
list(APPEND SRC "window/simple.cpp")

#add_definitions("-DUKACHULLDCS_ALL_TRACE")

set(LIBS)
list(APPEND LIBS platform)
list(APPEND LIBS support)
list(APPEND LIBS ${FreeGLUT_LIBRARY})
list(APPEND LIBS ${GLEW_LIBRARY})
list(APPEND LIBS ${OPENGL_gl_LIBRARY})

set(LIB "${LIB}_glut")

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
cma_setup_export(${LIB})

add_subdirectory(test EXCLUDE_FROM_ALL)

add_dependencies(platform_all ${LIB})
