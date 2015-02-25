// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  event/event/event.hpp                                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_EVENT_EVENT_EVENT_HPP)

#define UKACHULLDCS_08961_EVENT_EVENT_EVENT_HPP

// includes, system

#include <condition_variable> // std::condition_variable
#include <queue>              // std::queue<>
#include <unordered_set>      // std::unordered_set<>

// includes, project

#include <event/event/base.hpp>
#include <support/thread.hpp>

namespace event {
  
  // types, exported (class, enum, struct, union, typedef)

  template <typename T>
  class event : public base {

  public:

    class handler : virtual public event::event<T>::handler::template base {

    public:

      virtual ~handler();

      virtual void handle_event(T const&);

    protected:

      handler(bool = false);

      void mark_handled(T const&);
      bool async_handled(T const&) const;

    private:

      bool const monitor_;

    };

    explicit event();
    virtual ~event();

    virtual void      notify      ();
    virtual void      async_notify();
    virtual event<T>* clone       () const;

    bool unhandled() const;

  protected:

    typedef std::unordered_set<handler*>            handler_list_type;
    typedef support::simple_lock                    handler_lock_type;
    typedef std::thread                             handler_thread_type;

    typedef std::queue<event<T>* >                  event_queue_type;
    typedef std::mutex                              event_queue_lock_type;
    typedef std::unique_lock<event_queue_lock_type> event_queue_lock_guard_type;
    typedef std::condition_variable                 event_queue_cond_type;

    static handler_list_type*     handler_list;
    static handler_lock_type*     handler_lock;
    static handler_list_type*     monitor_list;
    static handler_lock_type*     monitor_lock;
    static handler_thread_type*   handler_thread;
    static std::once_flag         handler_thread_once_flag;
    static event_queue_type*      event_queue;
    static event_queue_lock_type* event_queue_lock;
    static event_queue_cond_type* event_queue_cond;
    static bool                   events_available;

  private:

    friend class handler;

    struct thread_initializer_t {

    public:

      void operator()() const;

    };

    static void attach(handler*, bool);
    static void detach(handler*, bool);
    static void notify_handlers(event<T> const&);
    static void handler_thread_function();
    static void dump_stats(std::string const&);

    mutable bool unhandled_;
    mutable bool async_;
    
  };

  // variables, exported (extern)

  // functions, inlined (inline)
  
  // functions, exported (extern)
  
} // namespace event {

#include <event/event/event.inl>

#define DEF_EVENT_HANDLER_SPECIALIZATION(X)                             \
  template <> events::event<X>::handler_list_type*     events::event<X>::handler_list =           \
                   new events::event<X>::handler_list_type;             \
  template <> events::event<X>::handler_lock_type*     events::event<X>::handler_lock =           \
                   new events::event<X>::handler_lock_type;             \
  template <> events::event<X>::handler_list_type*     events::event<X>::monitor_list =           \
                   new events::event<X>::handler_list_type;             \
  template <> events::event<X>::handler_lock_type*     events::event<X>::monitor_lock =           \
                   new events::event<X>::handler_lock_type;             \
  template <> events::event<X>::handler_thread_type*   events::event<X>::handler_thread(0);       \
  template <> std::once_flag                           events::event<X>::handler_thread_once_flag \
                                                         = ONCE_FLAG_INIT;                         \
  template <> events::event<X>::event_queue_type*      events::event<X>::event_queue =            \
                   new events::event<X>::event_queue_type;              \
  template <> events::event<X>::event_queue_lock_type* events::event<X>::event_queue_lock =       \
                   new events::event<X>::event_queue_lock_type;         \
  template <> events::event<X>::event_queue_cond_type* events::event<X>::event_queue_cond =       \
                   new events::event<X>::event_queue_cond_type;         \
  template <> bool                                     events::event<X>::events_available(false)
  
#endif // #if !defined(UKACHULLDCS_08961_EVENT_EVENT_EVENT_HPP)
