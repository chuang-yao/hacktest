//
// Created by Chuang on 10/6/2021.
//

#ifndef HACKTEST_FILLEVENT_H
#define HACKTEST_FILLEVENT_H

#include "ht/Event/Event.h"

#include <string>

namespace HackTest {

class FillEvent : public Event {
public:
  FillEvent(std::string, std::string, uint32_t, std::string, double);

private:
  std::string symbol_;
  std::string exchange_;
  uint32_t quantity_;
  std::string direction_;
  double costs_;
};

} // namespace HackTest

#endif // HACKTEST_FILLEVENT_H
