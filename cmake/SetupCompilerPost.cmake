# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

FUNCTION(PRINT_LIBRARY_SETUP)
  MESSAGE(STATUS "ATB_LIBRARY               = ${ATB_LIBRARY}")
  MESSAGE(STATUS "BOOST_LIBRARYDIR          = ${BOOST_LIBRARYDIR}")
  MESSAGE(STATUS "Boost_LIBRARY_DIR         = ${Boost_LIBRARY_DIR}")
  MESSAGE(STATUS "Boost_LIBRARY_DIRS        = ${Boost_LIBRARY_DIRS}")
  MESSAGE(STATUS "CMAKE_SHARED_LINKER_FLAGS = ${CMAKE_SHARED_LINKER_FLAGS}")
  MESSAGE(STATUS "CMAKE_MODULE_LINKER_FLAGS = ${CMAKE_MODULE_LINKER_FLAGS}")
  MESSAGE(STATUS "CMAKE_EXE_LINKER_FLAGS    = ${CMAKE_EXE_LINKER_FLAGS}")
ENDFUNCTION()

IF(CMAKE_COMPILER_IS_GNUCC)
  MESSAGE(STATUS "Setting Library Paths for: GCC (v. ${CMAKE_CXX_COMPILER_VERSION})")
ENDIF()

IF(MSVC)
  MESSAGE(STATUS "Setting Library Paths for: MSVC (v. ${CMAKE_CXX_COMPILER_VERSION})")

  # BOOST
  FOREACH(dir ${Boost_LIBRARY_DIRS})
    IF(EXISTS "${dir}" AND IS_DIRECTORY "${dir}")
      SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /LIBPATH:${dir}")
      SET(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} /LIBPATH:${dir}")
      SET(CMAKE_EXE_LINKER_FLAGS    "${CMAKE_EXE_LINKER_FLAGS} /LIBPATH:${dir}")
    ENDIF()
  ENDFOREACH()

  # AntTweakBar
  GET_FILENAME_COMPONENT(atb_lib_dir ${ATB_LIBRARY} PATH)
  IF(EXISTS "${atb_lib_dir}" AND IS_DIRECTORY "${atb_lib_dir}")
    SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /LIBPATH:${atb_lib_dir}")
    SET(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} /LIBPATH:${atb_lib_dir}")
    SET(CMAKE_EXE_LINKER_FLAGS    "${CMAKE_EXE_LINKER_FLAGS} /LIBPATH:${atb_lib_dir}")
  ENDIF()

  IF(VERBOSE)
    PRINT_LIBRARY_SETUP()
  ENDIF()

ENDIF()
