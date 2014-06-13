// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/connection/manager.cpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "field/connection/manager.hpp"

// includes, system

#include <sstream> // std::ostringstream

// includes, project

#include <field/base.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal
  
} // namespace {

BOOST_SINGLETON_PLACEMENT(field::connection::manager);

namespace field {
  
  namespace connection {
  
    // variables, exported
  
    // functions, exported

    bool
    manager::connect(::field::base* s, ::field::base* d)
    {
      TRACE("field::connection::manager::connect");

      bool result(false);

      if (s != d) {
        typedef connection_map_type::value_type value_type;

        value_type const sd(s, d, s->name() + "->" + d->name());
        value_type const ds(d, s, d->name() + "->" + s->name());
        auto const       found_sd(connection_map_.find(sd));
        auto const       found_ds(connection_map_.find(ds));
        
        if ((connection_map_.end() == found_sd) && (connection_map_.end() == found_ds)) {
          result = connection_map_.insert(sd).second;
        }
#if 1
        else {
          std::cout << support::trace::prefix() << "field::connection::manager::connect: "
                    << '('
                    << sd.get<src>()->name()
                    << ':'
                    << sd.get<dst>()->name()
                    << ':'
                    << sd.get<info>()
                    << ')';

          if (connection_map_.end() != found_sd) {
            std::cout << " =?= "
                      << '('
                      << (*found_sd).get<src>()->name()
                      << ':'
                      << (*found_sd).get<dst>()->name()
                      << ':'
                      << (*found_sd).get<info>()
                      << ')';
          }

          if (connection_map_.end() != found_ds) {
            std::cout << " =?= "
                      << '('
                      << (*found_ds).get<src>()->name()
                      << ':'
                      << (*found_ds).get<dst>()->name()
                      << ':'
                      << (*found_ds).get<info>()
                      << ')';
              }
          
          std::cout << '\n';
        }
#endif
      }
      
      return result;
    }
    
    bool
    manager::disconnect(::field::base* f)
    {
      TRACE("field::connection::manager::disconnect");

      bool       result(false);
      auto const found_src(connection_map_.by<src>().find(f));

      if (connection_map_.by<src>().end() != found_src) {
        connection_map_.by<src>().erase(found_src);

        result |= true;
      }

      auto const found_dst(connection_map_.by<dst>().find(f));

      if (connection_map_.by<dst>().end() != found_dst) {
        connection_map_.by<dst>().erase(found_dst);

        result |= true;
      }

      return result;
    }
    
    /* virtual */ void
    manager::print_on(std::ostream& os) const
    {
      TRACE_NEVER("field::connection::manager::print_on");
      
      os << "[\n"
         << std::string(2, '-') << " sources " << std::string(59, '-') << '\n';
      
      for (auto const f : connection_map_) {
        std::ostringstream ostr;
        
        print_helper<src, dst>(f.get<src>(), ostr);

#if 1
        ostr << std::string(std::max(static_cast<unsigned long>(40), ostr.str().length()+1) -
                            ostr.str().length(), ' ');
    
        print_helper<dst, src>(f.get<src>(), ostr);
#endif
        
        os << ostr.str() << '\n';
      }

      os << std::string(2, '-') << " destinations " << std::string(54, '-') << '\n';
      
      for (auto const f : connection_map_) {
        std::ostringstream ostr;
        
        print_helper<dst, src>(f.get<dst>(), ostr);

#if 1
        ostr << std::string(std::max(static_cast<unsigned long>(40), ostr.str().length()+1) -
                            ostr.str().length(), ' ');
    
        print_helper<src, dst>(f.get<dst>(), ostr);
#endif
        
        os << ostr.str() << '\n';
      }
      
      os << ']';
    }
    
    /* explicit */
    manager::manager(boost::restricted)
      : support::printable               (),
        boost::mutexed_singleton<manager>(),
        connection_map_                  ()
    {
      TRACE("field::connection::manager::manager");
    }

    template <typename L, typename R>
    void
    manager::print_helper(::field::base* a, std::ostream& os) const
    {
      TRACE_NEVER("field::connection::manager::print_helper");
      
      auto current(connection_map_.by<L>().find(a));
    
      os << a->name() << ' ' << ((typeid(L) == typeid(src)) ? "->" : "<-") << " { ";
    
      while (connection_map_.by<L>().end() != current) {
        if (current->template get<L>() == a) {
          os << '(' << (current->template get<R>())->name()
               << ":'"
               << current->template get<info>() << "'),";
        }
      
        ++current;
      }
    
      os << "\b }";
    }
    
  } // namespace connection {
  
} // namespace field {