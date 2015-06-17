// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/viewer/ssbo.hpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_APP_OGLPLUS_VIEWER_SSBO_HPP)

#define UKACHULLDCS_08961_APP_OGLPLUS_VIEWER_SSBO_HPP

// includes, system

#include <GL/glew.h>       // ::gl*
#include <oglplus/all.hpp>

// includes, project

// #include <>

namespace buffer {
  
  // types, exported (class, enum, struct, union, typedef)
  
  class base {

  public:

    virtual ~base() =0;
    
  protected:

    std::string const name_;
    oglplus::Program& prg_;
    oglplus::Buffer   buf_;
    
    explicit base(std::string const& a, oglplus::Program& b)
      : name_(a),
        prg_ (b),
        buf_ ()
    {}
    
  };

  template <typename T>
  class single_value : public base {

  public:

    using value_type = T;

    explicit single_value(std::string const& a, oglplus::Program& b)
      : base(a, b)
    {}
    
    virtual ~single_value()
    {}
    
  private:
    
  };

  template <typename T>
  class multi_value : public base {

  public:

    using value_type = T;

    explicit multi_value(std::string const& a, oglplus::Program& b, unsigned c = 1)
      : base             (a, b),
        ssb_binding_     (c)
    {}
    
    virtual ~multi_value()
    {}

    template <template <typename> class Container>
    void update(Container<T> const& a)
    {
      using namespace oglplus;
      
      ShaderStorageBlock ssb(prg_, name_.c_str());

      ssb.Binding(ssb_binding_);

      buf_.Bind(Buffer::Target::ShaderStorage);
      {
        Buffer::Data(Buffer::Target::ShaderStorage, a, BufferUsage::DynamicDraw);
      }
      buf_.BindBaseShaderStorage(ssb_binding_);
    }

    template <template <typename, std::size_t> class Container, std::size_t N>
    void update(Container<T const, N> const& a)
    {
      using namespace oglplus;
      
      ShaderStorageBlock ssb(prg_, name_.c_str());

      ssb.Binding(ssb_binding_);

      buf_.Bind(Buffer::Target::ShaderStorage);
      {
        Buffer::Data(Buffer::Target::ShaderStorage, a, BufferUsage::DynamicDraw);
      }
      buf_.BindBaseShaderStorage(ssb_binding_);
    }
    
  private:

    unsigned ssb_binding_;
    
  };
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace buffer {

#include <ssbo.inl>

#endif // #if !defined(UKACHULLDCS_08961_APP_OGLPLUS_VIEWER_SSBO_HPP)
