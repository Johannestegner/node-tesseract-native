cmake_minimum_required(VERSION 3.6)

message("Building the ${PROJECT_NAME} library from /src directory...")


set(LEPTONICA_DIR ${CMAKE_BINARY_DIR}/src/leptonica)

configure_file(leptonica.in leptonica/download/CMakeLists.txt)

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
    message(FATAL_ERROR "Build step for leptonica fialed: ${result}")
else()
    message("Build step for leptonica succeeded")
endif()


add_subdirectory( ${LEPTONICA_DIR}/src  ${LEPTONICA_DIR}/build )











set(SOURCE_FILES
        Api.cpp
        Api.h
        Result.h
        TesseractOptions.h)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

message("Library created.")

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

message("Library created and done...")
