//
// Created by Chuang Yao on 12/9/21.
//

#include "ht/DataHandler/YahooData.hpp"

#include <iomanip>
#include <iostream>
#include <string>

namespace HackTest {

YahooData::YahooData(std::string date, double open, double high, double low,
                     double close, double adjClose, uint64_t volume)
    : Data("YAHOO", Type::HISTORICAL), date_(std::move(date)), open_(open),
      high_(high), low_(low), close_(close), adj_close_(adjClose),
      volume_(volume) {}

std::ostream &operator<<(std::ostream &os, const YahooData &data) {
  os << data.get_date() << std::setw(12) << data.get_open() << std::setw(12)
     << data.get_high() << std::setw(12) << data.get_low() << std::setw(12)
     << data.get_close() << std::setw(12) << data.get_adj_close()
     << std::setw(12) << data.get_volume() << '\n';
  return os;
}

} // namespace HackTest