cmake_minimum_required()(VERSION 3.19)
project(
    Xorswift
    Version 0.1)

add_library(xorswift xorswift.cpp)
add_executable(xorswift_test xorswift_test.cpp)

target_link_libraries(xorswift  PRIVATE xorswift_test)