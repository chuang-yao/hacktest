//
// Created by chuan on 11/4/2021.
//

// Driver program for HackTest

#include "ht/Event/Event.hpp"
#include "ht/DataHandler/HistoricalCsvHandler.hpp"
#include "ht/Strategy/Strategy.hpp"
#include "ht/Portfolio/SimplePortfolio.hpp"
#include "ht/ExecutionHandler/ExecutionHandler.hpp"

#include <vector>
#include <string>

namespace fs = std::filesystem;

int main() {
  std::vector<std::string> symbols{"AAPL", "^IXIC", "MSFT"};
#ifdef __linux__
  fs::path path{"/home/chuang/HackTest/examples/data"};
#endif
#ifdef _WIN32
  fs::path path{R"(C:\Users\Chuang\CLionProjects\HackTest\examples\data)"};
#endif
#ifdef __APPLE__
  fs::path path{"/Users/cyao/Developer/CLionProjects/HackTest/examples/data"};
#endif

  HackTest::EventQueue q;
  HackTest::HistoricalCsvHandler bars(q, path, symbols);
  HackTest::Strategy strat;
  HackTest::SimplePortfolio port;
  HackTest::ExecutionHandler broker;
}
