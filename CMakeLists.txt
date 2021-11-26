cmake_minimum_required(VERSION 3.16.3)

project(HackTest)

set(CMAKE_CXX_STANDARD 20)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DDEBUG)
endif ()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(Boost)
if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif (Boost_FOUND)

add_subdirectory("ht")
add_subdirectory("examples")
