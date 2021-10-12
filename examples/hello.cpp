#include "ht/Event/all.hpp"
#include "ht/HackTest.hpp"

#include <chrono>
#include <thread>

int main() {
  HackTest::say_hello();

  HackTest::EventQueue q;

  HackTest::MarketEvent me(q);
  std::this_thread::sleep_for(std::chrono::milliseconds(1500));

  HackTest::SignalEvent se(q, "AAPL", "LONG");
  std::this_thread::sleep_for(std::chrono::milliseconds(1500));

  HackTest::OrderEvent oe(q, "AAPL", "MKT", 100, "SHORT");
  std::this_thread::sleep_for(std::chrono::milliseconds(1500));

  HackTest::FillEvent fe(q, "AAPL", "NASDAQ", 100, "LONG", 0.02);
  std::this_thread::sleep_for(std::chrono::milliseconds(1500));

  q.show();
}
