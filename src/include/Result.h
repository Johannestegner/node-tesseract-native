#ifndef TESSERACT_NATIVE_RESULT_H
#define TESSERACT_NATIVE_RESULT_H

#include <iostream>

namespace TesseractNative
{
    /**
     * Result structure which is returned from any Api.Process calls.
     * Either contains the string value of the processed image or an
     * error message.
     * In case of error, the `error` boolean member will be set to true.
     */
    class Result
    {
    public:
        Result();
        ~Result() = default;


        bool error;
        std::string value;
        std::string errorMessage;
    };
};



#endif //TESSERACT_NATIVE_RESULT_H
