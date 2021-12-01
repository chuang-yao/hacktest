//
// Created by Chuang Yao on 11/10/2021.
//

#ifndef HACKTEST_PORTFOLIO_HPP
#define HACKTEST_PORTFOLIO_HPP

#include "ht/Event/FillEvent.hpp"
#include "ht/Event/MarketEvent.hpp"
#include "ht/Event/SignalEvent.hpp"

namespace HackTest {

class Portfolio {
public:
  virtual ~Portfolio() = default;
  virtual void update_signal(SignalEvent &) = 0;
  virtual void update_fill(FillEvent &) = 0;
  virtual void update_time_index(MarketEvent &) = 0;
};

} // namespace HackTest

#endif // HACKTEST_PORTFOLIO_HPP
