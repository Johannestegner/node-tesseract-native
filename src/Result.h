#ifndef TESSERACT_NATIVE_RESULT_H_
#define TESSERACT_NATIVE_RESULT_H_
#include <string>

namespace TesseractNative
{
    /**
     * Result structure which is returned from any Api.Process calls.
     * Either contains the string value of the processed image or an
     * error message. 
     * In case of error, the `error` boolean member will be set to true.
     */
    struct Result
    {
        Result()
        {
            error = true;
            errorMessage = "Unknown error";
            value = "";
        }

        ~Result() { }

        bool error;
        std::string value;
        std::string errorMessage;
    };
};

#endif // TESSERACT_NATIVE_RESULT_H_
