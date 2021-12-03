#ifndef HACKTEST_SIGNALEVENT_HPP
#define HACKTEST_SIGNALEVENT_HPP

#include "Event.hpp"

#include <string>

namespace HackTest {

class SignalEvent : public Event {
public:
  SignalEvent(EventQueue &, std::string, std::string, std::string, double);

  [[nodiscard]] std::string get_symbol() const;
  [[nodiscard]] std::string get_direction() const;
  [[nodiscard]] double get_strength() const;

private:
  std::string symbol_;
  std::string datetime_;
  std::string direction_; // LONG, SHORT, EXIT
  double strength_;
};

} // namespace HackTest

#endif // HACKTEST_SIGNALEVENT_HPP
