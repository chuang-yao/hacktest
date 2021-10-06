set(HT_SOURCES
        HackTest.cpp

        Event/Event.cpp
        Event/MarketEvent.cpp
        Event/SignalEvent.cpp
        Event/OrderEvent.cpp
        Event/FillEvent.cpp)

set(HT_HEADERS
        HackTest.h

        Event/Event.h
        Event/MarketEvent.h
        Event/SignalEvent.h
        Event/OrderEvent.h
        Event/FillEvent.h)

add_library(ht
        ${HT_SOURCES}
        ${HT_HEADERS})
