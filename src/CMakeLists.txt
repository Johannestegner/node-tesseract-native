cmake_minimum_required(VERSION 3.6)

message("Building the ${PROJECT_NAME} library from /src directory...")


#############################################
## Leptonica
#############################################
#set(LEPTONICA_DIR ${CMAKE_CURRENT_BINARY_DIR}/leptonica)

#set(TESSERACT_DIR ${CMAKE_CURRENT_BINARY_DIR}/tesseract)
#configure_file(cmake/External_tesseract.cmake tesseract/download/CMakeLists.txt)

#add_subdirectory(${TESSERACT_DIR}/src ${TESSERACT_DIR}/build)

set(SOURCE_FILES
    Api.cpp
    Api.h
    Result.h
    TesseractOptions.h
)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

message("Library created.")

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

find_library(TESS tesseract)
find_library(LEPT leptonica)

target_link_libraries(
        ${PROJECT_NAME}
        ${TESS}
        ${LEPT}
)

message("Library created and done...")
