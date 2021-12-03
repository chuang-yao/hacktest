#include "ht/Event/SignalEvent.hpp"

#include <utility>

namespace HackTest {

SignalEvent::SignalEvent(EventQueue &q, std::string symbol,
                         std::string datetime, std::string direction,
                         double strength)
    : Event(Type::SIG, q), symbol_(std::move(symbol)),
      datetime_(std::move(datetime)), direction_(std::move(direction)),
      strength_(strength) {}

std::string SignalEvent::get_symbol() const { return symbol_; }

std::string SignalEvent::get_direction() const { return direction_; }

double SignalEvent::get_strength() const { return strength_; }

} // namespace HackTest
