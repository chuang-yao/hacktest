//
// Created by Chuang Yao on 12/9/21.
//

#ifndef HACKTEST_YAHOODATA_HPP
#define HACKTEST_YAHOODATA_HPP

#include "ht/DataHandler/Data.hpp"

namespace HackTest {

class YahooData : public Data {
  friend class HistoricalCsvHandler;
  friend class SimpleStrategy;
  friend class SimplePortfolio;
  friend class SimulatedExecutionHandler;

public:
  YahooData(std::string date, double open, double high, double low,
            double close, double adjClose, unsigned long long volume);

  [[nodiscard]] std::string get_date() const { return date_; }
  [[nodiscard]] double get_open() const { return open_; }
  [[nodiscard]] double get_high() const { return high_; }
  [[nodiscard]] double get_low() const { return low_; }
  [[nodiscard]] double get_close() const { return close_; }
  [[nodiscard]] double get_adj_close() const { return adj_close_; }
  [[nodiscard]] unsigned long long get_volume() const { return volume_; }

private:
  std::string date_;
  double open_;
  double high_;
  double low_;
  double close_;
  double adj_close_;
  unsigned long long volume_;
};

std::ostream &operator<<(std::ostream &os, const YahooData &);

} // namespace HackTest

#endif // HACKTEST_YAHOODATA_HPP
