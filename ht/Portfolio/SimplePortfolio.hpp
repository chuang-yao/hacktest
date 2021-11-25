//
// Created by Chuang Yao on 11/10/2021.
//

#ifndef HACKTEST_SIMPLEPORTFOLIO_HPP
#define HACKTEST_SIMPLEPORTFOLIO_HPP

#include "ht/Portfolio/Portfolio.hpp"

namespace HackTest {

class SimplePortfolio : public Portfolio {
   void update_signal(SignalEvent) override;
   void update_fill(FillEvent) override;
};

} // namespace HackTest

#endif // HACKTEST_SIMPLEPORTFOLIO_HPP
