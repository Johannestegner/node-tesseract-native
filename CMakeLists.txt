cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
set(PROJECT_NAME tesseract-native)
set(TEST_NAME ${PROJECT_NAME}-test)
set(CMAKE_CXX_STANDARD 14)

set(TESS_NATIVE_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(TESS_NATIVE_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

set(TESS_NATIVE_TEST_SRC_DIR ${TESS_NATIVE_SRC_DIR}/test)
set(TESS_NATIVE_TEST_BIN_DIR ${TESS_NATIVE_BINARY_DIR}/test)

message(STATUS "Building project ${PROJECT_NAME}")
project(${PROJECT_NAME})

message(STATUS "Building source...")
add_subdirectory(src)   # tesseract-native lib.

enable_testing()
message(STATUS "Building tests...")
add_subdirectory(test)  # tesseract-native-tests.
