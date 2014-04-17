# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

INCLUDE(InstallRequiredSystemLibraries)

SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${CMAKE_PROJECT_NAME} infrastructure")
SET(CPACK_PACKAGE_VENDOR              "dcs.hull.ac.uk")
SET(CPACK_PACKAGE_DESCRIPTION_FILE    "${CMAKE_CURRENT_SOURCE_DIR}/README.rst")
SET(CPACK_RESOURCE_FILE_LICENSE       "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
SET(CPACK_PACKAGE_VERSION_MAJOR       "0")
SET(CPACK_PACKAGE_VERSION_MINOR       "1")
SET(CPACK_PACKAGE_VERSION_PATCH       "0")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY   "CMake ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")

# see [http://www.cmake.org/Wiki/CMake:CPackPackageGenerators]
IF(WIN32)
  MESSAGE(STATUS "Creating NSIS package-installer configuration")

  SET(CPACK_GENERATOR "NSIS")
ELSEIF(UNIX)
  MESSAGE(STATUS "Creating RPM package-installer configuration")

  SET(CPACK_GENERATOR "RPM")
  SET(CPACK_RPM_PACKAGE_SUMMARY     ${CPACK_PACKAGE_DESCRIPTION_SUMMARY})
  SET(CPACK_RPM_PACKAGE_NAME        ${CPACK_PACKAGE_NAME})
  SET(CPACK_RPM_PACKAGE_VERSION     ${CPACK_PACKAGE_VERSION})
  SET(CPACK_RPM_PACKAGE_RELEASE     1)
  SET(CPACK_RPM_PACKAGE_LICENSE     "LGPLv2")
  SET(CPACK_RPM_PACKAGE_GROUP       "Development/Libraries")
  SET(CPACK_RPM_PACKAGE_VENDOR      ${CPACK_PACKAGE_VENDOR})
  SET(CPACK_RPM_PACKAGE_DESCRIPTION ${CPACK_PACKAGE_DESCRIPTION_FILE})
ELSE()
  MESSAGE(SEND_ERROR "Unsupported platform for creating package installer")
ENDIF()

INCLUDE(CPack)
