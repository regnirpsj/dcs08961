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

ADD_SUBDIRECTORY(app)
ADD_SUBDIRECTORY(lib)
