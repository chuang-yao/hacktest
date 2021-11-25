//
// Created by Chuang Yao on 11/25/21.
//

#ifndef HACKTEST_SIMPLESTRATEGY_HPP
#define HACKTEST_SIMPLESTRATEGY_HPP

#include "ht/Strategy/Strategy.hpp"

namespace HackTest {

class SimpleStrategy : public Strategy {
public:
  void calculate_signal(MarketEvent) override;
};

} // namespace HackTest

#endif // HACKTEST_SIMPLESTRATEGY_HPP
