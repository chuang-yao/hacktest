add_executable(test test.cpp)
target_link_libraries(test ht)

add_executable(HackTest main.cpp)
target_link_libraries(HackTest ht)
