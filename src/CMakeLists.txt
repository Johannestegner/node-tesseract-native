cmake_minimum_required(VERSION 3.6)
project(TEST_NAME)

######################################################
#
# Libleptonica download and build.
#
######################################################

set(LEPTONICA_DIR "${CMAKE_CURRENT_BINARY_DIR}/leptonica")


configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/External_leptonica.cmake
    ${LEPTONICA_DIR}/download/CMakeLists.txt
)

execute_process(
    COMMAND ${CMAKE_COMMAND} -G ${CMAKE_GENERATOR} .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${LEPTONICA_DIR}/download
)

if(result)
    message(FATAL_ERROR "CMake step for leptonica failed: ${result}")
endif()

execute_process(
    COMMAND bash ${LEPTONICA_DIR}/src/make-for-local
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${LEPTONICA_DIR}/src
)

execute_process(
    COMMAND make
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${LEPTONICA_DIR}/src
)

if(result)
    message(FATAL_ERROR "Build step for leptonica failed: ${result}")
endif()

######################################################
#
# Libleptonica test download and build end.
#
######################################################

file(GLOB SOURCE_FILES *.cpp *.h */*.cpp */*.h)
add_library(${PROJECT_NAME} ${SOURCE_FILES})


target_include_directories(
    ${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src
)

add_subdirectory(
    ${LEPTONICA_DIR}/src
    ${LEPTONICA_DIR}/build
)

#find_library(TESS tesseract REQUIRED)
#find_library(LEPT lept REQUIRED)

#target_link_libraries(
  #  ${PROJECT_NAME}
 #   ${TESS}
 #   ${LEPT}
#)

message(STATUS "Library ${PROJECT_NAME} created and done...")
