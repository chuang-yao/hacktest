#include "FillEvent.hpp"

namespace HackTest {

FillEvent::FillEvent(std::string symbol, std::string exchange,
                     uint32_t quantity, std::string direction, double costs)
    : Event(Type::Fill), symbol_(std::move(symbol)),
      exchange_(std::move(exchange)), quantity_(quantity),
      direction_(std::move(direction)), costs_(costs) {}

} // namespace HackTest
