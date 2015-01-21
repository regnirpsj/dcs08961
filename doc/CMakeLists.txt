# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

IF(DCS08961_DOC_DEV OR DCS08961_DOC_USR)
  FIND_PACKAGE(Doxygen REQUIRED)
ENDIF()

IF(DCS08961_DOC_DEV)
  MESSAGE(STATUS "Generation of developer documentation enabled")

  CONFIGURE_FILE(Doxyfile.dev.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.dev @ONLY IMMEDIATE)
  ADD_CUSTOM_TARGET(devdoc
    COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.dev
    SOURCES ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.dev)
  INSTALL(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/dev DESTINATION ${DCS08961_DOC_DIRECTORY}
    COMPONENT doc)
ELSE()
  MESSAGE(STATUS "Generation of developer documentation disabled")
ENDIF()

IF(DCS08961_DOC_USR)
  MESSAGE(STATUS "Generation of user documentation enabled")
  CONFIGURE_FILE(Doxyfile.usr.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.usr @ONLY IMMEDIATE)
  ADD_CUSTOM_TARGET(usrdoc
    COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.usr
    SOURCES ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.usr)
  INSTALL(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/usr DESTINATION ${DCS08961_DOC_DIRECTORY}
    COMPONENT doc)
ELSE()
  MESSAGE(STATUS "Generation of user documentation disabled")
ENDIF()
