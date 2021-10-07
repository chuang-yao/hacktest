//
// Created by Chuang on 10/6/2021.
//

#include "SignalEvent.h"

namespace HackTest {

SignalEvent::SignalEvent(std::string symbol, std::string direction)
    : Event(EventType::Signal), symbol_(std::move(symbol)),
      direction_(std::move(direction)) {}

} // namespace HackTest
