//
// Created by Chuang on 10/6/2021.
//

#ifndef HACKTEST_EVENT_H
#define HACKTEST_EVENT_H

#include <string>

namespace HackTest {

enum class EventType { Fill, Market, Order, Signal };

class Event {
public:
  explicit Event(EventType);

private:
  EventType type_;
};

} // namespace HackTest

#endif // HACKTEST_EVENT_H
