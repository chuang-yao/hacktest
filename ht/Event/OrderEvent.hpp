#ifndef HACKTEST_ORDEREVENT_HPP
#define HACKTEST_ORDEREVENT_HPP

#include "ht/Event/Event.hpp"

#include <string>

namespace HackTest {

class OrderEvent : public Event {
public:
  OrderEvent(std::string, std::string, uint32_t, std::string);

private:
  std::string symbol_;    // order symbol, "AAPL"
  std::string order_;     // order type, "MKT" or "LMT"
  uint32_t quantity_;     // order quantity
  std::string direction_; // order direction, "LONG" or "SHORT"
};

} // namespace HackTest

#endif // HACKTEST_ORDEREVENT_HPP
