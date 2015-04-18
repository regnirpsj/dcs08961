# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014-2015 University of Hull                                                       #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS thread)

include_directories(SYSTEM ${Boost_INCLUDE_DIR})

set(SRC)
list(APPEND SRC "adapter/multi.cpp")
list(APPEND SRC "adapter/single.cpp")
list(APPEND SRC "base.cpp")
list(APPEND SRC "connection/manager.cpp")
list(APPEND SRC "connection/update.cpp")
list(APPEND SRC "container.cpp")
list(APPEND SRC "defaults.cpp")
list(APPEND SRC "multi/base.cpp")
list(APPEND SRC "single/base.cpp")
list(APPEND SRC "value/multi.cpp")
list(APPEND SRC "value/single.cpp")

set(LIBS)
list(APPEND LIBS support)
list(APPEND LIBS ${Boost_LIBRARIES})

set(LIB "field")

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
cma_setup_export(${LIB})

add_subdirectory(test EXCLUDE_FROM_ALL)
