# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(Boost ${BOOST_MINIMUM_VERSION} REQUIRED)
find_package(GLM   ${GLM_MINIMUM_VERSION}   REQUIRED)

include_directories(SYSTEM ${Boost_INCLUDE_DIR})
include_directories(SYSTEM ${GLM_INCLUDE_DIR})

set(SRC)
LIST(APPEND SRC "orbital/base.cpp")
LIST(APPEND SRC "orbital/jupiter.cpp")
LIST(APPEND SRC "orbital/mars.cpp")
LIST(APPEND SRC "orbital/mercury.cpp")
LIST(APPEND SRC "orbital/moon.cpp")
LIST(APPEND SRC "orbital/neptune.cpp")
LIST(APPEND SRC "orbital/saturn.cpp")
LIST(APPEND SRC "orbital/sun.cpp")
LIST(APPEND SRC "orbital/uranus.cpp")
LIST(APPEND SRC "orbital/venus.cpp")

#add_definitions("-DUKACHULLDCS_ALL_TRACE")

set(LIBS)
list(APPEND LIBS support)

set(LIB "celestial")

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
cma_setup_export(${LIB})

add_subdirectory(test EXCLUDE_FROM_ALL)
