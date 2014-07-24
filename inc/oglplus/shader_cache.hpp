// -*- Mode:C++ -*-

/**
 *  @file oglplus/shader_cache.hpp
 *  @brief ShaderCache
 *
 *  @author Jan P Springer
 *
 *  Copyright 2014 Jan P Springer. Distributed under the Boost
 *  Software License, Version 1.0. (See accompanying file
 *  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#pragma once
#ifndef OGLPLUS_SHADER_CACHE_2307142200_HPP
#define OGLPLUS_SHADER_CACHE_2307142200_HPP

#pragma message "experimental <oglplus/shader_cache.hpp>"

#include <string>        // std::string
#include <unordered_set> // std::unordered_set<>

namespace oglplus {

  class ShaderCache {

  public:

    typedef std::unordered_set<std::string> StringListType;
    
    /**
     * \brief cache entry functions
     */
    //@{
    static void addEntry(std::string const& /* path/file name */,
                         std::string const& /* source */,
                         bool               /* add base path to prefix list */ = true);
    static void subEntry(std::string const& /* path/file name */);

    static bool        Exists(std::string const& /* path/file name */);
    static std::string Source(std::string const& /* path/file name */);
    //@}

    /**
     * \brief path prefix functions
     */
    //@{
    static void addPrefix(std::string const& /* path name */);
    static void subPrefix(std::string const& /* path name */);

    static StringListType PrefixList();
    //@}

    /**
     * \brief clear cache(s)
     */
    //@{
    static void clearAll();
    static void clearEntryList();
    static void clearPrefixList();
    //@}

  private:

    static StringListType entry_list_;
    static StringListType prefix_list_;

    /**
     * \brief returns corrected name by prepending '/' (if necessary)
     */
    static std::string correctName(std::string const&);
    
  };
  
} // namespace oglplus {

#if !OGLPLUS_LINK_LIBRARY || defined(OGLPLUS_IMPLEMENTING_LIBRARY)
#include <oglplus/shader_cache.ipp>
#endif // OGLPLUS_LINK_LIBRARY

#endif // include guard
