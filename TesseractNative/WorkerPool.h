#ifndef TESSERACT_NATIVE_WORKER_POOL_H_
#define TESSERACT_NATIVE_WORKER_POOL_H_
#include <vector>
#include "Worker.h"
#include <queue>
#include "Task.h"
#include <functional>
#include "Result.h"

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

        /**
         * Add a task to the queue.
         */
        const bool& Enqueue(const Task& task, const std::function<Result>& callback);


        WorkerPool(const WorkerPool&) = delete;
        void operator=(const WorkerPool&) = delete;

    private:

        /**
        * Struct to hold a task and the callback connected to it.
        */
        struct WorkerTask
        {
            WorkerTask(const Task& task, const std::function<Result>& callback)
                : task(task),
                  callback(callback)
            {
            }

            const Task& task;
            const std::function<Result>& callback;
        };

        std::vector<Worker> workers;
        std::queue<WorkerTask> tasks;

        WorkerPool();

    };

};

#endif // TESSERACT_NATIVE_WORKER_POOL_H_
