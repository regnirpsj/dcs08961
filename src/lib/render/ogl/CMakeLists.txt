# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

FIND_PACKAGE(GLEW REQUIRED)
FIND_PACKAGE(OpenGL REQUIRED)
FIND_PACKAGE(X11 REQUIRED)

SET(LIB "render_ogl")

SET(SRC)

LIST(APPEND SRC "context.cpp")
LIST(APPEND SRC "pass/container.cpp")
LIST(APPEND SRC "stage/clear.cpp")
LIST(APPEND SRC "stage/draw.cpp")
LIST(APPEND SRC "stage/swap.cpp")

SET(LIBS)
LIST(APPEND LIBS render)
LIST(APPEND LIBS support)
LIST(APPEND LIBS ${GLEW_LIBRARY})
LIST(APPEND LIBS ${OPENGL_gl_LIBRARY})
LIST(APPEND LIBS ${X11_X11_LIB})

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
EXPORT_SETUP(${LIB})

ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)
