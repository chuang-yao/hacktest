//
// Created by Chuang Yao on 12/6/21.
//

#include "ht/Utilities/Performance.hpp"

#include <numeric>
#include <vector>

namespace HackTest {

double calculate_sharpe_ratio(const std::vector<double> &returns, double r_f,
                              uint32_t periods = 252) {
  // Daily - 252
  // Hourly - 252 * 6.5
  // Minutely - 252 * 6.5 * 60
  double sum{std::accumulate(returns.cbegin(), returns.cend(), 0.0)};
  double avg{sum / static_cast<double>(returns.size())};
  double std{0};
  for (const auto &r : returns) {
    std += (r - avg) * (r - avg);
  }
  std /= static_cast<double>(returns.size() - 1);
  return sqrt(periods) * (avg - r_f) / std;
}

} // namespace HackTest