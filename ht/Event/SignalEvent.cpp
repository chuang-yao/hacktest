//
// Created by Chuang on 10/6/2021.
//

#include "SignalEvent.hpp"

namespace HackTest {

SignalEvent::SignalEvent(std::string symbol, std::string direction)
    : Event(Type::Signal), symbol_(std::move(symbol)),
      direction_(std::move(direction)) {}

} // namespace HackTest
