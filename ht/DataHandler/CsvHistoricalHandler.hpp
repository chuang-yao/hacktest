//
// Created by Chuang on 10/14/2021.
//

#ifndef HACKTEST_CSVHISTORICALHANDLER_HPP
#define HACKTEST_CSVHISTORICALHANDLER_HPP

#include <filesystem>
#include <string>

#include "ht/DataHandler/DataHandler.hpp"
#include "ht/Event/Event.hpp"

namespace HackTest {

class CsvHistoricalHandler : public DataHandler {
public:
  CsvHistoricalHandler(EventQueue &, std::filesystem::path,
                       std::vector<std::string>);

  void get_latest_data() override;
  void update_data() override;

private:
  EventQueue &q_;                    // reference to the current event queue
  std::filesystem::path path_;       // path to the directory of CSV files
  std::vector<std::string> symbols_; // a list of symbols to look for CSV files
};

} // namespace HackTest

#endif // HACKTEST_CSVHISTORICALHANDLER_HPP
