# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS program_options)
find_package(GLM   ${GLM_MINIMUM_VERSION}   REQUIRED)

include_directories(SYSTEM ${Boost_INCLUDE_DIR})
include_directories(SYSTEM ${GLM_INCLUDE_DIR})

set(SRC)
list(APPEND SRC "application/base.cpp")
list(APPEND SRC "application/command_line.cpp")
list(APPEND SRC "application/multi_instance.cpp")
list(APPEND SRC "application/single_instance.cpp")
list(APPEND SRC "window/base.cpp")
#list(APPEND SRC "window/controller.cpp")
list(APPEND SRC "window/manager.cpp")
list(APPEND SRC "window/rect.cpp")

#add_definitions("-DUKACHULLDCS_ALL_TRACE")

set(LIBS)
list(APPEND LIBS field)
list(APPEND LIBS support)
list(APPEND LIBS ${Boost_LIBRARIES})

set(LIB "platform")

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
cma_setup_export(${LIB})

add_custom_target(${LIB}_all)
add_custom_target(test_${LIB}_all)

add_subdirectory(glut)
add_subdirectory(oglplus)
add_subdirectory(posix)
add_subdirectory(win32)
add_subdirectory(winrt)

add_subdirectory(test EXCLUDE_FROM_ALL)
