#ifndef TESSERACT_NATIVE_RESULT_H_
#define TESSERACT_NATIVE_RESULT_H_
#include <string>

namespace TesseractNative
{
    struct Result
    {
        bool error;
        std::string value;
        std::string errorMessage;
    };

};

#endif // TESSERACT_NATIVE_RESULT_H_
