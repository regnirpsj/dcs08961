// -*- Mode:C++ -*-

/**
 *  @file oglplus/shader_cache.ipp
 *  @brief Implementation of ShaderCache
 *
 *  @author Jan P Springer
 *
 *  Copyright 2014 Jan P Springer. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#pragma message "experimental <oglplus/shader_cache.ipp>"

#include <boost/filesystem.hpp> // boost::filesystem::*
#include <climits>              // PATH_MAX

namespace oglplus {

  /* static */ ShaderCache::StringListType ShaderCache::entry_list_;
  /* static */ ShaderCache::StringListType ShaderCache::prefix_list_;

  /* static */ inline void
  ShaderCache::addEntry(std::string const& a, std::string const& b, bool c)
  {
    namespace bfs = boost::filesystem;

    bfs::path p(a);

    if (bfs::exists(p) && bfs::is_regular_file(p)) {
      if (!b.empty()) {
        std::string const name(correctName(a));

        ::glNamedStringARB(GL_SHADER_INCLUDE_ARB,
                           name.length(), name.c_str(),
                           b.length(),    b.c_str());
        
        entry_list_.insert(a);

        if (c) {
          addPrefix(p.parent_path().string());
        }
      }
    }
  }
  
  /* static */ inline void
  ShaderCache::subEntry(std::string const& a)
  {
    if (Exists(a)) {
      std::string const name(correctName(a));
      
      ::glDeleteNamedStringARB(name.length(), name.c_str());
      
      entry_list_.erase(a);
    }
  }
  
  /* static */ inline bool
  ShaderCache::Exists(std::string const& a)
  {
    std::string const name(correctName(a));

    return ::glIsNamedStringARB(name.length(), name.c_str());
  }
  
  /* static */ inline std::string
  ShaderCache::Source(std::string const& a)
  {
    static signed const max_len(PATH_MAX);
    
    std::string const name(correctName(a));
    signed            len (0);
    char*             src (new char [max_len]);
    
    ::glGetNamedStringARB(name.length(), name.c_str(), max_len, &len, src);
    
    std::string const result(src);

    delete [] src;
    
    return result;
  }
  
  /* static */ inline void
  ShaderCache::addPrefix(std::string const& a)
  {
    prefix_list_.insert(correctName(a));
  }
  
  /* static */ inline void
  ShaderCache::subPrefix(std::string const& a)
  {
    prefix_list_.erase(correctName(a));
  }

  /* static */ inline ShaderCache::StringListType
  ShaderCache::Prefixes()
  {
    return prefix_list_;
  }

  /* static */ inline void
  ShaderCache::clearAll()
  {
    clearEntries();
    clearPrefixes();
  }
  
  /* static */ inline void
  ShaderCache::clearEntries()
  {
    while (!entry_list_.empty()) {
      subEntry(*(entry_list_.begin()));
    }
  }

  
  /* static */ inline void
  ShaderCache::clearPrefixes()
  {
    while (!prefix_list_.empty()) {
      subPrefix(*(prefix_list_.begin()));
    }
  }

  /* static */ inline std::string
  ShaderCache::correctName(std::string const& a)
  {
    std::string result(a);

    if (result.length() && ('/' != result[0])) {
      result = '/' + result;
    }
    
    return result;
  }
  
} // namespace oglplus {
