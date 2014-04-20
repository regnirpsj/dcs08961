# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

# testing
OPTION(DCSC08961_BLD_UTEST "Enable unit-test building by default"                          ON)
OPTION(DCSC08961_RUN_CTEST "Enable unit-test execution using CTest by default"             ON)
OPTION(DCSC08961_RUN_UTEST "Enable unit-test execution using the build system by default" OFF)

# coverage testing
OPTION(DCSC08961_PROFILE   "Enable support for coverage testing" OFF)

# tracing
OPTION(DCSC08961_TRACE_ALL "Enable runtime function tracing for everything!" OFF)
