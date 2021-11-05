//
// Created by Chuang on 10/14/2021.
//

#ifndef HACKTEST_DATAHANDLER_HPP
#define HACKTEST_DATAHANDLER_HPP

#include <string>

namespace HackTest {

class DataHandler {
public:
  virtual void get_latest_bars(std::string, size_t) = 0;
  virtual void update_bars() = 0;
};

} // namespace HackTest

#endif // HACKTEST_DATAHANDLER_HPP
