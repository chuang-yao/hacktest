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

  void show_datetime() const;

private:
  Type type_;
  std::chrono::time_point<std::chrono::system_clock> time_;
};

class EventQueue {
  friend class Event;

public:
  void show();

private:
  std::queue<Event> queue_;
};

} // namespace HackTest

#endif // HACKTEST_EVENT_HPP
