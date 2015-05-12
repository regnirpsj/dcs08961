# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(FreeGLUT ${FREEGLUT_MINIMUM_VERSION} REQUIRED)
find_package(GLEW                                 REQUIRED ${GLEW_COMPONENTS})
find_package(OpenGL                               REQUIRED)
find_package(X11)

include_directories(SYSTEM ${FreeGLUT_INCLUDE_DIR})
include_directories(SYSTEM ${GLEW_INCLUDE_DIR})
include_directories(SYSTEM ${OPENGL_INCLUDE_DIR})
if(X11_FOUND)
  include_directories(SYSTEM ${X11_X11_INCLUDE_PATH})
endif()

set(SRC)
list(APPEND SRC "context.cpp")
list(APPEND SRC "pass/standard.cpp")
list(APPEND SRC "stage/clear.cpp")
list(APPEND SRC "stage/draw.cpp")
list(APPEND SRC "stage/setup.cpp")
list(APPEND SRC "stage/swap.cpp")
list(APPEND SRC "stats/gpu.cpp")
list(APPEND SRC "window/glut.cpp")

if(X11_FOUND)
  list(APPEND SRC "window/glx.cpp")
endif()

#add_definitions("-DUKACHULLDCS_ALL_TRACE")
if(CMAKE_HOST_WIN32)
  add_definitions("-DFREEGLUT_STATIC -DFREEGLUT_LIB_PRAGMAS=0")
endif()
add_definitions(${GLEW_DEFINITIONS})

set(LIBS)
list(APPEND LIBS ${LIB})
list(APPEND LIBS platform_glut)
if(X11_FOUND)
  list(APPEND LIBS platform_glx)
endif()
list(APPEND LIBS scene)
list(APPEND LIBS support)
list(APPEND LIBS ${FreeGLUT_LIBRARY})
list(APPEND LIBS ${GLEW_LIBRARY})
list(APPEND LIBS ${OPENGL_gl_LIBRARY})
if(X11_FOUND)
  list(APPEND LIBS ${X11_X11_LIB})
endif()

set(LIB "render_ogl")

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

add_dependencies(render_all ${LIB})

add_subdirectory(test EXCLUDE_FROM_ALL)
