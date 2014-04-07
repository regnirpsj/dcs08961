# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

IF(DCSC08961_BLD_UTEST)
  ADD_CUSTOM_TARGET(test_libs)
  SET_PROPERTY(TARGET test_libs PROPERTY FOLDER "Tests")
  ADD_DEPENDENCIES(test_all test_libs)
ENDIF()

ADD_SUBDIRECTORY(field)
ADD_SUBDIRECTORY(gli)
ADD_SUBDIRECTORY(glm)
ADD_SUBDIRECTORY(scene)
ADD_SUBDIRECTORY(support)
