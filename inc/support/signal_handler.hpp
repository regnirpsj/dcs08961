// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  support/signal_handler.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SUPPORT_SIGNAL_HANDLER_HPP)

#define UKACHULLDCS_08961_SUPPORT_SIGNAL_HANDLER_HPP

// includes, system


#include <boost/utility/mutexed_singleton.hpp> // boost::singleton<>
#include <csignal>                             // ::siginfo_t
#include <functional>                          // std::function<>

// includes, project

//#include <>

namespace support {
  
  // types, exported (class, enum, struct, union, typedef)

  class signal_handler : public boost::mutexed_singleton<signal_handler> {

    BOOST_SINGLETON_PLACEMENT_DECLARATION;

  public:

    typedef std::function<void (::siginfo_t*)> handler_function_type;

    ~signal_handler();

    handler_function_type handler(signed                /* signo   */);
    handler_function_type handler(signed                /* signo   */,
                                  handler_function_type /* handler */);

  private:

    template<class T, int DS, typename ST> friend class boost::mutexed_singleton;

    explicit signal_handler(boost::restricted);

  };
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace support {

#endif // #if !defined(UKACHULLDCS_08961_SUPPORT_SIGNAL_HANDLER_HPP)
