# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

FIND_PACKAGE(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS serialization)

SET(LIB "archive")

SET(LIBS)
SET(ARGS_INC)
SET(ARGS_OBJ)
SET(ARGS_OUT)

### begin file list

# field::*
LIST(APPEND ARGS_INC "field/base.hpp")
LIST(APPEND ARGS_OBJ "field::base")
LIST(APPEND ARGS_OUT "field_base")

LIST(APPEND ARGS_INC "field/container.hpp")
LIST(APPEND ARGS_OBJ "field::container")
LIST(APPEND ARGS_OUT "field_container")
LIST(APPEND LIBS field)

# scene::*

# support::*

### end of file list

LIST(LENGTH ARGS_OUT ARGS_COUNT)
MATH(EXPR ARGS_COUNT ${ARGS_COUNT}-1)

SET(SRC)
SET(GENERATE_COUNT 0)

FOREACH(arg RANGE ${ARGS_COUNT})
  LIST(GET ARGS_INC ${arg} INCLUDE)
  LIST(GET ARGS_OBJ ${arg} TYPE)
  LIST(GET ARGS_OUT ${arg} OUTPUT)
  SET(OUTFILE ${CMAKE_CURRENT_BINARY_DIR}/archive_${OUTPUT}.cpp)

  IF(NOT EXISTS ${OUTFILE})
    CONFIGURE_FILE(template.cpp ${OUTFILE})
    MATH(EXPR GENERATE_COUNT ${GENERATE_COUNT}+1)
  ENDIF()

  LIST(APPEND SRC ${OUTFILE})
ENDFOREACH()

SET_PROPERTY(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES ${SRC})

MATH(EXPR ARGS_COUNT ${ARGS_COUNT}+1)

IF(0 LESS ${GENERATE_COUNT})
  MESSAGE(STATUS "(re-)generated ${GENERATE_COUNT}/${ARGS_COUNT} archive specializations")
ENDIF()

LIST(APPEND LIBS ${Boost_LIBRARIES})

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
EXPORT_SETUP(${LIB})

# ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)
