//
// Created by Chuang on 10/14/2021.
//

#include "ht/DataHandler/CsvHistoricalHandler.hpp"
#include <fstream>

namespace HackTest {

CsvHistoricalHandler::CsvHistoricalHandler(EventQueue &q,
                                           std::filesystem::path path,
                                           std::vector<std::string> symbols)
    : q_(q), path_(std::move(path)), symbols_(std::move(symbols)) {}

void CsvHistoricalHandler::get_latest_data() {}

void CsvHistoricalHandler::update_data() {}

void CsvHistoricalHandler::read_csv_file() {
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

void CsvHistoricalHandler::show_data(const std::string &symbol,
                                     const std::string &date) {
  if (data_.contains(symbol) && data_[symbol].contains(date)) {
    std::cout << "Showing data of " << symbol << " on " << date << '\n';
    for (auto &&e : data_[symbol][date]) {
      std::cout << e << '\t';
    }
    std::cout << '\n';
  } else {
    std::cout << "No data of " << symbol << " on " << date << '\n';
  }
}

} // namespace HackTest
