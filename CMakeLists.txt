cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
set(PROJECT_NAME tesseract-native)
set(TEST_NAME ${PROJECT_NAME}-test)

project(${PROJECT_NAME})

add_subdirectory(src)   # tesseract-native lib.
enable_testing()
add_subdirectory(test)  # tesseract-native-tests.
