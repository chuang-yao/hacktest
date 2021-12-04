#ifndef HACKTEST_FILLEVENT_HPP
#define HACKTEST_FILLEVENT_HPP

#include "ht/Event/Event.hpp"

#include <string>

namespace HackTest {

class FillEvent : public Event {
public:
  FillEvent(EventQueue &, std::string, std::string, uint32_t, std::string,
            double, double);

  [[nodiscard]] double calculate_ib_commission() const;
  [[nodiscard]] const std::string &get_direction() const;
  [[nodiscard]] const std::string &get_symbol() const;
  [[nodiscard]] uint32_t get_quantity() const;
  [[nodiscard]] double get_commission() const;

private:
  std::string symbol_;    // symbol
  std::string exchange_;  // where was the order got executed
  uint32_t quantity_;     // exact quantities transacted
  std::string direction_; // LONG or SHORT
  double fill_cost;       // order value in USD
  double commission_;     // commission charged by real brokers, 0 if none
};

} // namespace HackTest

#endif // HACKTEST_FILLEVENT_HPP
