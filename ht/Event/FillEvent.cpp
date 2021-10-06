//
// Created by Chuang on 10/6/2021.
//

#include "FillEvent.h"

namespace HackTest {

FillEvent::FillEvent(std::string timeIndex, std::string symbol,
                     std::string exchange, uint32_t quantity,
                     std::string direction, double costs)
    : Event("FILL"), timeIndex_(std::move(timeIndex)),
      symbol_(std::move(symbol)), exchange_(std::move(exchange)),
      quantity_(quantity), direction_(std::move(direction)), costs_(costs) {}

} // namespace HackTest
