#include "Api.h"
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
    Pix* image = pixRead(filePath.c_str());
    tess->SetImage(image);
    std::string out = tess->GetUTF8Text();
    pixDestroy(&image);

    TesseractNative::Result result;
    result.error = false;
    result.value = out;

    return result;

}

TesseractNative::Result Api::Process(const int** image)
{
    return TesseractNative::Result();
}

Api::Api()
{
    this->tess = new tesseract::TessBaseAPI();
    this->tess->Init(nullptr, "eng");

}
