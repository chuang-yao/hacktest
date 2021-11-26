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
#include <iostream>
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

  HackTest::MarketEvent me(q);
  HackTest::SignalEvent se(q, "AAPL", "LONG");
  HackTest::OrderEvent oe(q, "AAPL", "MKT", 100, "SHORT");
  HackTest::FillEvent fe(q, "AAPL", "NASDAQ", 100, "LONG", 0.02);

  while (true) {
    // update the bars
    if (bars.continue_test()) {
      bars.update_bars();
    } else {
      break;
    }
    // handle the events
    while (true) {
      if (q.empty()) {
        break;
      } else {
        auto event_handle = q.get_event();
        switch (event_handle->get_type()) {
        case HackTest::Event::Type::FIL:
          portfolio.update_fill(
              *std::static_pointer_cast<HackTest::FillEvent>(event_handle));
          break;
        case HackTest::Event::Type::MKT:
          strategy.calculate_signal(
              *std::static_pointer_cast<HackTest::MarketEvent>(event_handle));
          portfolio.update_time_index(
              *std::static_pointer_cast<HackTest::MarketEvent>(event_handle));
          break;
        case HackTest::Event::Type::ORD:
          broker.execute_order(
              *std::static_pointer_cast<HackTest::OrderEvent>(event_handle));
          break;
        case HackTest::Event::Type::SIG:
          portfolio.update_signal(
              *std::static_pointer_cast<HackTest::SignalEvent>(event_handle));
          break;
        default:
          break;
        }
      }
    }

    std::cout << "The event queue is now empty! Sleep for 1000ms...\n";
    
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1000ms);
  }
}
