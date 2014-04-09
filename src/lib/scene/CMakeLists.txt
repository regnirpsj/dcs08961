# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

SET(LIB "scene")

SET(SRC)

LIST(APPEND SRC "node/base.cpp")

LIST(APPEND SRC "object/area_light.cpp")
LIST(APPEND SRC "object/base.cpp")
LIST(APPEND SRC "object/directional_light.cpp")
LIST(APPEND SRC "object/light_source.cpp")
LIST(APPEND SRC "object/material.cpp")
LIST(APPEND SRC "object/positional_light.cpp")
LIST(APPEND SRC "object/spot_light.cpp")

# LIST(APPEND SRC "primitive/.cpp")

LIST(APPEND SRC "visitor/base.cpp")
LIST(APPEND SRC "visitor/subject.cpp")

SET(LIBS)
LIST(APPEND LIBS field)
LIST(APPEND LIBS support)

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)
