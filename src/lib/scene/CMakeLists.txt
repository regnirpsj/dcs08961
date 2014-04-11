# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

FIND_PACKAGE(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS filesystem)

SET(LIB "scene")

SET(SRC)

LIST(APPEND SRC "node/base.cpp")
LIST(APPEND SRC "node/camera.cpp")
LIST(APPEND SRC "node/dynamic.cpp")
LIST(APPEND SRC "node/geometry.cpp")
LIST(APPEND SRC "node/global_light.cpp")
LIST(APPEND SRC "node/group.cpp")
LIST(APPEND SRC "node/local_light.cpp")
LIST(APPEND SRC "node/material_group.cpp")
LIST(APPEND SRC "node/mesh.cpp")
LIST(APPEND SRC "node/rotor.cpp")
LIST(APPEND SRC "node/select.cpp")
LIST(APPEND SRC "node/transform.cpp")
LIST(APPEND SRC "node/translator.cpp")

LIST(APPEND SRC "object/area_light.cpp")
LIST(APPEND SRC "object/base.cpp")
LIST(APPEND SRC "object/directional_light.cpp")
LIST(APPEND SRC "object/light_source.cpp")
LIST(APPEND SRC "object/material.cpp")
LIST(APPEND SRC "object/positional_light.cpp")
LIST(APPEND SRC "object/spot_light.cpp")
LIST(APPEND SRC "object/texture.cpp")

LIST(APPEND SRC "primitive/cube.cpp")
LIST(APPEND SRC "primitive/cylinder.cpp")
LIST(APPEND SRC "primitive/icosahedron.cpp")
LIST(APPEND SRC "primitive/octahedron.cpp")
LIST(APPEND SRC "primitive/sphere.cpp")
LIST(APPEND SRC "primitive/tetrahedron.cpp")

LIST(APPEND SRC "visitor/base.cpp")
LIST(APPEND SRC "visitor/subject.cpp")

SET(LIBS)
LIST(APPEND LIBS field)
LIST(APPEND LIBS gli)
LIST(APPEND LIBS support)
LIST(APPEND LIBS ${Boost_LIBRARIES})

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)
