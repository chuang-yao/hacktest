//
// Created by Chuang Yao on 11/10/2021.
//

#ifndef HACKTEST_DATA_HPP
#define HACKTEST_DATA_HPP

#include <string>

namespace HackTest {

class Data {
public:
  enum class Type { HISTORICAL, LIVE };
  Data(std::string, Type);

private:
  std::string source_;
  Type type_;
};

} // namespace HackTest

#endif // HACKTEST_DATA_HPP
