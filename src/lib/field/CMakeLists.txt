# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

SET(LIB "field")

SET(SRC)

LIST(APPEND SRC "adapter_multi.cpp")
LIST(APPEND SRC "adapter_single.cpp")
LIST(APPEND SRC "base.cpp")
LIST(APPEND SRC "container.cpp")
LIST(APPEND SRC "defaults.cpp")
LIST(APPEND SRC "value_multi.cpp")
LIST(APPEND SRC "value_single.cpp")

SET(LIBS)
LIST(APPEND LIBS support)

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)
