// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  support/application.hpp                                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SUPPORT_APPLICATION_HPP)

#define UKACHULLDCS_08961_SUPPORT_APPLICATION_HPP

// includes, system

#include <boost/noncopyable.hpp>     // boost::noncopyable
#include <boost/program_options.hpp> // boost::program_options::options_description,
                                     // boost::program_options::positional_options_description,
                                     // boost::program_options::variables_map

// includes, project

#include <support/printable.hpp>

namespace support {
  
  // types, exported (class, enum, struct, union, typedef)

  class application : private boost::noncopyable,
                      public support::printable {

  public:

    /**
     * \return application_
     */
    static application* instance();

    virtual void   config(int /* argc */, char* /* argv */[]);
    virtual void   init  ();
    virtual signed run   () =0;
    virtual void   fini  ();

    virtual void print_on(std::ostream&) const;
    
  protected:
    
    boost::program_options::options_description            cmdline_options_;
    boost::program_options::positional_options_description cmdline_positionals_;
    unsigned                                               verbose_level_;
    
    explicit application();
    virtual ~application() =0;

    virtual void cmdline_eval   (boost::program_options::variables_map&);
    virtual void cmdline_process(int /* argc */, char* /* argv */[]);    
    
  private:

    static application* application_; // dflt: nullptr
    
  };
  
  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace support {

#endif // #if !defined(UKACHULLDCS_08961_SUPPORT_APPLICATION_HPP)
