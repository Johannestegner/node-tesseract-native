cmake_minimum_required(VERSION 3.6)
project(googletest-download NONE)

include(ExternalProject)
ExternalProject_Add(googletest
        GIT_REPOSITORY    https://github.com/google/googletest.git
        GIT_TAG           master
        SOURCE_DIR        "${GOOGLE_TEST_DIR}/src"
        BINARY_DIR        "${GOOGLE_TEST_DIR}/build"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND     ""
        INSTALL_COMMAND   ""
        TEST_COMMAND      ""
)
