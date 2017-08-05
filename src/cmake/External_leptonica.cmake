cmake_minimum_required(VERSION 3.6)
project(leptonica-download NONE)

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
