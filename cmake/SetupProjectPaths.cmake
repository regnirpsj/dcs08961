# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

# sub directories, relative to CMAKE_BINARY_DIR or CMAKE_INSTALL_PREFIX
# depending on if they are used during build or install
SET(DCSC08961_CPACK_DIRECTORY   cpack)
SET(DCSC08961_RUNTIME_DIRECTORY bin)

IF(WIN32 OR WIN64)
  SET(DCSC08961_LIBRARY_DIRECTORY bin)
ELSE()
  SET(DCSC08961_LIBRARY_DIRECTORY lib)
ENDIF()

SET(DCSC08961_SHARE_DIRECTORY   share)
SET(DCSC08961_DOC_DIRECTORY     ${DCSC08961_SHARE_DIRECTORY}/doc)
SET(DCSC08961_EXTRA_DIRECTORY   ${DCSC08961_SHARE_DIRECTORY}/extra)
SET(DCSC08961_SHADER_DIRECTORY  ${DCSC08961_SHARE_DIRECTORY}/shader)

# output directories, overwrite
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${DCSC08961_LIBRARY_DIRECTORY})
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${DCSC08961_LIBRARY_DIRECTORY})
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${DCSC08961_RUNTIME_DIRECTORY})

# output directories, project specific
SET(CMAKE_DOC_OUTPUT_DIRECTORY     ${CMAKE_BINARY_DIR}/${DCSC08961_DOC_DIRECTORY})
SET(CMAKE_EXTRA_OUTPUT_DIRECTORY   ${CMAKE_BINARY_DIR}/${DCSC08961_EXTRA_DIRECTORY})
SET(CMAKE_SHADER_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/${DCSC08961_SHADER_DIRECTORY})
