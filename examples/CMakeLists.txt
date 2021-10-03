if((UNIX AND (NOT APPLE)) AND (CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))
  add_compile_options(-stdlib=libc++)
  add_link_options(-stdlib=libc++ -lc++abi)
endif()

add_executable(hello hello.cpp)
target_link_libraries(hello ht)
