//
// Created by Chuang on 10/14/2021.
//

#ifndef HACKTEST_HISTORICALCSVHANDLER_HPP
#define HACKTEST_HISTORICALCSVHANDLER_HPP

#include <filesystem>
#include <map>
#include <string>

#include "ht/DataHandler/DataHandler.hpp"
#include "ht/Event/Event.hpp"

namespace HackTest {

class HistoricalCsvHandler : public DataHandler {
public:
  HistoricalCsvHandler(EventQueue &, std::filesystem::path,
                       std::vector<std::string>);

  void get_latest_bars(std::string, size_t) override;
  void update_bars() override;
  void show_data_on_date(const std::string &symbol, const std::string &date);

private:
  EventQueue &q_;                    // reference to the current event queue
  std::filesystem::path path_;       // path to the directory of CSV files
  std::vector<std::string> symbols_; // a list of symbols to look for CSV files
  std::map<std::string, std::map<std::string, std::vector<double>>>
      data_; // data read from CSV files

  void read_csv_file_();
};

} // namespace HackTest

#endif // HACKTEST_HISTORICALCSVHANDLER_HPP
