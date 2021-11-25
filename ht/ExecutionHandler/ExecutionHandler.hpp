//
// Created by Chuang Yao on 11/10/2021.
//

#ifndef HACKTEST_EXECUTIONHANDLER_HPP
#define HACKTEST_EXECUTIONHANDLER_HPP

#include "ht/Event/OrderEvent.hpp"

namespace HackTest {

class ExecutionHandler {
public:
  virtual void execute_order(OrderEvent) = 0;
};

} // namespace HackTest

#endif // HACKTEST_EXECUTIONHANDLER_HPP
