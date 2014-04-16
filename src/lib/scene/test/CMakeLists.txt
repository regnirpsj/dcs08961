# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2014 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

FIND_PACKAGE(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS unit_test_framework)

SET(SRC)

# LIST(APPEND SRC "node_camera.cpp")
LIST(APPEND SRC "node_global_light.cpp")
LIST(APPEND SRC "node_group.cpp")
LIST(APPEND SRC "node_local_light.cpp")
LIST(APPEND SRC "node_material_group.cpp")
LIST(APPEND SRC "node_mesh.cpp")
LIST(APPEND SRC "node_rotor.cpp")
LIST(APPEND SRC "node_select.cpp")
LIST(APPEND SRC "node_transform.cpp")
LIST(APPEND SRC "node_translator.cpp")

LIST(APPEND SRC "objects_light.cpp")
LIST(APPEND SRC "objects_material.cpp")
LIST(APPEND SRC "objects_texture.cpp")

LIST(APPEND SRC "primitive_cube.cpp")
LIST(APPEND SRC "primitive_cylinder.cpp")
LIST(APPEND SRC "primitive_icosahedron.cpp")
LIST(APPEND SRC "primitive_octahedron.cpp")
LIST(APPEND SRC "primitive_sphere.cpp")
LIST(APPEND SRC "primitive_tetrahedron.cpp")

LIST(APPEND SRC "visitor_print.cpp")

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

SET(LIBS)
LIST(APPEND LIBS ${LIB})
LIST(APPEND LIBS ${Boost_LIBRARIES})

IF(UNIX)
  LIST(APPEND LIBS rt)
ENDIF()

TEST_SETUP(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})
