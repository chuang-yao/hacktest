//
// Created by Chuang Yao on 11/4/2021.
//

// Driver program for HackTest

#include "ht/DataHandler/HistoricalCsvHandler.hpp"
#include "ht/ExecutionHandler/SimulatedExecutionHandler.hpp"
#include "ht/Portfolio/SimplePortfolio.hpp"
#include "ht/Strategy/SimpleStrategy.hpp"

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace HackTest;
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

  EventQueue q;
  HistoricalCsvHandler bars(q, path, symbols);
  SimpleStrategy strategy(q, bars);
  SimplePortfolio portfolio(q, bars, "2021-01-01", 100.0);
  SimulatedExecutionHandler broker;

  while (true) {
    // update the bars
    if (bars.continue_test()) {
      bars.update_bars();
    } else {
      break;
    }
    // handle the events
    while (!q.is_empty()) {
      auto event_handle{std::move(q.get_event_handle())};
      switch (event_handle->get_type()) {
      case Event::Type::FIL:
#ifdef DEBUG
        std::cout << "Handling FillEvent...\n";
#endif
        portfolio.update_fill(
            *std::dynamic_pointer_cast<FillEvent>(event_handle));
        break;
      case Event::Type::MKT:
#ifdef DEBUG
        std::cout << "Handling MarketEvent...\n";
#endif
        strategy.calculate_signal(
            *std::dynamic_pointer_cast<MarketEvent>(event_handle));
        portfolio.update_time_index(
            *std::dynamic_pointer_cast<MarketEvent>(event_handle));
        break;
      case Event::Type::ORD:
#ifdef DEBUG
        std::cout << "Handling OrderEvent...\n";
#endif
        broker.execute_order(
            *std::dynamic_pointer_cast<OrderEvent>(event_handle));
        break;
      case Event::Type::SIG:
#ifdef DEBUG
        std::cout << "Handling SignalEvent...\n";
#endif
        portfolio.update_signal(
            *std::dynamic_pointer_cast<SignalEvent>(event_handle));
        break;
      default:
        break;
      }
    }
#ifdef DEBUG
    std::cout << "The event queue is now empty! Sleep for 1000ms...\n";
#endif
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(1000ms);
  }
}
