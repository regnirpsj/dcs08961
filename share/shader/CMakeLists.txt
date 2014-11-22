# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

FILE(GLOB_RECURSE SHADER_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} glsl/*.glsl)

FOREACH(file ${SHADER_SRC})
  IF(VERBOSE)
    MESSAGE(STATUS "copying ${file} -> ${CMAKE_SHADER_OUTPUT_DIRECTORY}/${file}")
  ENDIF()
  CONFIGURE_FILE(${file} ${CMAKE_SHADER_OUTPUT_DIRECTORY}/${file} COPYONLY)
ENDFOREACH()

INSTALL(DIRECTORY ${CMAKE_SHADER_OUTPUT_DIRECTORY} DESTINATION ${DCS08961_SHARE_DIRECTORY}
  COMPONENT hdr)
