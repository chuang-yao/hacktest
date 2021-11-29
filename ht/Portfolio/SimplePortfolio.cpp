//
// Created by Chuang Yao on 11/10/2021.
//

#include "ht/Portfolio/SimplePortfolio.hpp"

namespace HackTest {

SimpleHolding::SimpleHolding(const std::vector<std::string> &symbols,
                             double cash, double commission, double total)
    : cash_(cash), commission_(commission), total_(total) {
  for (const auto &symbol : symbols) {
    holdings_.insert({symbol, 0.0});
  }
}

SimplePortfolio::SimplePortfolio(EventQueue &q, HistoricalCsvHandler &dh,
                                 std::string date, double capital)
    : q_(q), dh_(dh), symbols_(dh.symbols_), start_date_(std::move(date)),
      initial_capital_(capital),
      current_holdings_(SimpleHolding(dh_.symbols_, capital, 0.0, capital)) {
  for (const auto &symbol : symbols_) {
    current_positions_.insert({symbol, 0.0});
  }
  all_positions_.insert({start_date_, current_positions_});
  all_holdings_.insert({start_date_, current_holdings_});
}

void SimplePortfolio::update_fill(FillEvent &) {}

void SimplePortfolio::update_signal(SignalEvent &) {}

void SimplePortfolio::update_time_index(MarketEvent &) {}

} // namespace HackTest
