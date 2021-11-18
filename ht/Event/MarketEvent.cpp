#include "ht/Event/MarketEvent.hpp"

namespace HackTest {

MarketEvent::MarketEvent(EventQueue &q) : Event(Type::MKT, q) {}

} // namespace HackTest
