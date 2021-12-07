//
// Created by Chuang Yao on 11/25/21.
//

#include "ht/Strategy/SimpleStrategy.hpp"
#include "ht/Event/SignalEvent.hpp"
#include "ht/Portfolio/SimplePortfolio.hpp"

namespace HackTest {

SimpleStrategy::SimpleStrategy(EventQueue &q, HistoricalCsvHandler &dh,
                               SimplePortfolio &portfolio)
    : q_(q), dh_(dh), symbols_(dh_.symbols_), portfolio_(portfolio) {
  for (const auto &symbol : symbols_) {
    bought_.insert({symbol, false});
  }
}

void SimpleStrategy::calculate_signal(MarketEvent &me) {
  for (const auto &symbol : symbols_) {
    if (dh_.latest_data_[symbol].contains(portfolio_.get_start_date())) {
      add_to_queue<SignalEvent>(q_, symbol,
                                dh_.latest_data_[symbol].rbegin()->second.date_,
                                "LONG", bought_[symbol] ? 0 : 1);
      bought_[symbol] = true;
    }
  }
}

} // namespace HackTest
