# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

SET(LIB "glm")

SET(SRC)

LIST(APPEND SRC "gtx/limits.cpp")
LIST(APPEND SRC "gtx/utilities.cpp")

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES)

ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)
