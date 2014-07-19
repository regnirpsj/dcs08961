# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

IF(DCS08961_BLD_UTEST)
  ADD_CUSTOM_TARGET(test_all)
  SET_PROPERTY(TARGET test_all PROPERTY FOLDER "Tests")
ENDIF()

IF(DCS08961_BLD_UTEST)
  ADD_CUSTOM_TARGET(test_libs)
  SET_PROPERTY(TARGET test_libs PROPERTY FOLDER "Tests")
  ADD_DEPENDENCIES(test_all test_libs)
ENDIF()

ADD_SUBDIRECTORY(app)
ADD_SUBDIRECTORY(lib)
