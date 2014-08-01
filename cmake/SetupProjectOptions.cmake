# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

# glibcxx parallel support
OPTION(DCS08961_GLIBCXX_PARALLEL "Enable GLIBCXX parallel mode" OFF)

# doxygen docs
OPTION(DCS08961_DOC_DEV "Enable generation of developer documentation" OFF)
OPTION(DCS08961_DOC_USR "Enable generation of user documentation"      OFF)

# unit testing
OPTION(DCS08961_BLD_UTEST "Enable unit-test building by default"                          ON)
OPTION(DCS08961_RUN_CTEST "Enable unit-test execution using CTest by default"             ON)
OPTION(DCS08961_RUN_UTEST "Enable unit-test execution using the build system by default" OFF)

# coverage testing
OPTION(DCS08961_PROFILE   "Enable support for coverage testing" OFF)

# tracing
OPTION(DCS08961_TRACE_ALL "Enable runtime function tracing for everything!" OFF)
