// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/geometry.hpp                                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_NODE_GEOMETRY_HPP)

#define UKACHULLDCS_08961_SCENE_NODE_GEOMETRY_HPP

// includes, system

#include <glm/glm.hpp> // glm::vec[3|4]
#include <iosfwd>      // std::ostream (fwd)

// includes, project

#include <field/value_multi.hpp>
#include <scene/node/base.hpp>

namespace scene {

  namespace node {
    
    // types, exported (class, enum, struct, union, typedef)

    class geometry : public base {

    public:

      typedef base subject_inherited;

      struct attribute {

      public:
        
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 tcoord;
        glm::vec4 tangent;
        glm::vec4 color;

        explicit attribute(glm::vec3 const& /* position */ = glm::vec3(0.0),
                           glm::vec3 const& /* normal */   = glm::vec3(0.0),
                           glm::vec2 const& /* tcoord */   = glm::vec2(0.0),
                           glm::vec4 const& /* tangent */  = glm::vec4(0.0),
                           glm::vec4 const& /* color */    = glm::vec4(1.0));
        
      };
      
      field::value::multi<attribute> attributes;
      field::value::multi<unsigned>  indices;

      virtual ~geometry() =0;

      virtual void accept(visitor::base&);

      void compute_bounds();
      void compute_tangents();
      
    protected:

      explicit geometry(std::string const& /* name */);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)

    bool operator==(geometry::attribute const&, geometry::attribute const&);
    
    // functions, exported (extern)

    std::ostream& operator<<(std::ostream&, geometry::attribute const&);
    
  } // namespace node {
  
} // namespace scene {

#include <scene/node/geometry.inl>

#endif // #if !defined(UKACHULLDCS_08961_SCENE_NODE_GEOMETRY_HPP)
