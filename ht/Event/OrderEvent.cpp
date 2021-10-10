#include "OrderEvent.hpp"

namespace HackTest {

OrderEvent::OrderEvent(std::string symbol, std::string order, uint32_t quantity,
                       std::string direction)
    : Event(Type::Order), symbol_(std::move(symbol)), order_(std::move(order)),
      quantity_(quantity), direction_(std::move(direction)) {}

} // namespace HackTest
