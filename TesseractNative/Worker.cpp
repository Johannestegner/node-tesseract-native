#include "Worker.h"

TesseractNative::Worker::Worker(const unsigned int& id)
{
    active = false;
    identity = id;
    task = nullptr;
}

TesseractNative::Worker::~Worker()
{
    task = nullptr;
}
