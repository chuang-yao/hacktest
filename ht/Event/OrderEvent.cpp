#include "ht/Event/OrderEvent.hpp"

#include <iostream>

namespace HackTest {

OrderEvent::OrderEvent(EventQueue &q, std::string symbol, std::string order,
                       uint32_t quantity, std::string direction)
    : Event(Type::ORD), symbol_(std::move(symbol)), order_(std::move(order)),
      quantity_(quantity), direction_(std::move(direction)) {}

void OrderEvent::print_order() const {
  std::cout << symbol_ << '\t' << order_ << '\t' << quantity_ << '\t'
            << direction_ << '\n';
}
} // namespace HackTest
