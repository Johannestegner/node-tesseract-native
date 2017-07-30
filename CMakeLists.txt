cmake_minimum_required(VERSION 3.6)

cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_CXX_STANDARD 11)

set(PROJECT_NAME tesseract-native)
set(TEST_NAME ${PROJECT_NAME}-test)

project(${PROJECT_NAME})


enable_testing()

add_subdirectory(src)   # tesseract-native lib.

message("Building the ${TEST_NAME} executable from /test directory...")
add_subdirectory(test)  # tesseract-native-tests.
