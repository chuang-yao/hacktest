//
// Created by Chuang Yao on 10/14/2021.
//

#include "ht/DataHandler/HistoricalCsvHandler.hpp"
#include "ht/Event/MarketEvent.hpp"

#include <fstream>
#include <sstream>

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
      std::cout << itr->second.date_ << '\t' << itr->second.open_ << '\t'
                << itr->second.high_ << '\t' << itr->second.low_ << '\t'
                << itr->second.close_ << '\t' << itr->second.adj_close_ << '\t'
                << itr->second.volume_ << '\n';
    }
  }
}

void HistoricalCsvHandler::update_bars() {
  if (!latest_data_.empty()) {
    bool send_mkt_event{false};
    for (const auto &symbol : symbols_) {
      for (auto itr{data_[symbol].rbegin()};
           itr->first > latest_data_[symbol].rbegin()->first; ++itr) {
        latest_data_[symbol].insert(*itr);
        send_mkt_event = true; // only send a MarketEvent when there is new data
      }
    }
    if (send_mkt_event) {
      add_to_queue<MarketEvent>(q_);
    }
  } else {
    latest_data_ = data_;
    add_to_queue<MarketEvent>(q_);
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
        std::string date = field;
        std::getline(ss, field, ',');
        double open = std::stod(field);
        std::getline(ss, field, ',');
        double high = std::stod(field);
        std::getline(ss, field, ',');
        double low = std::stod(field);
        std::getline(ss, field, ',');
        double close = std::stod(field);
        std::getline(ss, field, ',');
        double adjClose = std::stod(field);
        std::getline(ss, field, ',');
        unsigned long long volume = std::stoull(field);

        YahooData entry(date, open, high, low, close, adjClose, volume);
        data_[symbol].insert({entry.date_, entry});
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
    std::cout << itr_date->second.date_ << '\t' << itr_date->second.open_
              << '\t' << itr_date->second.high_ << '\t' << itr_date->second.low_
              << '\t' << itr_date->second.close_ << '\t'
              << itr_date->second.adj_close_ << '\t' << itr_date->second.volume_
              << '\n';
  } else {
    std::cout << "No data for " << symbol << " on " << date << '\n';
  }
}

bool HistoricalCsvHandler::continue_test() const { return continue_; }

YahooData::YahooData(std::string date, double open, double high, double low,
                     double close, double adjClose, unsigned long long volume)
    : Data("YAHOO", Type::HISTORICAL), date_(std::move(date)), open_(open),
      high_(high), low_(low), close_(close), adj_close_(adjClose),
      volume_(volume) {}

} // namespace HackTest
