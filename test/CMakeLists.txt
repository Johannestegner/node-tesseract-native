cmake_minimum_required(VERSION 3.6)
find_package(Threads REQUIRED)

project(${PROJECT_NAME})

######################################################
#
# Google Test download and build.
# Should later be moved to its own cmake file.
#
######################################################

set(GOOGLE_TEST_DIR ${TESS_NATIVE_TEST_BIN_DIR}/google-test)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/External_gtest.cmake
    google-test/download/CMakeLists.txt
)


add_subdirectory(
    ${GOOGLE_TEST_DIR}/src
    ${GOOGLE_TEST_DIR}/build
)

execute_process(
    COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${GOOGLE_TEST_DIR}/download
)

if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()

execute_process(
    COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY  ${GOOGLE_TEST_DIR}/download
)

if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

message(STATUS "Successfully built gtest from source.")

######################################################
#
# Google test download and build end.
#
######################################################

file(GLOB_RECURSE SRCS *.cpp)

add_executable(
    ${TEST_NAME}
    ${SRCS}
)

target_link_libraries(
    ${TEST_NAME}
    ${PROJECT_NAME}
    gtest
    gtest_main
)

file(
    COPY ${TESS_NATIVE_TEST_SRC_DIR}/resources
    DESTINATION ${TESS_NATIVE_TEST_BIN_DIR}
)

add_test(
    NAME AllTests
    COMMAND ${TEST_NAME}
)

message(STATUS "Successfully built ${TEST_NAME}.")
