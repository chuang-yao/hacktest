#include "Event.hpp"

#include <iostream>

namespace HackTest {

Event::Event(Type type)
    : type_(type), datetime_(std::chrono::system_clock::now()) {}

void Event::show_datetime() {
  std::time_t t = std::chrono::system_clock::to_time_t(datetime_);
  std::cout << std::ctime(&t);
}

} // namespace HackTest
