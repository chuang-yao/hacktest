//
// Created by Chuang on 10/14/2021.
//

#include "ht/DataHandler/CsvHistoricalHandler.hpp"

namespace HackTest {

CsvHistoricalHandler::CsvHistoricalHandler(EventQueue &q,
                                           std::filesystem::path path,
                                           std::vector<std::string> symbols)
    : q_(q), path_(std::move(path)), symbols_(std::move(symbols)) {}

void CsvHistoricalHandler::get_latest_data() {}

void CsvHistoricalHandler::update_data() {}

} // namespace HackTest
