set(HT_SOURCES
        HackTest.cpp

        Event/Event.cpp
        Event/MarketEvent.cpp
        Event/SignalEvent.cpp
        Event/OrderEvent.cpp
        Event/FillEvent.cpp

        DataHandler/DataHandler.cpp
        DataHandler/Data.cpp
        DataHandler/HistoricalCsvHandler.cpp

        Portfolio/Portfolio.cpp
        Portfolio/SimplePortfolio.cpp)

set(HT_HEADERS
        HackTest.hpp

        Event/Event.hpp
        Event/MarketEvent.hpp
        Event/SignalEvent.hpp
        Event/OrderEvent.hpp
        Event/FillEvent.hpp

        DataHandler/DataHandler.hpp
        DataHandler/Data.hpp
        DataHandler/HistoricalCsvHandler.hpp

        Portfolio/Portfolio.hpp
        Portfolio/SimplePortfolio.hpp)

add_library(ht
        ${HT_SOURCES}
        ${HT_HEADERS})
