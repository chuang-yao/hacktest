//
// Created by Chuang Yao on 11/10/2021.
//

#ifndef HACKTEST_SIMPLEPORTFOLIO_HPP
#define HACKTEST_SIMPLEPORTFOLIO_HPP

#include "ht/DataHandler/HistoricalCsvHandler.hpp"
#include "ht/Portfolio/Portfolio.hpp"

namespace HackTest {

class SimplePortfolio : public Portfolio {
public:
  SimplePortfolio(EventQueue &, HistoricalCsvHandler &, std::string, double);

  void update_signal(SignalEvent &) override;
  void update_fill(FillEvent &) override;
  void update_time_index(MarketEvent &) override;

private:
  EventQueue q_;
  HistoricalCsvHandler dh_;
  std::vector<std::string> symbols_;

  std::string start_date_;
  double initial_capital_;

  std::map<std::string, double> current_positions_;
  std::map<std::string, std::map<std::string, double>> all_positions_;
};

} // namespace HackTest

#endif // HACKTEST_SIMPLEPORTFOLIO_HPP
