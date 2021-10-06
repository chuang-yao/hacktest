//
// Created by Chuang on 10/6/2021.
//

#include "SignalEvent.h"

namespace HackTest {

SignalEvent::SignalEvent(std::string symbol, std::string datetime,
                         std::string direction)
    : Event("SIGNAL"), symbol_(std::move(symbol)),
      datetime_(std::move(datetime)), direction_(std::move(direction)) {}

} // namespace HackTest
