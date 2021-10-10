#ifndef HACKTEST_EVENT_HPP
#define HACKTEST_EVENT_HPP

#include <chrono>

namespace HackTest {

class Event {
public:
  enum class Type { Fill, Market, Order, Signal };

  explicit Event(Type);

  void show_datetime();

private:
  Type type_;
  std::chrono::time_point<std::chrono::system_clock> datetime_;
};

} // namespace HackTest

#endif // HACKTEST_EVENT_HPP
