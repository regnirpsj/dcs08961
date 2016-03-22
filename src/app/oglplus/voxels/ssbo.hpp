// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  app/oglplus/voxels/ssbo.hpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_APP_OGLPLUS_VOXELS_SSBO_HPP)

#define UKACHULLDCS_08961_APP_OGLPLUS_VOXELS_SSBO_HPP

// includes, system

#include <GL/glew.h>       // ::gl*
#include <oglplus/all.hpp>
#include <array>           // std::array<>
#include <vector>          // std::vector<>

// includes, project

// #include <>

namespace buffer {
  
  // types, exported (class, enum, struct, union, typedef)

  class slot_manager {

  public:

    explicit slot_manager(unsigned);
    
    unsigned alloc();
    void     release(unsigned);
    
  private:

    std::vector<bool> slots_;
    
  };
  
  class base {
    
  public:

    virtual ~base() =0;
    
  protected:

    static slot_manager slot_mgr;
    
    std::string const name_;
    oglplus::Program& prg_;
    oglplus::Buffer   buf_;
    
    explicit base(std::string const&, oglplus::Program&);
    
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

    explicit multi_value(std::string const& a, oglplus::Program& b)
      : base        (a, b),
        ssb_binding_(slot_mgr.alloc())
    {}
    
    virtual ~multi_value()
    {
      slot_mgr.release(ssb_binding_);
    }
    
    void update(std::vector<T> const& a)
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

    template <std::size_t N>
    void update(std::array<T const, N> const& a)
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

#endif // #if !defined(UKACHULLDCS_08961_APP_OGLPLUS_VOXELS_SSBO_HPP)
