#include "ht/Event/FillEvent.hpp"

namespace HackTest {

FillEvent::FillEvent(EventQueue &q, std::string symbol, std::string exchange,
                     uint32_t quantity, std::string direction, double costs,
                     double commission)
    : Event(Type::FIL, q), symbol_(std::move(symbol)),
      exchange_(std::move(exchange)), quantity_(quantity),
      direction_(std::move(direction)), fill_cost(costs),
      commission_(commission) {
  if (commission_ == -1) {
    commission_ = calculate_ib_commission();
  }
}

double FillEvent::calculate_ib_commission() const {
  double total_cost{1.3};
  if (quantity_ <= 500) {
    total_cost = std::max(1.3, 0.013 * quantity_);
  } else {
    total_cost = std::max(1.3, 0.008 * quantity_);
  }
  total_cost = std::min(total_cost, 0.5 / 100 * quantity_ * fill_cost);
  return total_cost;
}

const std::string &FillEvent::get_direction() const { return direction_; }

const std::string &FillEvent::get_symbol() const { return symbol_; }

uint32_t FillEvent::get_quantity() const { return quantity_; }

double FillEvent::get_commission() const { return commission_; }

} // namespace HackTest
