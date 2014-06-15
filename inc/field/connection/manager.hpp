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
#include <boost/utility/mutexed_singleton.hpp>   // boost::mutexed_singleton<>

// includes, project

#include <field/connection/update.hpp>
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

      typedef std::function<void ()> update_function_type;
      
      bool connect   (::field::base* const /* src */, ::field::base* const /* dst */,
                      update_function_type);
      bool disconnect(::field::base* const /* src/dst */);
      bool update    (::field::base* const /* src */);
      
      std::string status() const;
      
      virtual void print_on(std::ostream&) const;
      
    private:

      template <class, int, typename> friend class boost::mutexed_singleton;
      
      struct dst {};
      struct src {};
      struct upd {};
      
      typedef boost::bimaps::unordered_multiset_of<boost::bimaps::tagged<::field::base*, src>>
        connection_src_type;
      typedef boost::bimaps::unordered_multiset_of<boost::bimaps::tagged<::field::base*, dst>>
        connection_dst_type;
      typedef boost::bimaps::with_info<boost::bimaps::tagged<update_function_type, upd>>
        connection_upd_type;
      typedef boost::bimaps::unordered_multiset_of_relation<> connection_rel_type;
      typedef boost::bimaps::bimap<connection_src_type,
                                   connection_dst_type,
                                   connection_rel_type,
                                   connection_upd_type>
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

  // functions, inlined (inline)

  template <typename T1, typename T2 = T1>
  bool connect   (T1* const /* src */, T2* const /* dst */,
                  std::function<void (T1* const, T2* const)> /* upd */ =
                  connection::update::assign<T1,T2>);

  template <typename T>
  bool disconnect(T* const /* src/dst */);
  
} // namespace field {

#include <field/connection/manager.inl>

#endif // #if !defined(UKACHULLDCS_08961_FIELD_CONNECTION_MANAGER_HPP)
