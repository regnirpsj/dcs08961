# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

# FXC_COMPILE(RESULT TYPE ENTRY SOURCES .. [INCLUDES ..] [DEPENDENCIES ..] [DEBUG])

FUNCTION(FXC_COMPILE FXC_RESULT FXC_TYPE FXC_ENTRY)
  IF(NOT FXC)
    FIND_PROGRAM(FXC fxc HINTS ${WINDOWS8SDK_DIR}/${ARCH}/bin DOC "DirectX shader compiler")
    IF(NOT FXC)
      MESSAGE(SEND_ERROR "Error: unable to find DirectX shader compiler (fxc)")
    ELSE()
      MESSAGE(STATUS "Found DirectX shader compiler: ${FXC}")
    ENDIF()
  ENDIF()

  SET(OARGS DEBUG)
  SET(SARGS)
  SET(MARGS SOURCES INCLUDES DEPENDENCIES)
  CMAKE_PARSE_ARGUMENTS(FXC "${OARGS}" "${SARGS}" "${MARGS}" ${ARGN})

  # note: fxc does't like spaces between options and arguments, i.e.
  #       '/X x' will not work, while '/Xx' is ok

  SET(FXC_FLAGS)
  LIST(APPEND FXC_FLAGS "/nologo")           # suppress copyright message
  LIST(APPEND FXC_FLAGS "/Cc")               # output color coded assembly listings
  LIST(APPEND FXC_FLAGS "/Ges")              # enable strict mode
  LIST(APPEND FXC_FLAGS "/Gis")              # force IEEE strictness
  LIST(APPEND FXC_FLAGS "/T${FXC_TYPE}_5_0") # target profile
  LIST(APPEND FXC_FLAGS "/Zpc")              # pack matrices in column-major order

  IF("Release" STREQUAL "${CMAKE_BUILD_TYPE}")
    LIST(APPEND FXC_FLAGS "/O3")             # optimization level 0..3.  1 is default
    LIST(APPEND FXC_FLAGS "/Qstrip_debug")   # strip debug information from 4_0+ shader bytecode
    LIST(APPEND FXC_FLAGS "/Qstrip_priv")    # strip private data from 4_0+ shader bytecode
  ELSE()
    LIST(APPEND FXC_FLAGS "/O2")             # optimization level 0..3.  1 is default
    LIST(APPEND FXC_FLAGS "/Zi")             # enable debugging information

    IF("DEBUG" STREQUAL "${CMAKE_BUILD_TYPE}")
      LIST(APPEND FXC_FLAGS "/D_DEBUG=1")
      LIST(APPEND FXC_FLAGS "/DDEBUG=1")
    ENDIF()
  ENDIF()

  IF(FXC_DEBUG)
    LIST(APPEND FXC_FLAGS "/Vi") # display details about the include process
  ENDIF()

  FOREACH(path ${FXC_INCLUDES})
    IF(NOT "" STREQUAL "${path}")
      LIST(APPEND FXC_FLAGS "/I${path}")
    ENDIF()
  ENDFOREACH()  

  SET(FXC_DEPENDENCIES_ABS)
  FOREACH(file ${FXC_DEPENDENCIES})
    GET_FILENAME_COMPONENT(file_abs ${file} ABSOLUTE)
    LIST(APPEND FXC_DEPENDENCIES_ABS ${file_abs})
  ENDFOREACH()

  IF(FXC_DEBUG OR VERBOSE)
    MESSAGE(STATUS "FXC_COMPILE() variable setup:\n"
      "   FXC_RESULT           = ${FXC_RESULT}\n"
      "   FXC_TYPE             = ${FXC_TYPE}\n"
      "   FXC_ENTRY            = ${FXC_ENTRY}\n"
      "   FXC_SOURCES          = ${FXC_SOURCES}\n"
      "   FXC_INCLUDES         = ${FXC_INCLUDES}\n"
      "   FXC_DEPENDENCIES     = ${FXC_DEPENDENCIES}\n"
      "   FXC_DEPENDENCIES_ABS = ${FXC_DEPENDENCIES_ABS}\n"
      "   FXC_FLAGS            = ${FXC_FLAGS}")
  ENDIF()
  
  IF(NOT FXC_SOURCES)
    MESSAGE(SEND_ERROR "Error: FXC_COMPILE() called without any source files")
    RETURN()
  ENDIF()  

  SET(${FXC_RESULT})

  FOREACH(file ${FXC_SOURCES})
    GET_FILENAME_COMPONENT(path    ${file} PATH)
    GET_FILENAME_COMPONENT(src_rel ${file} NAME)
    GET_FILENAME_COMPONENT(src_abs ${file} ABSOLUTE)
    GET_FILENAME_COMPONENT(dst     ${file} NAME_WE)
    
    SET(dst_name "${dst}_${FXC_TYPE}_${FXC_ENTRY}")
    SET(dst_file "${dst_name}.inc")
    
    IF(NOT "" STREQUAL "${path}")
      SET(dst_file "${path}/${dst_file}")
    ENDIF()

    LIST(APPEND ${FXC_RESULT} "${CMAKE_CURRENT_BINARY_DIR}/${dst_file}")
    
    ADD_CUSTOM_COMMAND(
      OUTPUT          "${CMAKE_CURRENT_BINARY_DIR}/${dst_file}"
      COMMAND          ${FXC}
      ARGS             ${FXC_FLAGS} /E${FXC_ENTRY} /Vn${dst_name} /Fh${dst_file} ${src_abs}
      MAIN_DEPENDENCY  ${src_abs}
      DEPENDS          ${FXC_DEPENDENCIES_ABS} ${FXC_DEPENDENCIES}
      COMMENT         "Compiling HLSL shader ${src_rel} (${FXC_TYPE},${FXC_ENTRY}) to ${dst_file}"
      VERBATIM)
  ENDFOREACH()
  
  SET_SOURCE_FILES_PROPERTIES(${${FXC_RESULT}} PROPERTIES GENERATED TRUE)
  SET(${FXC_RESULT} ${${FXC_RESULT}} PARENT_SCOPE)
ENDFUNCTION()

# LIBRARY_SETUP(NAME SOURCES .. [DEPENDENCIES ..] [DEBUG])

FUNCTION(LIBRARY_SETUP LIB_NAME)
  SET(OARGS DEBUG)
  SET(SARGS)
  SET(MARGS SOURCES DEPENDENCIES)
  CMAKE_PARSE_ARGUMENTS(LIB "${OARGS}" "${SARGS}" "${MARGS}" ${ARGN})
  
  FILE(GLOB_RECURSE PUBHDRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/inc/${LIB_NAME}/*.hpp)
  LIST(APPEND LIB_SOURCES ${PUBHDRS})
  
  FILE(GLOB_RECURSE PUBINLS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/inc/${LIB_NAME}/*.inl)
  LIST(APPEND LIB_SOURCES ${PUBINLS})
  
  FILE(GLOB_RECURSE PRVHDRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)
  
  LIST(APPEND LIB_SOURCES ${PRVHDRS})
  
  IF(LIB_DEBUG OR VERBOSE)
    MESSAGE(STATUS "LIBRARY_SETUP(${LIB_NAME}) variable setup:\n"
      "   LIB_NAME         = ${LIB_NAME}\n"
      "   LIB_SOURCES      = ${LIB_SOURCES}\n"
      "   LIB_DEPENDENCIES = ${LIB_DEPENDENCIES}")
  ENDIF()
  
  ADD_LIBRARY(${LIB_NAME} ${CMAKE_LIBRARY_TYPE} ${LIB_SOURCES})
  
  SET_PROPERTY(TARGET ${LIB} PROPERTY FOLDER "Libraries")
  SOURCE_GROUP(Source          REGULAR_EXPRESSION ".+\\.cpp")
  SOURCE_GROUP(Header\\Public  REGULAR_EXPRESSION ".+/inc/${LIB_NAME}/.+\\.(hpp|inl)")
  SOURCE_GROUP(Header\\Private REGULAR_EXPRESSION ".+\\.hpp")
  
  TARGET_LINK_LIBRARIES(${LIB_NAME} ${LIB_DEPENDENCIES})
  
  # INSTALL(TARGETS ${LIB_NAME} DESTINATION ${DCSC08961_LIBRARY_DIRECTORY} COMPONENT runtime)
ENDFUNCTION()

# TEST_SETUP(PREFIX SOURCES ... [DEPENDENCIES ..] [DEBUG])

FUNCTION(TEST_SETUP TST_PREFIX)
  SET(OARGS DEBUG)
  SET(SARGS)
  SET(MARGS SOURCES DEPENDENCIES)
  CMAKE_PARSE_ARGUMENTS(TST "${OARGS}" "${SARGS}" "${MARGS}" ${ARGN})

  IF(TST_DEBUG OR VERBOSE)
    MESSAGE(STATUS "TEST_SETUP(${TST_PREFIX}) variable setup:\n"
      "   TST_PREFIX       = ${TST_PREFIX}\n"
      "   TST_SOURCES      = ${TST_SOURCES}\n"
      "   TST_DEPENDENCIES = ${TST_DEPENDENCIES}")
  ENDIF()

  SET(TST_EXES)
  SET(TST_TESTS)
  
  FOREACH(APP ${TST_SOURCES})
    GET_FILENAME_COMPONENT(EXE "test_${TST_PREFIX}_${APP}" NAME_WE)
    ADD_EXECUTABLE(${EXE} EXCLUDE_FROM_ALL ${APP})
    SET_PROPERTY(TARGET ${EXE} PROPERTY FOLDER "Tests/${TST_PREFIX}")
    TARGET_LINK_LIBRARIES(${EXE} ${TST_DEPENDENCIES})
    ADD_TEST(${EXE} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${EXE})
    LIST(APPEND TST_EXES ${EXE})
    
    GET_FILENAME_COMPONENT(TEST "unit_test_${TST_PREFIX}_${APP}" NAME_WE)
    ADD_CUSTOM_TARGET(${TEST} COMMAND ${EXE} DEPENDS ${EXE} SOURCES ${APP})
    LIST(APPEND TST_TESTS ${TEST})
  ENDFOREACH(APP)
  
  IF(TST_DEBUG OR VERBOSE)
    MESSAGE(STATUS "TEST_SETUP(${TST_PREFIX}) target setup:\n"
      "   TST_EXES         = ${TST_EXES}\n"
      "   TST_TESTS        = ${TST_TESTS}")
  ENDIF()
  
  IF(DCSC08961_BLD_UTEST)
    IF(DCSC08961_RUN_CTEST)
      ADD_CUSTOM_TARGET(test_${TST_PREFIX} COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS ${TST_EXES})
    ELSEIF(DCSC08961_RUN_UTEST)
      ADD_CUSTOM_TARGET(test_${TST_PREFIX} DEPENDS ${TST_TESTS})
    ELSE()
      ADD_CUSTOM_TARGET(test_${TST_PREFIX} DEPENDS ${TST_EXES})
    ENDIF()
    SET_PROPERTY(TARGET test_${TST_PREFIX} PROPERTY FOLDER "Tests/${TST_PREFIX}")
    ADD_DEPENDENCIES(test_libs test_${TST_PREFIX})
  ENDIF()
ENDFUNCTION()