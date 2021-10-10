#ifndef HACKTEST_FILLEVENT_HPP
#define HACKTEST_FILLEVENT_HPP

#include "ht/Event/Event.hpp"

#include <string>

namespace HackTest {

class FillEvent : public Event {
public:
  FillEvent(EventQueue &, std::string, std::string, uint32_t, std::string,
            double);

private:
  std::string symbol_;    // symbol
  std::string exchange_;  // where was the order got executed
  uint32_t quantity_;     // exact quantities transacted
  std::string direction_; // LONG or SHORT
  double costs_;          // transaction costs
};

} // namespace HackTest

#endif // HACKTEST_FILLEVENT_HPP
