#include "../include/Result.h"

TesseractNative::Result::Result()
{
    this->error = true;
    this->errorMessage = "Unknown error";
    this->value = "";
}

