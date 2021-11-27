//
// Created by Chuang Yao on 11/10/2021.
//

#include "ht/Portfolio/SimplePortfolio.hpp"

#include "ht/DataHandler/HistoricalCsvHandler.hpp"
#include <utility>

namespace HackTest {

SimplePortfolio::SimplePortfolio(EventQueue &q, HistoricalCsvHandler &dh,
                                 std::string date, double capital)
    : q_(q), dh_(dh), symbols_(dh_.symbols_), start_date_(std::move(date)),
      initial_capital_(capital) {}

void SimplePortfolio::update_fill(FillEvent &) {}

void SimplePortfolio::update_signal(SignalEvent &) {}

void SimplePortfolio::update_time_index(MarketEvent &) {}

} // namespace HackTest
