set(SOURCE_FILES
        Api.cpp
        Api.h
        Result.h
        TesseractOptions.h)

include_directories(F:/SDKs/leptonica-1.74.4/src)
include_directories(F:/SDKs/leptonica-1.74.4/build/src)

include_directories(F:/SDKs/tesseract-4.00.00dev/api)
include_directories(F:/SDKs/tesseract-4.00.00dev/ccutil)
include_directories(F:/SDKs/tesseract-4.00.00dev/ccstruct)
include_directories(F:/SDKs/tesseract-4.00.00dev/ccmain)

add_library(tesseract_native STATIC ${SOURCE_FILES})

target_include_directories(tesseract_native PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)
