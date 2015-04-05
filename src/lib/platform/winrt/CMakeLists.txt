# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

SET(LIB "platform_winrt")

SET(SRC)

LIST(APPEND SRC "application/base.cpp")
LIST(APPEND SRC "application/desktop.cpp")
LIST(APPEND SRC "application/store.cpp")
LIST(APPEND SRC "application/universal.cpp")
LIST(APPEND SRC "window/base.cpp")
LIST(APPEND SRC "window/simple.cpp")

SET(LIBS)
LIST(APPEND LIBS platform)
LIST(APPEND LIBS support)
LIST(APPEND LIBS ${Boost_LIBRARIES})

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)

ADD_DEPENDENCIES(platform_all ${LIB})
