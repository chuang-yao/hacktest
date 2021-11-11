//
// Created by Chuang on 10/14/2021.
//

#include "ht/DataHandler/HistoricalCsvHandler.hpp"
#include "ht/Event/MarketEvent.hpp"

#include <fstream>

namespace HackTest {

HistoricalCsvHandler::HistoricalCsvHandler(EventQueue &q,
                                           std::filesystem::path path,
                                           std::vector<std::string> symbols)
    : q_(q), path_(std::move(path)), symbols_(std::move(symbols)) {
  read_csv_files_();
}

void HistoricalCsvHandler::get_latest_bars(std::string symbol, size_t n) {
  if (data_.contains(symbol)) {
    std::cout << "Showing the latest " << n << " entries for " << symbol
              << '\n';
    for (auto itr = data_[symbol].rbegin();
         itr != data_[symbol].rend() && n != 0; ++itr, --n) {
      std::cout << (itr->second).date_ << '\t' << (itr->second).open_ << '\t'
                << (itr->second).high_ << '\t' << (itr->second).low_ << '\t'
                << (itr->second).close_ << '\t' << (itr->second).adjClose_
                << '\t' << (itr->second).volume_ << '\n';
    }
  }
}

void HistoricalCsvHandler::update_bars() { MarketEvent e(q_); }

void HistoricalCsvHandler::read_csv_files_() {
  for (auto &&symbol : symbols_) {
    std::ifstream file(path_ / (symbol + ".csv"));
    if (file.is_open()) {
      std::string line;
      std::getline(file, line); // drop the first line of the CSV file
      while (std::getline(file, line)) {
        std::istringstream ss(line);
        // Date,Open,High,Low,Close,Adj Close,Volume
        YahooData entry;
        std::string field;
        std::getline(ss, field, ',');
        entry.date_ = field;
        std::getline(ss, field, ',');
        entry.open_ = std::stod(field);
        std::getline(ss, field, ',');
        entry.high_ = std::stod(field);
        std::getline(ss, field, ',');
        entry.low_ = std::stod(field);
        std::getline(ss, field, ',');
        entry.close_ = std::stod(field);
        std::getline(ss, field, ',');
        entry.adjClose_ = std::stod(field);
        std::getline(ss, field, ',');
        entry.volume_ = std::stoull(field);
        data_[symbol][entry.date_] = entry;
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
    std::cout << data_[symbol][date].date_ << '\t' << data_[symbol][date].open_
              << '\t' << data_[symbol][date].high_ << '\t'
              << data_[symbol][date].low_ << '\t' << data_[symbol][date].close_
              << '\t' << data_[symbol][date].adjClose_ << '\t'
              << data_[symbol][date].volume_ << '\n';
  } else {
    std::cout << "No data for " << symbol << " on " << date << '\n';
  }
}

YahooData::YahooData() : Data("YAHOO", Type::HISTORICAL) {}

YahooData::YahooData(std::string date, double open, double high, double low,
                     double close, double adjClose, unsigned long long volume)
    : Data("YAHOO", Type::HISTORICAL), date_(std::move(date)), open_(open),
      high_(high), low_(low), close_(close), adjClose_(adjClose),
      volume_(volume) {}

} // namespace HackTest
