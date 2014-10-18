# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

#ADD_DEFINITIONS("-DUKACHULLDCS_ALL_TRACE")

SET(LIB "render")

SET(SRC)

LIST(APPEND SRC "api.cpp")

LIST(APPEND SRC "base/context.cpp")
LIST(APPEND SRC "base/pass/base.cpp")
LIST(APPEND SRC "base/pass/container.cpp")
LIST(APPEND SRC "base/pass/gui.cpp")
LIST(APPEND SRC "base/pass/null.cpp")
LIST(APPEND SRC "base/stage/base.cpp")
LIST(APPEND SRC "base/stage/clear.cpp")
LIST(APPEND SRC "base/stage/draw.cpp")
LIST(APPEND SRC "base/stage/setup.cpp")
LIST(APPEND SRC "base/stage/swap.cpp")
LIST(APPEND SRC "base/statistics/base.cpp")
LIST(APPEND SRC "base/statistics/cpu.cpp")
LIST(APPEND SRC "base/statistics/gpu.cpp")
LIST(APPEND SRC "base/window.cpp")

SET(LIBS)
LIST(APPEND LIBS support)

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

ADD_SUBDIRECTORY(d3d)
ADD_SUBDIRECTORY(null)
ADD_SUBDIRECTORY(ogl)
ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)
