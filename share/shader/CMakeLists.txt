# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014-2015 University of Hull                                                       #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

file(GLOB_RECURSE SHADER_SRC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} glsl/*.glsl)

foreach(file ${SHADER_SRC})
  if(VERBOSE)
    message(STATUS "copying ${file} -> ${CMAKE_SHADER_OUTPUT_DIRECTORY}/${file}")
  endif()
  configure_file(${file} ${CMAKE_SHADER_OUTPUT_DIRECTORY}/${file} COPYONLY)
endforeach()

install(DIRECTORY   ${CMAKE_SHADER_OUTPUT_DIRECTORY}/glsl
        DESTINATION ${${PROJECT_NAME}_SHARE_DIRECTORY}
	COMPONENT   ${PROJECT_NAME}_HDR_COMPONENT_NAME)
