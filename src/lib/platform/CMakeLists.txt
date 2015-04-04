# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

FIND_PACKAGE(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS program_options)

SET(LIB "platform")

SET(SRC)

LIST(APPEND SRC "application/base.cpp")
LIST(APPEND SRC "application/command_line.cpp")
LIST(APPEND SRC "application/multi_instance.cpp")
LIST(APPEND SRC "application/single_instance.cpp")
LIST(APPEND SRC "window/base.cpp")
LIST(APPEND SRC "window/manager.cpp")
LIST(APPEND SRC "window/rect.cpp")

#ADD_DEFINITIONS("-DUKACHULLDCS_ALL_TRACE")

SET(LIBS)
LIST(APPEND LIBS support)
LIST(APPEND LIBS ${Boost_LIBRARIES})

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
EXPORT_SETUP(${LIB})

ADD_CUSTOM_TARGET(platform_all)
ADD_CUSTOM_TARGET(test_platform_all)

ADD_SUBDIRECTORY(glut)
ADD_SUBDIRECTORY(oglplus)
ADD_SUBDIRECTORY(posix)
ADD_SUBDIRECTORY(win32)
ADD_SUBDIRECTORY(winrt)
ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)
