#include "ht/Event/all.h"
#include "ht/HackTest.h"

int main() {
  HackTest::say_hello();

  HackTest::MarketEvent me;
  HackTest::SignalEvent se("AAPL", "2021-01-01", "LONG");
  HackTest::OrderEvent oe("MSFT", "MKT", 100, "SHORT");
  HackTest::FillEvent fe("2021-01-01", "AAPL", "NASDAQ", 100, "LONG", 0.02);
}
