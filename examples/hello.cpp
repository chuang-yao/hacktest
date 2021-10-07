#include "ht/Event/all.hpp"
#include "ht/HackTest.hpp"

int main() {
  HackTest::say_hello();

  HackTest::MarketEvent me;
  HackTest::SignalEvent se("AAPL", "LONG");
  HackTest::OrderEvent oe("MSFT", "MKT", 100, "SHORT");
  HackTest::FillEvent fe("AAPL", "NASDAQ", 100, "LONG", 0.02);
}
