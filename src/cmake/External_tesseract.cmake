cmake_minimum_required(VERSION 3.6)
find_package(leptonica REQUIRED)

include(ExternalProject)
ExternalProject_Add(tesseract
       GIT_REPOSITORY    https://github.com/tesseract-ocr/tesseract.git
       GIT_TAG           master
       SOURCE_DIR        "${TESSERACT_DIR}/src"
       BINARY_DIR        "${TESSERACT_DIR}/build"
       CONFIGURE_COMMAND ""
       BUILD_COMMAND     ""
       INSTALL_COMMAND   ""
       TEST_COMMAND      ""
)

execute_process(
        COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${TESSERACT_DIR}/download
)

execute_process(
        COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY  ${TESSERACT_DIR}/download
)
