#include "ht/DataHandler/all.hpp"
#include "ht/Event/all.hpp"
#include "ht/HackTest.hpp"

namespace fs = std::filesystem;

int main() {
  HackTest::say_hello();

  HackTest::EventQueue q;

  HackTest::MarketEvent me(q);
  HackTest::SignalEvent se(q, "AAPL", "LONG");
  HackTest::OrderEvent oe(q, "AAPL", "MKT", 100, "SHORT");
  HackTest::FillEvent fe(q, "AAPL", "NASDAQ", 100, "LONG", 0.02);
  q.show();

#ifdef __linux__
  fs::path path{"/home/chuang/HackTest/examples/data"};
#endif
#ifdef _WIN32
  fs::path path{R"(C:\Users\chuan\CLionProjects\HackTest\examples\data)"};
#endif

  std::vector<std::string> symbols{"AAPL", "^IXIC", "MSFT"};
  HackTest::HistoricalCsvHandler dh(q, path, symbols);

  dh.show_data_on_date("AMD", "2019-06-13");

  dh.show_data_on_date("AAPL", "2019-06-13");
  dh.show_data_on_date("AAPL", "2021-06-13");
  dh.show_data_on_date("MSFT", "2019-06-13");
  dh.show_data_on_date("MSFT", "2021-06-13");

  dh.get_latest_bars("AAPL", 5);
  dh.get_latest_bars("MSFT", 5);
}
