#include "WorkerPool.h"

TesseractNative::WorkerPool::WorkerPool()
{
    // TODO: Not magic number for cores.

    for (unsigned int i=4;i-->0;)
    {
        workers.push_back(Worker{
            i
        });
    }

}

const bool& TesseractNative::WorkerPool::Enqueue(const Task& task, const std::function<Result>& callback)
{
    this->tasks.push(WorkerTask(
        task, callback
    ));
}

