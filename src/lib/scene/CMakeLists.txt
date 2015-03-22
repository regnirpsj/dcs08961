# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014-2015 University of Hull                                                       #
#                                                                                                  #
####################################################################################################

MESSAGE(STATUS "Setting up: ${CMAKE_CURRENT_SOURCE_DIR}")

FIND_PACKAGE(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS filesystem)

# ADD_DEFINITIONS("-DUKACHULLDCS_ALL_TRACE")

SET(LIB "scene")

SET(SRC)

LIST(APPEND SRC "file.cpp")

LIST(APPEND SRC "loader/mtl.cpp")
LIST(APPEND SRC "loader/obj.cpp")

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

LIST(APPEND SRC "object/base.cpp")
LIST(APPEND SRC "object/camera/base.cpp")
LIST(APPEND SRC "object/camera/frustum.cpp")
LIST(APPEND SRC "object/camera/orthographic.cpp")
LIST(APPEND SRC "object/camera/perspective.cpp")
LIST(APPEND SRC "object/camera/viewport.cpp")
LIST(APPEND SRC "object/light/area.cpp")
LIST(APPEND SRC "object/light/base.cpp")
LIST(APPEND SRC "object/light/directional.cpp")
LIST(APPEND SRC "object/light/positional.cpp")
LIST(APPEND SRC "object/light/spot.cpp")
LIST(APPEND SRC "object/material.cpp")
LIST(APPEND SRC "object/texture/base.cpp")
LIST(APPEND SRC "object/texture/d1.cpp")
LIST(APPEND SRC "object/texture/d2.cpp")
LIST(APPEND SRC "object/texture/d3.cpp")
LIST(APPEND SRC "object/texture/fill.cpp")
LIST(APPEND SRC "object/texture/load.cpp")

LIST(APPEND SRC "primitive/cube.cpp")
LIST(APPEND SRC "primitive/cylinder.cpp")
LIST(APPEND SRC "primitive/icosahedron.cpp")
LIST(APPEND SRC "primitive/octahedron.cpp")
LIST(APPEND SRC "primitive/sphere.cpp")
LIST(APPEND SRC "primitive/tetrahedron.cpp")

LIST(APPEND SRC "visitor/base.cpp")
LIST(APPEND SRC "visitor/bfs.cpp")
#LIST(APPEND SRC "visitor/collect.cpp")
LIST(APPEND SRC "visitor/cull.cpp")
LIST(APPEND SRC "visitor/dfs.cpp")
#LIST(APPEND SRC "visitor/intersect.cpp")
LIST(APPEND SRC "visitor/print.cpp")
LIST(APPEND SRC "visitor/subject.cpp")
LIST(APPEND SRC "visitor/update_bounds.cpp")

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

SET(LIBS)
LIST(APPEND LIBS field)
LIST(APPEND LIBS gli)
LIST(APPEND LIBS glm)
LIST(APPEND LIBS support)
LIST(APPEND LIBS ${Boost_LIBRARIES})

LIBRARY_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
EXPORT_SETUP(${LIB})

ADD_SUBDIRECTORY(test EXCLUDE_FROM_ALL)
