# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

#find_package(Boost ${BOOST_MINIMUM_VERSION} REQUIRED
#             COMPONENTS date_time filesystem program_options system thread)

#include_directories(SYSTEM ${Boost_INCLUDE_DIR})

set(SRC)
LIST(APPEND SRC "base.cpp")
LIST(APPEND SRC "handler/base.cpp")

#add_definitions("-DUKACHULLDCS_ALL_TRACE")

set(LIBS)
list(APPEND LIBS support)
#list(APPEND LIBS ${Boost_LIBRARIES})

set(LIB "event")

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
cma_setup_export(${LIB})

add_subdirectory(test EXCLUDE_FROM_ALL)
