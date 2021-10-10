#include "MarketEvent.hpp"

namespace HackTest {

MarketEvent::MarketEvent(EventQueue &q) : Event(Type::Market, q) {}

} // namespace HackTest
