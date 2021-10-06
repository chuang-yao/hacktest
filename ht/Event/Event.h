//
// Created by Chuang on 10/6/2021.
//

#ifndef HACKTEST_EVENT_H
#define HACKTEST_EVENT_H

#include <string>

namespace HackTest {

class Event {
public:
  explicit Event(std::string);

protected:
  std::string type_;
};

} // namespace HackTest

#endif // HACKTEST_EVENT_H
