//
// Created by Chuang Yao on 11/4/2021.
//

// Driver program for HackTest

#include "ht/DataHandler/HistoricalCsvHandler.hpp"
#include "ht/Event/Event.hpp"
#include "ht/ExecutionHandler/SimulatedExecutionHandler.hpp"
#include "ht/Portfolio/SimplePortfolio.hpp"
#include "ht/Strategy/SimpleStrategy.hpp"

#include <chrono>
#include <thread>
#include <vector>

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
  HackTest::SimpleStrategy strategy;
  HackTest::SimplePortfolio portfolio;
  HackTest::SimulatedExecutionHandler broker;

  while (true) {
    // update the bars
    if (bars.continueTest) {
      bars.update_bars();
    } else {
      break;
    }

    // handle the events
    while (true) {
      if (q.empty()) {
        break;
      } else {
        auto event = q.get_event();
        switch (event.get_type()) {
        case HackTest::Event::Type::FIL:
          portfolio.update_fill(dynamic_cast<HackTest::FillEvent &>(event));
          break;
        case HackTest::Event::Type::MKT:
          strategy.calculate_signal(
              dynamic_cast<HackTest::MarketEvent &>(event));
          portfolio.update_time_index(
              dynamic_cast<HackTest::MarketEvent &>(event));
          break;
        case HackTest::Event::Type::ORD:
          broker.execute_order(dynamic_cast<HackTest::OrderEvent &>(event));
          break;
        case HackTest::Event::Type::SIG:
          portfolio.update_signal(dynamic_cast<HackTest::SignalEvent &>(event));
          break;
        default:
          break;
        }
      }
    }

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1000ms);
  }
}
