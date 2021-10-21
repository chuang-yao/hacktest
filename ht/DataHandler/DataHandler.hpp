//
// Created by Chuang on 10/14/2021.
//

#ifndef HACKTEST_DATAHANDLER_HPP
#define HACKTEST_DATAHANDLER_HPP

namespace HackTest {

class DataHandler {
public:
  virtual void get_latest_data() = 0;
  virtual void update_data() = 0;
};

} // namespace HackTest

#endif // HACKTEST_DATAHANDLER_HPP
