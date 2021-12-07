//
// Created by Chuang Yao on 11/10/2021.
//

#ifndef HACKTEST_SIMPLEPORTFOLIO_HPP
#define HACKTEST_SIMPLEPORTFOLIO_HPP

#include "ht/DataHandler/HistoricalCsvHandler.hpp"
#include "ht/Portfolio/Portfolio.hpp"

namespace HackTest {

class SimpleHolding {
  friend class SimplePortfolio;

public:
  SimpleHolding(const std::vector<std::string> &, double, double, double);

private:
  std::map<std::string, double> holdings_;
  double cash_;
  double commission_;
  double total_;
};

class SimplePortfolio : public Portfolio {
public:
  SimplePortfolio(EventQueue &, HistoricalCsvHandler &, std::string, double);

  void update_signal(SignalEvent &) override;
  void update_fill(FillEvent &) override;
  void update_time_index(MarketEvent &) override;
  void update_position_from_fill(FillEvent &);
  void update_holdings_from_fill(FillEvent &);
  void generate_simple_order(SignalEvent &);
  void calculate_returns_();

  [[nodiscard]] const std::string &get_start_date() const;

private:
  EventQueue &q_;
  HistoricalCsvHandler &dh_;
  std::vector<std::string> symbols_;

  std::string start_date_;
  double initial_capital_;

  std::map<std::string, int64_t> current_positions_;
  std::map<std::string, std::map<std::string, int64_t>> all_positions_;

  SimpleHolding current_holdings_;
  std::map<std::string, SimpleHolding> all_holdings_;

  std::map<std::string, double> returns_;
};

} // namespace HackTest

#endif // HACKTEST_SIMPLEPORTFOLIO_HPP
