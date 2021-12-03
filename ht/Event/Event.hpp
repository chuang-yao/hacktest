//
// Created by Chuang Yao on 11/04/2021.
//

#ifndef HACKTEST_EVENT_HPP
#define HACKTEST_EVENT_HPP

#include <chrono>
#include <iostream>
#include <memory>
#include <queue>

namespace HackTest {

class EventQueue;

class Event {
  friend std::ostream &operator<<(std::ostream &, const Event &);

public:
  enum class Type { FIL, MKT, ORD, SIG };

  explicit Event(Type);
  virtual ~Event() = default;

  void show_datetime() const;
  [[nodiscard]] Type get_type() const;

private:
  Type type_;
  std::chrono::time_point<std::chrono::system_clock> time_;
};

class EventQueue {
  friend class Event;
  friend class FillEvent;
  friend class MarketEvent;
  friend class OrderEvent;
  friend class SignalEvent;

  template <typename D, typename... Args>
  friend void add_event_to_queue(EventQueue &q, Args... args);

public:
  void show() const;
  [[nodiscard]] bool is_empty() const;
  void push(const std::shared_ptr<Event> &);
  std::shared_ptr<Event> get_event_handle();

private:
  std::queue<std::shared_ptr<Event>> queue_;
};

template <typename D, typename... Args>
void add_event_to_queue(EventQueue &q, Args... args) {
  std::shared_ptr<Event> ptr = std::make_shared<D>(q, args...);
  q.push(ptr);
}

} // namespace HackTest

#endif // HACKTEST_EVENT_HPP
