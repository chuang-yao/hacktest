//
// Created by Chuang Yao on 11/25/21.
//

#ifndef HACKTEST_SIMULATEDEXECUTIONHANDLER_HPP
#define HACKTEST_SIMULATEDEXECUTIONHANDLER_HPP

#include "ht/DataHandler/HistoricalCsvHandler.hpp"
#include "ht/ExecutionHandler/ExecutionHandler.hpp"

namespace HackTest {

class SimulatedExecutionHandler : public ExecutionHandler {
public:
  SimulatedExecutionHandler(EventQueue &, HistoricalCsvHandler &);
  void execute_order(OrderEvent &) override;

private:
  EventQueue &q_;
  HistoricalCsvHandler &dh_;
};

} // namespace HackTest

#endif // HACKTEST_SIMULATEDEXECUTIONHANDLER_HPP
