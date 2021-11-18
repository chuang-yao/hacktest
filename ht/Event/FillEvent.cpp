#include "ht/Event/FillEvent.hpp"

namespace HackTest {

FillEvent::FillEvent(EventQueue &q, std::string symbol, std::string exchange,
                     uint32_t quantity, std::string direction, double costs)
    : Event(Type::FIL, q), symbol_(std::move(symbol)),
      exchange_(std::move(exchange)), quantity_(quantity),
      direction_(std::move(direction)), costs_(costs) {}

} // namespace HackTest
