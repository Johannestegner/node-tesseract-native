#ifndef TESSERACT_NATIVE_WORKER_POOL_H_
#define TESSERACT_NATIVE_WORKER_POOL_H_
#include <vector>
#include "Worker.h"

namespace TesseractNative
{
    /**
     * Worker pool singleton.
     * 
     * Worker pool takes holds the workers and delegates
     * the tasks to any available worker.
     * If no available worker, it will wait til one is and then 
     * delegate the task in a first in first out manner (if not higher prioritised).
     */
    class WorkerPool
    {
    public:

        /**
         * Get the worker pool instance.
         */
        static WorkerPool& GetInstance()
        {
            static WorkerPool instance;
            return instance;
        }


        WorkerPool(const WorkerPool&) = delete;
        void operator=(const WorkerPool&) = delete;

    private:
        std::vector<Worker*> workers;
        WorkerPool();
    };

};

#endif // TESSERACT_NATIVE_WORKER_POOL_H_
