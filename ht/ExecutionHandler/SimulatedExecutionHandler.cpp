//
// Created by Chuang Yao on 11/25/21.
//

#include "ht/ExecutionHandler/SimulatedExecutionHandler.hpp"
#include "ht/Event/FillEvent.hpp"

namespace HackTest {

SimulatedExecutionHandler::SimulatedExecutionHandler(
    EventQueue &queue, HistoricalCsvHandler &handler)
    : q_(queue), dh_(handler) {}

void SimulatedExecutionHandler::execute_order(OrderEvent &event) {
  add_to_queue<FillEvent>(
      q_, event.get_symbol(), "NASDAQ", event.get_quantity(),
      event.get_direction(),
      dh_.latest_data_[event.get_symbol()].rbegin()->second.adjClose_, -1);
}

} // namespace HackTest
