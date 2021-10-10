#ifndef HACKTEST_MARKETEVENT_HPP
#define HACKTEST_MARKETEVENT_HPP

#include "Event.hpp"

#include <string>

namespace HackTest {

class MarketEvent : public Event {
public:
  explicit MarketEvent(EventQueue &);
};

} // namespace HackTest

#endif // HACKTEST_MARKETEVENT_HPP
