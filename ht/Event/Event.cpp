//
// Created by Chuang on 10/6/2021.
//

#include "Event.hpp"

namespace HackTest {

Event::Event(EventType type)
    : type_(type), datetime_(std::chrono::system_clock::now()) {}

} // namespace HackTest
