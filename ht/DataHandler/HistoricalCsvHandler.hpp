//
// Created by Chuang Yao on 10/14/2021.
//

#ifndef HACKTEST_HISTORICALCSVHANDLER_HPP
#define HACKTEST_HISTORICALCSVHANDLER_HPP

#include <filesystem>
#include <map>
#include <string>

#include "ht/DataHandler/Data.hpp"
#include "ht/DataHandler/DataHandler.hpp"
#include "ht/Event/Event.hpp"

namespace HackTest {

class YahooData : public Data {
  friend class HistoricalCsvHandler;
  friend class SimpleStrategy;
  friend class SimplePortfolio;
  friend class SimulatedExecutionHandler;

public:
  YahooData(std::string date, double open, double high, double low,
            double close, double adjClose, unsigned long long volume);

private:
  std::string date_;
  double open_;
  double high_;
  double low_;
  double close_;
  double adj_close_;
  unsigned long long volume_;
};

class HistoricalCsvHandler : public DataHandler {
  friend class SimpleStrategy;
  friend class SimplePortfolio;
  friend class SimulatedExecutionHandler;

public:
  HistoricalCsvHandler(EventQueue &, std::filesystem::path,
                       std::vector<std::string>);

  void get_latest_bars(std::string, size_t) override;
  void update_bars() override;
  void show_data_on_date(const std::string &symbol, const std::string &date);
  [[nodiscard]] bool continue_test() const;

private:
  EventQueue &q_;                    // reference to the current event queue
  std::filesystem::path path_;       // path to the directory of CSV files
  std::vector<std::string> symbols_; // a list of symbols to look for CSV files
  std::map<std::string, std::map<std::string, YahooData>> data_;
  std::map<std::string, std::map<std::string, YahooData>> latest_data_;
  bool continue_{true}; // whether to continue the backtest

  void read_csv_files_();
};

} // namespace HackTest

#endif // HACKTEST_HISTORICALCSVHANDLER_HPP
