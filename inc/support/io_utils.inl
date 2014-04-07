// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  support/io_utils.inl                                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SUPPORT_IO_UTILS_INL)

#define UKACHULLDCS_08961_SUPPORT_IO_UTILS_INL

// includes, system

#include <boost/io/ios_state.hpp> // boost::io::ios_all_saver
#include <iomanip>                // std::setfill<>, std::fixed, std::setprecision, std::right,
#include <istream>                // std::basic_istream<>
#include <ostream>                // std::basic_ostream<>

// includes, project

// #include <>

namespace support {

  namespace istream {
    
    // functions, inlined (inline)

    template <typename CTy, typename CTr>
    /* explicit */ inline
    position_saver<CTy,CTr>::position_saver(std::basic_istream<CTy,CTr>& s)
      : boost::noncopyable(),
        s_                (s),
        p_                (s_.tellg())
    {}

    template <typename CTy, typename CTr>
    inline
    position_saver<CTy,CTr>::~position_saver()
    {
      restore();
    }

    template <typename CTy, typename CTr>
    inline void
    position_saver<CTy,CTr>::restore()
    {
      s_.seekg(p_);
    }
    
  } // namespace istream {

  namespace ostream {
    
    // functions, inlined (inline)

    template <typename CTy, typename CTr>
    inline /* explicit */
    position_saver<CTy,CTr>::position_saver(std::basic_ostream<CTy,CTr>& s)
      : boost::noncopyable(),
        s_                (s),
        p_                (s_.tellp())
    {}
  
    template <typename CTy, typename CTr>
    inline
    position_saver<CTy,CTr>::~position_saver()
    {
      restore();
    }

    template <typename CTy, typename CTr>
    inline void
    position_saver<CTy,CTr>::restore()
    {
      s_.seekp(p_);
    }
    
    template <typename CTy, typename CTr>
    /* explicit */ inline
    scoped_redirect<CTy,CTr>::scoped_redirect(std::basic_ostream<CTy,CTr>& a,
                                              std::basic_ostream<CTy,CTr>& b)
      : boost::noncopyable(),
        s_              (a),
        b_              (s_.rdbuf(b.rdbuf()))
    {}

    template <typename CTy, typename CTr>
    inline
    scoped_redirect<CTy,CTr>::~scoped_redirect()
    {
      s_.rdbuf(b_);
    }

    template <typename CTy>
    /* explicit */ inline
    format_punct<CTy>::format_punct(size_t a)
      : std::locale::facet(a),
        formatted         (true),
        separator         (','), 
        delim_left        ('('), 
        delim_right       (')'),
        space             (' ')
    {}
    
    template <typename CTy>
    /* explicit */ inline
    format_punct<CTy>::format_punct(format_punct const& a)
      : std::locale::facet(0),
        formatted         (a.formatted),
        separator         (a.separator),
        delim_left        (a.delim_left),
        delim_right       (a.delim_right),
        space             (a.space)
    {}

    template <typename CTy> std::locale::id format_punct<CTy>::id;

    template <typename CTy, typename CTr>
    /* explicit */ inline
    basic_format_saver<CTy,CTr>::basic_format_saver(std::basic_ios<CTy,CTr>& a)
      : boost::noncopyable(),
        ias_              (a)
    {   
      a.imbue(std::locale(a.getloc(), new format_punct<CTy>(get_facet<format_punct<CTy>>(a))));
    } 
    
    template <typename CTy, typename CTr>
    inline
    basic_format_saver<CTy,CTr>::~basic_format_saver()
    {}

    template <typename CTy>
    /* explicit */ inline
    delimeter<CTy>::delimeter(CTy a, CTy b, CTy c)
      : value()
    { 
      value[0] = a;
      value[1] = b;
      value[2] = c;
    }

    template <typename FTy, typename CTy, typename CTr>
    inline FTy const&
    get_facet(std::basic_ios<CTy,CTr>& ios)
    {
      if (!std::has_facet<FTy>(ios.getloc())) {
        ios.imbue(std::locale(ios.getloc(), new FTy));
      } 
      
      return std::use_facet<FTy>(ios.getloc());
    }
    
    template <typename CTy, typename CTr>
    std::basic_ios<CTy,CTr>&
    formatted(std::basic_ios<CTy,CTr>& os)
    {
      const_cast<format_punct<CTy>&>(get_facet<format_punct<CTy>>(os)).formatted = true;
      
      return os;
    }

    template <typename CTy, typename CTr>
    std::basic_ios<CTy,CTr>&
    unformatted(std::basic_ios<CTy,CTr>& os)
    {
      const_cast<format_punct<CTy>&>(get_facet<format_punct<CTy>>(os)).formatted = false;
      
      return os;
    }

    template <typename CTy, typename CTr>
    std::basic_ostream<CTy, CTr>& operator<<(std::basic_ostream<CTy, CTr>& os,
                                             delimeter<CTy> const& a)
    {                                        
      format_punct<CTy>& fmt(const_cast<format_punct<CTy>&>(get_facet<format_punct<CTy>>(os)));
      
      fmt.delim_left  = a.value[0];
      fmt.delim_right = a.value[1];
      fmt.separator   = a.value[2];

      return os;
    }
    
    template <typename CTy, typename CTr,
              typename T>
    inline std::basic_ostream<CTy,CTr>&
    operator<<(std::basic_ostream<CTy,CTr>& os, std::pair<T, T> const& a)
    {
      typename std::basic_ostream<CTy,CTr>::sentry const cerberus(os);
    
      if (cerberus) {
        format_punct<CTy> const& fmt(get_facet<format_punct<CTy>>(os));
        
        if (fmt.formatted) {
          basic_format_saver<CTy> const bfs(os);
          
          os << fmt.delim_left << a.first << fmt.separator << a.second << fmt.delim_right;
        } else {
          os << a.first << fmt.space << a.second;
        }
      }
      
      return os;
    }
    
    template <typename CTy, typename CTr,
              typename T>
    inline std::basic_ostream<CTy,CTr>&
    operator<<(std::basic_ostream<CTy,CTr>& os, std::pair<T const, T const> const& a)
    {
      typename std::basic_ostream<CTy,CTr>::sentry const cerberus(os);
    
      if (cerberus) {
        format_punct<CTy> const& fmt(get_facet<format_punct<CTy>>(os));

        if (fmt.formatted) {
          os << fmt.delim_left << a.first << fmt.separator << a.second << fmt.delim_right;
        } else {
          os << a.first << fmt.space << a.second;
        }
      }
      
      return os;
    }

    template <typename CTy, typename CTr,
              typename T, typename U>
    inline std::basic_ostream<CTy,CTr>&
    operator<<(std::basic_ostream<CTy,CTr>& os, std::pair<T, U> const& a)
    {
      typename std::basic_ostream<CTy,CTr>::sentry const cerberus(os);
    
      if (cerberus) {
        format_punct<CTy> const& fmt(get_facet<format_punct<CTy>>(os));

        if (fmt.formatted) {
          os << fmt.delim_left << a.first << fmt.separator << a.second << fmt.delim_right;
        } else {
          os << a.first << fmt.space << a.second;
        }
      }
      
      return os;
    }
    
    template <typename CTy, typename CTr,
              typename T, typename U>
    inline std::basic_ostream<CTy,CTr>&
    operator<<(std::basic_ostream<CTy,CTr>& os, std::pair<T const, U const> const& a)
    {
      typename std::basic_ostream<CTy,CTr>::sentry const cerberus(os);
    
      if (cerberus) {
        format_punct<CTy> const& fmt(get_facet<format_punct<CTy>>(os));

        if (fmt.formatted) {
          os << fmt.delim_left << a.first << fmt.separator << a.second << fmt.delim_right;
        } else {
          os << a.first << fmt.space << a.second;
        }
      }
      
      return os;
    }

    template <typename CTy, typename CTr,
              template <typename, std::size_t> class Container, class V, std::size_t N>
    std::basic_ostream<CTy,CTr>& operator<<(std::basic_ostream<CTy,CTr>& os,
                                            Container<V,N> const& a)
    {
      typename std::basic_ostream<CTy,CTr>::sentry const cerberus(os);

      if (cerberus) {
        format_punct<CTy> const& fmt(get_facet<format_punct<CTy>>(os));

        if (fmt.formatted) {
          os << fmt.delim_left;

          for (auto e : a) {
            os << e << fmt.separator;
          }
      
          os << '\b' << fmt.delim_right;
        } else {
          for (auto e : a) {
            os << e << fmt.space;
          }
        }
      }
      
      return os;
    }
    
    template <typename CTy, typename CTr,
              template <typename, typename> class Container, class V, class A>
    inline std::basic_ostream<CTy,CTr>&
    operator<<(std::basic_ostream<CTy,CTr>& os, Container<V,A> const& a)
    {
      typename std::basic_ostream<CTy,CTr>::sentry const cerberus(os);

      if (cerberus) {
        format_punct<CTy> const& fmt(get_facet<format_punct<CTy>>(os));
        
        if (fmt.formatted) {
          os << fmt.delim_left;

          for (auto e : a) {
            os << e << fmt.separator;
          }
      
          os << '\b' << fmt.delim_right;
        } else {
          for (auto e : a) {
            os << e << fmt.space;
          }
        }
      }
      
      return os;
    }

    template <typename CTy, typename CTr,
              template <typename, typename, typename> class Container, class K, class C, class A>
    inline std::basic_ostream<CTy,CTr>&
    operator<<(std::basic_ostream<CTy,CTr>& os, Container<K,C,A> const& a)
    {
      typename std::basic_ostream<CTy,CTr>::sentry const cerberus(os);

      if (cerberus) {
        format_punct<CTy> const& fmt(get_facet<format_punct<CTy>>(os));

        if (fmt.formatted) {
          os << fmt.delim_left;

          for (auto e : a) {
            os << e << fmt.separator;
          }
      
          os << '\b' << fmt.delim_right;
        } else {
          for (auto e : a) {
            os << e << fmt.space;
          }
        }
      }
      
      return os;
    }
  
    template <typename CTy, typename CTr,
              template <typename, typename, typename, typename> class Container, class K, class V,
              class C, class A>
    inline std::basic_ostream<CTy,CTr>&
    operator<<(std::basic_ostream<CTy,CTr>& os, Container<K,V,C,A> const& a)
    {
      typename std::basic_ostream<CTy,CTr>::sentry const cerberus(os);

      if (cerberus) {
        format_punct<CTy> const& fmt(get_facet<format_punct<CTy>>(os));

        // 'os << e << ' ';' does not work because two viable functions are available
        //  - operator<<(std::basic_ostream<CTy,CTr>&, std::pair<T,U> const&)
        //  - operator<<(std::basic_ostream<CTy,CTr>&, Container<V,A> const&)
        
        if (fmt.formatted) {
          os << fmt.delim_left;

          for (auto e : a) {
            os << fmt.delim_left
               << e.first << fmt.separator << e.second
               << fmt.delim_right
               << fmt.separator;
          }
      
          os << '\b' << fmt.delim_right;
        } else {
          for (auto e : a) {
            os << fmt.delim_left
               << e.first << fmt.separator << e.second
               << fmt.delim_right
               << fmt.space;
          }
        }
      }
      
      return os;
    }
  
    template <typename CTy, typename CTr,
              template <typename, typename, typename, typename, typename> class Container, class K,
              class V, class H, class C, class A>
    inline std::basic_ostream<CTy,CTr>&
    operator<<(std::basic_ostream<CTy,CTr>& os, Container<K,V,H,C,A> const& a)
    {
      typename std::basic_ostream<CTy,CTr>::sentry const cerberus(os);

      if (cerberus) {
        format_punct<CTy> const& fmt(get_facet<format_punct<CTy>>(os));

        if (fmt.formatted) {
          os << fmt.delim_left;

          for (auto e : a) {
            os << fmt.delim_left
               << e.first << fmt.separator << e.second
               << fmt.delim_right
               << fmt.separator;
          }
      
          os << '\b' << fmt.delim_right;
        } else {
          for (auto e : a) {
            os << fmt.delim_left
               << e.first << fmt.separator << e.second
               << fmt.delim_right
               << fmt.space;
          }
        }
      }
      
      return os;
    }

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1700))
    template <typename CTy, typename CTr,
              typename T>
    inline std::basic_ostream<CTy,CTr>&
    operator<<(std::basic_ostream<CTy,CTr>& os, std::initializer_list<T> a)
    {
      typename std::basic_ostream<CTy,CTr>::sentry const cerberus(os);

      if (cerberus) {
        format_punct<CTy> const& fmt(get_facet<format_punct<CTy>>(os));

        if (fmt.formatted) {
          os << fmt.delim_left;

          for (auto e : a) {
            os << e << fmt.separator;
          }
      
          os << '\b' << fmt.delim_right;
        } else {
          for (auto e : a) {
            os << e << fmt.space;
          }
        }
      }
      
      return os;
    }
#endif

  } // namespace ostream {
  
  namespace iostream {
    
    // functions, inlined (inline)

    template <typename CTy, typename CTr>
    /* explicit */ inline
    position_saver<CTy,CTr>::position_saver(std::basic_iostream<CTy,CTr>& s)
      : istream::position_saver<CTy,CTr>(s),
        ostream::position_saver<CTy,CTr>(s)
    {}

    template <typename CTy, typename CTr>
    inline
    position_saver<CTy,CTr>::~position_saver()
    {
      restore();
    }

    template <typename CTy, typename CTr>
    inline void
    position_saver<CTy,CTr>::restore()
    {
      ostream::position_saver<CTy,CTr>::restore();
      istream::position_saver<CTy,CTr>::restore();
    }
    
  } // namespace iostream {
    
} // namespace support {

#endif // #if !defined(UKACHULLDCS_08961_SUPPORT_IO_UTILS_INL)
