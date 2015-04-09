# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

FIND_PACKAGE(Boost ${BOOST_MINIMUM_VERSION} REQUIRED
  COMPONENTS filesystem program_options system thread)

SET(LIB "support")

SET(SRC)

LIST(APPEND SRC "application.cpp")
LIST(APPEND SRC "chrono.cpp")
LIST(APPEND SRC "chrono_io.cpp")
LIST(APPEND SRC "hasher.cpp")
LIST(APPEND SRC "io_utils.cpp")
LIST(APPEND SRC "printable.cpp")
LIST(APPEND SRC "refcounted.cpp")
LIST(APPEND SRC "signal_handler.cpp")
LIST(APPEND SRC "string.cpp")
LIST(APPEND SRC "thread.cpp")
LIST(APPEND SRC "trace.cpp")
LIST(APPEND SRC "type_info.cpp")

SET(LIBS)
LIST(APPEND LIBS ${Boost_LIBRARIES})

IF(UNIX)
  LIST(APPEND LIBS pthread)
ENDIF()

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
EXPORT_SETUP(${LIB})

ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)
