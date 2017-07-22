#ifndef TESSERACT_NATIVE_API_H_
#define TESSERACT_NATIVE_API_H_

#include "TesseractOptions.h"

/**
 * Public API.
 * This API is what is supposed to be exposed to node.js.
 * Everything public in the class should be seen as exposed, even if it is not.
 */
class Api
{
public:

    /**
     * Get the single API instance.
     * Using singleton pattern.
     */
    __inline static const Api& GetInstance()
    {
        static Api api;
        return api;
    }

    /**
     * Process image from file path.
     * @param filePath Path to the file to process.
     * @param options Options to use.
     */
    const char* Process(const char* filePath, const TesseractNative::Options& options);

    /**
     * Process image from data.
     * @param image 2D integer array with image data. (for now, this will change...)
     * @param options Options to use.
     */
    const char* Process(const int** image, const TesseractNative::Options& options);

    /**
    * Process image from file path.
    * @param filePath Path to the file to process.
    */
    const char* Process(const char* filePath);

    /**
    * Process image from data.
    * @param image 2D integer array with image data. (for now, this will change...)
    */
    const char* Process(const int** image);

private:

    Api(const Api&) = delete;
    void operator=(const Api&) = delete;

    Api();
};

#endif // TESSERACT_NATIVE_API_H_
