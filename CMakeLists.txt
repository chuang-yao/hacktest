cmake_minimum_required(VERSION 3.16.3)

project(HackTest)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(Boost)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif (Boost_FOUND)

add_subdirectory("ht")
add_subdirectory("examples")
