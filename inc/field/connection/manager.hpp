// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/connection/manager.hpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_FIELD_CONNECTION_MANAGER_HPP)

#define UKACHULLDCS_08961_FIELD_CONNECTION_MANAGER_HPP

// includes, system

#include <boost/bimap/bimap.hpp>                 // boost::bimaps::*
#include <boost/bimap/unordered_multiset_of.hpp> // boost::bimaps::unordered_multiset_of<>
#include <boost/bimap/unordered_set_of.hpp>      // boost::bimaps::unordered_set_of<>
#include <boost/utility/mutexed_singleton.hpp>   // boost::mutexed_singleton<>

// includes, project

#include <support/printable.hpp>

namespace field {

  class base;
  
  namespace connection {

    class base;
    
    // types, exported (class, enum, struct, union, typedef)

    class manager : public support::printable,
                    public boost::mutexed_singleton<manager> {

      BOOST_SINGLETON_PLACEMENT_DECLARATION;
      
    public:

      bool connect   (::field::base* /* src */, ::field::base* /* dst */);
      bool disconnect(::field::base* /* src/dst */);
      
      virtual void print_on(std::ostream&) const;
      
    private:

      template <class T, int DS, typename ST> friend class boost::mutexed_singleton;
      
      struct dst  {};
      struct src  {};
      struct info {};
      
      typedef boost::bimaps::unordered_multiset_of<boost::bimaps::tagged<::field::base*, src>>
        connection_src_type;
      typedef boost::bimaps::unordered_multiset_of<boost::bimaps::tagged<::field::base*, dst>>
        connection_dst_type;
      typedef boost::bimaps::with_info<boost::bimaps::tagged<std::string, info>>
        connection_info_type;
      typedef boost::bimaps::unordered_multiset_of_relation<> connection_rel_type;
      typedef boost::bimaps::bimap<connection_src_type,
                                   connection_dst_type,
                                   connection_rel_type,
                                   connection_info_type>
        connection_map_type;

      connection_map_type connection_map_;
      
      explicit manager(boost::restricted);

      template <typename, typename>
      void print_helper(::field::base*, std::ostream&) const;
      
    };
    
    // variables, exported (extern)

    // functions, inlined (inline)
  
    // functions, exported (extern)

  } // namespace connection {
  
} // namespace field {

#endif // #if !defined(UKACHULLDCS_08961_FIELD_CONNECTION_MANAGER_HPP)
