//
// Created by Chuang Yao on 10/14/2021.
//

#ifndef HACKTEST_DATAHANDLER_HPP
#define HACKTEST_DATAHANDLER_HPP

#include <any>
#include <string>

namespace HackTest {

class DataHandler {
public:
  virtual ~DataHandler() = default;
  // Returns the last N bars from the latest_symbol list, or fewer if less bars
  // are available.
  virtual std::any get_latest_bars(std::string, size_t) = 0;
  // Pushes the latest bar to the latest symbol structure for all symbols in the
  // symbol list.
  virtual void update_bars() = 0;
};

} // namespace HackTest

#endif // HACKTEST_DATAHANDLER_HPP
