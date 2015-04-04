# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

SET(LIB "platform_win32")

SET(SRC)

LIST(APPEND SRC "application/base.cpp")
LIST(APPEND SRC "application/console.cpp")
LIST(APPEND SRC "application/windows.cpp")
LIST(APPEND SRC "io.cpp")
LIST(APPEND SRC "utilities.cpp")
LIST(APPEND SRC "window/base.cpp")
LIST(APPEND SRC "window/manager.cpp")
LIST(APPEND SRC "window/rect.cpp")
LIST(APPEND SRC "window/simple.cpp")

SET(LIBS)
LIST(APPEND LIBS platform)
LIST(APPEND LIBS support)
LIST(APPEND LIBS ${Boost_LIBRARIES})

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)

ADD_DEPENDENCIES(platform_all ${LIB})