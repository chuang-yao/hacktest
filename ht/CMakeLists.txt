if((UNIX AND (NOT APPLE)) AND (CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))
  add_compile_options(-stdlib=libc++)
  add_link_options(-stdlib=libc++ -lc++abi)
endif()

set(HT_SOURCES
    HackTest.cpp)

set(HT_HEADERS
    HackTest.hpp)

add_library(ht
    ${HT_SOURCES}
    ${HT_HEADERS})
