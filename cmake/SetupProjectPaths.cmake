# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

# sub directories, relative to CMAKE_BINARY_DIR or CMAKE_INSTALL_PREFIX
# depending on if they are used during build or install
SET(DCSCOMMON_CPACK_DIRECTORY   cpack)
SET(DCSCOMMON_RUNTIME_DIRECTORY bin)

IF(WIN32 OR WIN64)
  SET(DCSCOMMON_LIBRARY_DIRECTORY bin)
ELSE()
  SET(DCSCOMMON_LIBRARY_DIRECTORY lib)
ENDIF()

SET(DCSCOMMON_SHARE_DIRECTORY   share)
SET(DCSCOMMON_DOC_DIRECTORY     ${DCSCOMMON_SHARE_DIRECTORY}/doc)
SET(DCSCOMMON_EXTRA_DIRECTORY   ${DCSCOMMON_SHARE_DIRECTORY}/extra)
SET(DCSCOMMON_SHADER_DIRECTORY  ${DCSCOMMON_SHARE_DIRECTORY}/shader)

# output directories, overwrite
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${DCSCOMMON_LIBRARY_DIRECTORY})
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${DCSCOMMON_LIBRARY_DIRECTORY})
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${DCSCOMMON_RUNTIME_DIRECTORY})

# output directories, project specific
SET(CMAKE_DOC_OUTPUT_DIRECTORY     ${CMAKE_BINARY_DIR}/${DCSCOMMON_DOC_DIRECTORY})
SET(CMAKE_EXTRA_OUTPUT_DIRECTORY   ${CMAKE_BINARY_DIR}/${DCSCOMMON_EXTRA_DIRECTORY})
SET(CMAKE_SHADER_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/${DCSCOMMON_SHADER_DIRECTORY})
