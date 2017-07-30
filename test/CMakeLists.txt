cmake_minimum_required(VERSION 3.6)

find_package(Threads REQUIRED)

set(GOOGLE_TEST_DIR ${CMAKE_BINARY_DIR}/test/google-test)

configure_file(CMakeLists.txt.in google-test/download/CMakeLists.txt)

message("Building googletest")

execute_process(
        COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${GOOGLE_TEST_DIR}/download
)

if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
else()
    message("CMake step for googletest succeeeded")
endif()


execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY  ${GOOGLE_TEST_DIR}/download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
else()
    message("Build step for googletest succeeded")
endif()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory( ${GOOGLE_TEST_DIR}/src  ${GOOGLE_TEST_DIR}/build )

file(GLOB SRCS */*.cpp)

add_executable(${TEST_NAME} ${SRCS})

target_link_libraries(${TEST_NAME}
        ${PROJECT_NAME}
        gtest_main
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})

