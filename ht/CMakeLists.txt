set(HT_SOURCES
        HackTest.cpp

        Event/Event.cpp
        Event/MarketEvent.cpp
        Event/SignalEvent.cpp
        Event/OrderEvent.cpp
        Event/FillEvent.cpp

        DataHandler/DataHandler.cpp
        DataHandler/Data.cpp
        DataHandler/YahooData.cpp
        DataHandler/HistoricalCsvHandler.cpp

        Strategy/Strategy.cpp
        Strategy/SimpleStrategy.cpp

        Portfolio/Portfolio.cpp
        Portfolio/SimplePortfolio.cpp

        ExecutionHandler/ExecutionHandler.cpp
        ExecutionHandler/SimulatedExecutionHandler.cpp

        Utilities/Performance.cpp)

set(HT_HEADERS
        HackTest.hpp

        Event/Event.hpp
        Event/MarketEvent.hpp
        Event/SignalEvent.hpp
        Event/OrderEvent.hpp
        Event/FillEvent.hpp

        DataHandler/DataHandler.hpp
        DataHandler/Data.hpp
        DataHandler/YahooData.hpp
        DataHandler/HistoricalCsvHandler.hpp

        Strategy/Strategy.hpp
        Strategy/SimpleStrategy.hpp

        Portfolio/Portfolio.hpp
        Portfolio/SimplePortfolio.hpp

        ExecutionHandler/ExecutionHandler.hpp
        ExecutionHandler/SimulatedExecutionHandler.hpp

        Utilities/Performance.hpp)

add_library(ht
        ${HT_SOURCES}
        ${HT_HEADERS})
