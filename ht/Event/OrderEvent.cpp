#include "ht/Event/OrderEvent.hpp"

namespace HackTest {

OrderEvent::OrderEvent(EventQueue &q, std::string symbol, std::string order,
                       uint32_t quantity, std::string direction)
    : Event(Type::Order, q), symbol_(std::move(symbol)),
      order_(std::move(order)), quantity_(quantity),
      direction_(std::move(direction)) {}

} // namespace HackTest
