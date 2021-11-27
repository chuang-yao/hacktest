//
// Created by Chuang Yao on 11/25/21.
//

#ifndef HACKTEST_SIMPLESTRATEGY_HPP
#define HACKTEST_SIMPLESTRATEGY_HPP

#include "ht/DataHandler/HistoricalCsvHandler.hpp"
#include "ht/Event/Event.hpp"
#include "ht/Strategy/Strategy.hpp"

namespace HackTest {

class SimpleStrategy : public Strategy {
public:
  SimpleStrategy(EventQueue &, HistoricalCsvHandler &);
  void calculate_signal(MarketEvent &) override;

private:
  EventQueue &q_;
  HistoricalCsvHandler &dh_;
  std::vector<std::string> symbols_;
  std::map<std::string, bool> bought_;
};

} // namespace HackTest

#endif // HACKTEST_SIMPLESTRATEGY_HPP
