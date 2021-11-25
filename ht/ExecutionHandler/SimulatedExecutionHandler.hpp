//
// Created by Chuang Yao on 11/25/21.
//

#ifndef HACKTEST_SIMULATEDEXECUTIONHANDLER_HPP
#define HACKTEST_SIMULATEDEXECUTIONHANDLER_HPP

#include "ht/ExecutionHandler/ExecutionHandler.hpp"

namespace HackTest {

class SimulatedExecutionHandler : public ExecutionHandler {
public:
  void execute_order(OrderEvent) override;
};

} // namespace HackTest

#endif // HACKTEST_SIMULATEDEXECUTIONHANDLER_HPP
