//
// Created by Chuang Yao on 11/24/21.
//

#ifndef HACKTEST_STRATEGY_HPP
#define HACKTEST_STRATEGY_HPP

#include "ht/Event/MarketEvent.hpp"

namespace HackTest {

class Strategy {
public:
  virtual void calculate_signal(MarketEvent) = 0;
};

} // namespace HackTest

#endif // HACKTEST_STRATEGY_HPP
