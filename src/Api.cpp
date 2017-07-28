#include "Api.h"
#include "Result.h"

#include <iostream>
#include <memory>
#include <allheaders.h>

#include <baseapi.h>

using namespace tesseract;

TesseractNative::Result Api::Process(std::string filePath, const TesseractNative::Options& options)
{
    return TesseractNative::Result();
}

TesseractNative::Result Api::Process(const int** image, const TesseractNative::Options& options)
{
    return TesseractNative::Result();
}

TesseractNative::Result Api::Process(std::string filePath)
{

    return TesseractNative::Result{};

}

TesseractNative::Result Api::Process(const int** image)
{
    return TesseractNative::Result();
}

Api::Api()
{


}
