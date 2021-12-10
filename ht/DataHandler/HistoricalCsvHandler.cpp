//
// Created by Chuang Yao on 10/14/2021.
//

#include "ht/DataHandler/HistoricalCsvHandler.hpp"
#include "ht/DataHandler/YahooData.hpp"
#include "ht/Event/MarketEvent.hpp"

#include <fstream>
#include <sstream>
#include <utility>

namespace HackTest {

HistoricalCsvHandler::HistoricalCsvHandler(EventQueue &q,
                                           std::filesystem::path path,
                                           std::vector<std::string> symbols,
                                           std::string date)
    : q_(q), path_(std::move(path)), symbols_(std::move(symbols)),
      start_date_(std::move(date)) {
  read_csv_files_();
}

std::any HistoricalCsvHandler::get_latest_bars(std::string symbol, size_t n) {
  std::map<std::string, YahooData> bars;
  if (data_.contains(symbol)) {
    for (auto itr{data_[symbol].rbegin()};
         itr != data_[symbol].rend() && n != 0; ++itr, --n) {
      bars.insert(
          {itr->second.date_,
           YahooData(itr->second.date_, itr->second.open_, itr->second.high_,
                     itr->second.low_, itr->second.close_,
                     itr->second.adj_close_, itr->second.volume_)});
    }
  }
  return bars;
}

void HistoricalCsvHandler::update_bars() {
  for (auto &df : data_) {
    std::map<std::string, YahooData> entry;
    entry.insert({df.second.begin()->first, df.second.begin()->second});
    if (!latest_data_.contains(df.first)) {
      latest_data_.insert({df.first, std::map<std::string, YahooData>()});
    }
    latest_data_[df.first].insert(
        {entry.begin()->first, entry.begin()->second});
    if (!df.second.empty()) {
      df.second.erase(df.second.begin());
    }
  }

  add_to_queue<MarketEvent>(q_);

  bool is_empty{true};
  for (const auto &df : data_) {
    if (!df.second.empty()) {
      is_empty = false;
    }
  }
  if (is_empty) {
    continue_ = false;
  }
}

void HistoricalCsvHandler::read_csv_files_() {
  for (const auto &symbol : symbols_) {
    std::ifstream file(path_ / (symbol + ".csv"));
    if (file.is_open()) {
      std::string line;
      std::getline(file, line); // drop the first line of the CSV file
      while (std::getline(file, line)) {
        std::istringstream ss(line);
        // Date,Open,High,Low,Close,Adj Close,Volume
        std::string field;
        std::getline(ss, field, ',');
        if (field >= start_date_) {
          std::string date{field};
          std::getline(ss, field, ',');
          double open{std::stod(field)};
          std::getline(ss, field, ',');
          double high{std::stod(field)};
          std::getline(ss, field, ',');
          double low{std::stod(field)};
          std::getline(ss, field, ',');
          double close{std::stod(field)};
          std::getline(ss, field, ',');
          double adjClose{std::stod(field)};
          std::getline(ss, field, ',');
          uint64_t volume{std::stoull(field)};

          YahooData entry(date, open, high, low, close, adjClose, volume);
          data_[symbol].insert({entry.date_, entry});
        } else {
          continue;
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
    auto itr_symbol = data_.find(symbol);
    auto itr_date = itr_symbol->second.find(date);
    std::cout << "Showing data for " << symbol << " on " << date << '\n';
    std::cout << itr_date->second;
  } else {
    std::cout << "No data for " << symbol << " on " << date << '\n';
  }
}

bool HistoricalCsvHandler::continue_test() const { return continue_; }

} // namespace HackTest
