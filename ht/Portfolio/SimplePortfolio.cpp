//
// Created by Chuang Yao on 11/10/2021.
//

#include "ht/Portfolio/SimplePortfolio.hpp"
#include "ht/Event/OrderEvent.hpp"

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
    current_positions_.insert({symbol, 0});
  }
  all_positions_.insert({start_date_, current_positions_});
  all_holdings_.insert({start_date_, current_holdings_});
}

void SimplePortfolio::update_fill(FillEvent &event) {
  update_position_from_fill(event);
  update_holdings_from_fill(event);
}

void SimplePortfolio::update_signal(SignalEvent &event) {
  generate_simple_order(event);
}

void SimplePortfolio::update_time_index(MarketEvent &) {
  // get the latest data from DataHandler
  std::map<std::string, YahooData> bars;
  for (const auto &symbol : symbols_) {
    bars.insert({symbol, dh_.latest_data_[symbol].rbegin()->second});
  }

  // update positions
  std::map<std::string, double> pos;
  std::map<std::string, std::map<std::string, double>> dp;
  for (const auto &symbol : symbols_) {
    pos.insert({symbol, current_positions_[symbol]});
  }
  dp.insert({bars.rbegin()->second.date_, pos});
  all_positions_.insert(dp.begin(), dp.end());

  // update holdings
  SimpleHolding holding(symbols_, current_holdings_.cash_,
                        current_holdings_.commission_,
                        current_holdings_.total_);
  for (const auto &symbol : symbols_) {
    double market_value = current_positions_[symbol] *
                          dh_.latest_data_[symbol].rbegin()->second.adjClose_;
    holding.holdings_[symbol] = market_value;
    holding.total_ += market_value;
  }
  all_holdings_.insert({bars.rbegin()->second.date_, holding});
}

void SimplePortfolio::update_position_from_fill(FillEvent &event) {
  double direction;
  if (event.get_direction() == "LONG") {
    direction = 1;
  } else if (event.get_direction() == "SHORT") {
    direction = -1;
  } else {
    direction = 0;
  }

  current_positions_[event.get_symbol()] += event.get_quantity() * direction;
}

void SimplePortfolio::update_holdings_from_fill(FillEvent &event) {
  double direction;
  if (event.get_direction() == "LONG") {
    direction = 1;
  } else if (event.get_direction() == "SHORT") {
    direction = -1;
  } else {
    direction = 0;
  }

  double cost{dh_.latest_data_[event.get_symbol()].rbegin()->second.adjClose_};
  double fill_cost{direction * cost * event.get_quantity()};

  current_holdings_.holdings_[event.get_symbol()] += fill_cost;
  current_holdings_.commission_ += event.get_commission();
  current_holdings_.cash_ -= fill_cost + event.get_commission();
  current_holdings_.total_ -= fill_cost + event.get_commission();
}

void SimplePortfolio::generate_simple_order(SignalEvent &event) {
  int32_t mkt_quantity{static_cast<int32_t>(100 * event.get_strength())};
  int32_t cur_quantity{
      static_cast<int32_t>(current_positions_[event.get_symbol()])};

  if (event.get_direction() == "LONG" && cur_quantity == 0) {
    OrderEvent(q_, event.get_symbol(), "MKT", mkt_quantity, "LONG");
  }
  if (event.get_direction() == "SHORT" && cur_quantity == 0) {
    OrderEvent(q_, event.get_symbol(), "MKT", mkt_quantity, "SHORT");
  }

  if (event.get_direction() == "EXIT" && cur_quantity > 0) {
    OrderEvent(q_, event.get_symbol(), "MKT", abs(cur_quantity), "SHORT");
  }
  if (event.get_direction() == "EXIT" && cur_quantity < 0) {
    OrderEvent(q_, event.get_symbol(), "MKT", abs(cur_quantity), "LONG");
  }
}

} // namespace HackTest
