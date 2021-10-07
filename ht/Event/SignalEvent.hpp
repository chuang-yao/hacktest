//
// Created by Chuang on 10/6/2021.
//

#ifndef HACKTEST_SIGNALEVENT_HPP
#define HACKTEST_SIGNALEVENT_HPP

#include "Event.hpp"

#include <string>

namespace HackTest {

class SignalEvent : public Event {
public:
  SignalEvent(std::string, std::string);

private:
  std::string symbol_;
  std::string direction_;
};

} // namespace HackTest

#endif // HACKTEST_SIGNALEVENT_HPP
