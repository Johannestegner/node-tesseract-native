cmake_minimum_required(VERSION 3.6)

message("Building lib leptonica...")

include(ExternalProject)
ExternalProject_Add(leptonica
        GIT_REPOSITORY    https://github.com/DanBloomberg/leptonica.git
        GIT_TAG           v1.74.3
        SOURCE_DIR        "${LEPTONICA_DIR}/src"
        BINARY_DIR        "${LEPTONICA_DIR}/build"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND     ""
        INSTALL_COMMAND   ""
        TEST_COMMAND      ""
)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${LEPTONICA_DIR}/download
)

if(result)
    message(FATAL_ERROR "CMake step for leptonica failed: ${result}")
else()
    message("CMake step for leptonica succeded.")
endif()

execute_process(COMMAND  ${CMAKE_COMMAND} --build .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${LEPTONICA_DIR}/download
)

if(result)
    message(FATAL_ERROR "Build step for leptonica failed: ${result}")
else()
    message("Build step for leptonica succeeded")
endif()

execute_process(COMMAND ./configure .
                RESULT_VARIABLE result
                WORKING_DIRECTORY ${LEPTONICA_DIR}/src
)

