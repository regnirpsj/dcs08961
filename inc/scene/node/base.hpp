// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/node/base.hpp                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_NODE_BASE_HPP)

#define UKACHULLDCS_08961_SCENE_NODE_BASE_HPP

// includes, system

#include <glm/glm.hpp> // glm::mat4, glm::vec3

// includes, project

#include <field/adapter_single.hpp>
#include <scene/object/base.hpp>
#include <scene/visitor/subject.hpp>

namespace scene {

  namespace node {
    
    // types, exported (class, enum, struct, union, typedef)

    class base : public object::base,
                 public visitor::subject {

    public:

      typedef visitor::subject subject_inherited;

      struct bounds {

      public:

        static bounds const invalid; // { [+inf, +inf, +inf], [-inf, -inf, -inf], false, }

        glm::vec3 min;
        glm::vec3 max;
        bool      valid;

        explicit bounds(glm::vec3 const& /* min */   = invalid.min,
                        glm::vec3 const& /* max */   = invalid.max,
                        bool             /* valid */ = invalid.valid);
        
      };
      
      
      field::adapter::single<base*>  parent;
      field::value::single<unsigned> travmask;
      field::value::single<bounds>   bbox;

      virtual ~base() =0;
      
      virtual void accept(visitor::base&) =0;
      
      virtual void print_on(std::ostream&) const;

      virtual glm::mat4 absolute_parent_xform() const;
      virtual glm::mat4 absolute_xform() const;
      
    protected:

      friend class group; // indirect access to parent_
      
      base* parent_;
      
      explicit base(std::string const& /* name */);

      virtual void evaluate();
      virtual void changed(field::base&);

      virtual void invalidate_bounds();
      
    private:
      
      base* cb_get_parent() const;
      base* cb_set_parent(base*);
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)

    bool operator==(base::bounds const&, base::bounds const&);
    bool operator!=(base::bounds const&, base::bounds const&);
    
    // functions, exported (extern)

    std::ostream& operator<<(std::ostream&, base::bounds const&);
    
  } // namespace node {

} // namespace scene {

#include <scene/node/base.inl>

#endif // #if !defined(UKACHULLDCS_08961_SCENE_NODE_BASE_HPP)
