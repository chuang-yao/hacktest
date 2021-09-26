set(HT_SOURCES
    HackTest.cpp)

set(HT_HEADERS
    HackTest.hpp)

add_library(ht_library
    ${HT_SOURCES}
    ${HT_HEADERS})

target_include_directories(ht_library PUBLIC
    ${CMAKE_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}
    ${Boost_INCLUDE_DIRS})

target_link_directories(ht_library PUBLIC
    ${BOOST_LIBRARY_DIRS})
