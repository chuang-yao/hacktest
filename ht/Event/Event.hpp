//
// Created by Chuang Yao on 11/04/2021.
//

#ifndef HACKTEST_EVENT_HPP
#define HACKTEST_EVENT_HPP

#include <chrono>
#include <iostream>
#include <queue>

namespace HackTest {

class EventQueue;

class Event {
  friend std::ostream &operator<<(std::ostream &, const Event &);

public:
  enum class Type { FIL, MKT, ORD, SIG };

  explicit Event(Type);
  Event(Type, EventQueue &);
  virtual ~Event() = default;

  void show_datetime() const;
  [[nodiscard]] Type get_type() const;

private:
  Type type_;
  std::chrono::time_point<std::chrono::system_clock> time_;
};

class EventQueue {
  friend class Event;

public:
  void show() const;
  [[nodiscard]] bool empty() const;
  [[nodiscard]] std::shared_ptr<Event> back() const;
  std::shared_ptr<Event> get_event();

private:
  std::queue<std::shared_ptr<Event>> queue_;
};

} // namespace HackTest

#endif // HACKTEST_EVENT_HPP
