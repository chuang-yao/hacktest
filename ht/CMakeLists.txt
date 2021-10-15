set(HT_SOURCES
        HackTest.cpp

        Event/Event.cpp
        Event/MarketEvent.cpp
        Event/SignalEvent.cpp
        Event/OrderEvent.cpp
        Event/FillEvent.cpp

        DataHandler/DataHandler.cpp
        DataHandler/CsvHistoricalHandler.cpp)

set(HT_HEADERS
        HackTest.hpp

        Event/Event.hpp
        Event/MarketEvent.hpp
        Event/SignalEvent.hpp
        Event/OrderEvent.hpp
        Event/FillEvent.hpp

        DataHandler/DataHandler.hpp
        DataHandler/CsvHistoricalHandler.hpp)

add_library(ht
        ${HT_SOURCES}
        ${HT_HEADERS})
