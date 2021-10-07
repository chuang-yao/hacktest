//
// Created by Chuang on 10/6/2021.
//

#ifndef HACKTEST_EVENT_HPP
#define HACKTEST_EVENT_HPP

#include <chrono>

namespace HackTest {

enum class EventType { Fill, Market, Order, Signal };

class Event {
public:
  explicit Event(EventType);

private:
  EventType type_;
  std::chrono::time_point<std::chrono::system_clock> datetime_;
};

} // namespace HackTest

#endif // HACKTEST_EVENT_HPP
