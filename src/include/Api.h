#ifndef TESSERACT_NATIVE_API_H_
#define TESSERACT_NATIVE_API_H_

#include "TesseractOptions.h"
#include <string>
#include "Result.h"
#include <tesseract/baseapi.h>

/**
 * Public API.
 * This API is what is supposed to be exposed to node.js.
 * Everything public in the class should be seen as exposed, even if it is not.
 */
class Api
{
public:
    Api();
    Api(const Api& cpy);
    ~Api();



    /**
     * Process image from file path.
     * @param filePath Path to the file to process.
     * @param options Options to use.
     */
    TesseractNative::Result Process(std::string filePath, const TesseractNative::Options& options);

    /**
     * Process image from data.
     * @param image 2D integer array with image data. (for now, this will change...)
     * @param options Options to use.
     */
    TesseractNative::Result Process(const int** image, const TesseractNative::Options& options);

    /**
    * Process image from file path.
    * @param filePath Path to the file to process.
    */
    TesseractNative::Result Process(std::string filePath);

    /**
    * Process image from data.
    * @param image 2D integer array with image data. (for now, this will change...)
    */
    TesseractNative::Result Process(const int** image);

private:
    tesseract::TessBaseAPI* tess;

};

#endif // TESSERACT_NATIVE_API_H_
