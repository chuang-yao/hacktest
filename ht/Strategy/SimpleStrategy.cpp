//
// Created by Chuang Yao on 11/25/21.
//

#include "ht/Strategy/SimpleStrategy.hpp"
#include "ht/Event/SignalEvent.hpp"

namespace HackTest {

SimpleStrategy::SimpleStrategy(EventQueue &q, HistoricalCsvHandler &dh)
    : q_(q), dh_(dh), symbols_(dh_.symbols_) {
  for (const auto &symbol : symbols_) {
    bought_.insert({symbol, false});
  }
}

void SimpleStrategy::calculate_signal(MarketEvent &me) {
  for (const auto &symbol : symbols_) {
    if (!dh_.latest_data_.empty()) {
      SignalEvent se(q_, symbol,
                     dh_.latest_data_[symbol].rbegin()->second.date_, "LONG",
                     1);
      bought_[symbol] = true;
    }
  }
}

} // namespace HackTest
