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

  fs::path path{R"(C:\Users\chuan\CLionProjects\HackTest\examples\data)"};
  std::vector<std::string> symbols{"AAPL", "^IXIC", "MSFT"};

  HackTest::CsvHistoricalHandler dh(q, path, symbols);
  dh.read_csv_file();
  dh.show_data("AAPL", "2021-06-10");
  dh.show_data("AAPL", "2021-06-13");
}
