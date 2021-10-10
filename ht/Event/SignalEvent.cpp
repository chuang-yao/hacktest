#include "SignalEvent.hpp"

namespace HackTest {

SignalEvent::SignalEvent(std::string symbol, std::string direction)
    : Event(Type::Signal), symbol_(std::move(symbol)),
      direction_(std::move(direction)) {}

} // namespace HackTest
