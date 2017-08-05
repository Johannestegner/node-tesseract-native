#include "../include/Api.h"
#include <leptonica/allheaders.h>

using namespace tesseract;
using namespace TesseractNative;

Result Api::Process(std::string filePath, const Options& options)
{
    return TesseractNative::Result();
}

Result Api::Process(const int** image, const Options& options)
{
    return TesseractNative::Result();
}

Result Api::Process(std::string filePath)
{
    TesseractNative::Result result;

    //Pix* image = pixRead(filePath.c_str());
    //tess->SetImage(image);
    //std::string out = tess->GetUTF8Text();
    //pixDestroy(&image);

    //TesseractNative::Result result;
    //result.error = false;
    //result.value = out;

    return result;
}

Result Api::Process(const int** image)
{
    return TesseractNative::Result();
}

Api::Api()
{


    this->tess = new TessBaseAPI();
    if(!this->tess->Init(nullptr, "eng")) {
        throw new std::exception();
    }
}

Api::~Api()
{
   // tess->End();
   // delete(tess);
   // tess = nullptr;
}

Api::Api(const Api &cpy)
{
    //this->tess = cpy.tess;
}
