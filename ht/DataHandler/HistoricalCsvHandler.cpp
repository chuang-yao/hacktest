//
// Created by Chuang on 10/14/2021.
//

#include "ht/DataHandler/HistoricalCsvHandler.hpp"

#include <fstream>

namespace HackTest {

HistoricalCsvHandler::HistoricalCsvHandler(EventQueue &q,
                                           std::filesystem::path path,
                                           std::vector<std::string> symbols)
    : q_(q), path_(std::move(path)), symbols_(std::move(symbols)) {
  read_csv_file_();
}

void HistoricalCsvHandler::get_latest_bars(std::string symbol, size_t n) {
  if (data_.contains(symbol)) {
    std::cout << "Showing the latest " << n << " entries for " << symbol
              << '\n';
    for (auto itr = data_[symbol].rbegin();
         itr != data_[symbol].rend() && n != 0; ++itr, --n) {
      std::cout << itr->first << '\t';
      for (auto &&e : itr->second) {
        std::cout << e << '\t';
      }
      std::cout << '\n';
    }
  }
}

void HistoricalCsvHandler::update_bars() {}

void HistoricalCsvHandler::read_csv_file_() {
  for (auto &&symbol : symbols_) {
    std::ifstream file(path_ / (symbol + ".csv"));
    if (file.is_open()) {
      std::string line;
      std::getline(file, line); // drop the first line of the CSV file
      while (std::getline(file, line)) {
        std::istringstream ss(line);
        // Date,Open,High,Low,Close,Adj Close,Volume
        std::string field;
        std::getline(ss, field, ',');
        std::string date{field};
        std::vector<double> values;
        while (std::getline(ss, field, ',')) {
          double v = std::stod(field);
          data_[symbol][date].push_back(v);
        }
      }
    } else {
      std::cout << "Failed to open " << path_ / (symbol + ".csv") << '\n';
      continue;
    }
  }
}

void HistoricalCsvHandler::show_data_on_date(const std::string &symbol,
                                             const std::string &date) {
  if (data_.contains(symbol) && data_[symbol].contains(date)) {
    std::cout << "Showing data for " << symbol << " on " << date << '\n';
    for (auto &&e : data_[symbol][date]) {
      std::cout << e << '\t';
    }
    std::cout << '\n';
  } else {
    std::cout << "No data for " << symbol << " on " << date << '\n';
  }
}

} // namespace HackTest
