# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2015 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

if(VERBOSE)
  message(STATUS "Loading ${PROJECT_NAME} options")
endif()

# tracing
option(DCS08961_TRACE_ALL "Enable runtime function tracing for everything!" OFF)
