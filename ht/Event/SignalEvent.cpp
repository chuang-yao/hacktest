#include "ht/Event/SignalEvent.hpp"

namespace HackTest {

SignalEvent::SignalEvent(EventQueue &q, std::string symbol,
                         std::string direction)
    : Event(Type::SIG, q), symbol_(std::move(symbol)),
      direction_(std::move(direction)) {}

} // namespace HackTest
