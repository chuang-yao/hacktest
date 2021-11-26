#ifndef HACKTEST_SIGNALEVENT_HPP
#define HACKTEST_SIGNALEVENT_HPP

#include "Event.hpp"

#include <string>

namespace HackTest {

class SignalEvent : public Event {
public:
  SignalEvent(EventQueue &, std::string, std::string);

private:
  std::string symbol_;
  std::string direction_; // LONG, SHORT, EXIT
};

} // namespace HackTest

#endif // HACKTEST_SIGNALEVENT_HPP
