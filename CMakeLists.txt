# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014-2015 University of Hull                                                       #
#                                                                                                  #
####################################################################################################

cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project(DCS08961 VERSION 0.0.1)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../cmake-modules-git/cmake")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(CheckOutOfTreeBuild)
include(SetupInitialCache)
include(SetupBuildType)
include(SetupPlatformAndArchitecture)
include(SetupFunctionsAndMacros)

cma_print_current_directory()

include(SetupCompilerDefaults)
include(SetupProjectDefaults)
include(SetupUnitTests)

include_directories(${CMAKE_SOURCE_DIR}/inc)
include_directories(${CMAKE_BINARY_DIR}/exports)

add_subdirectory(doc)
add_subdirectory(share)
add_subdirectory(src)

include(ShowConfigSummary)

# keep last
include(SetupPackaging)
