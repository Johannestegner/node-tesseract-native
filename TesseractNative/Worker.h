#ifndef TESSERACT_NATIVE_WORKER_H_
#define TESSERACT_NATIVE_WORKER_H_
#include "Task.h"

namespace TesseractNative
{

    /**
     * Worker class.
     * 
     * Each individual worker instance takes care of executing a given job.
     * Each worker will work on a thread of its own, making it possible to execute multiple OCR jobs at once.
     */
    class Worker
    {
    public:
        /**
         * Working class hero.
         */
        Worker(const unsigned int& id);

        ~Worker();

        /**
         * Get the workers application-unique id.
         */
        __inline const long& GetId() const { return this->identity; }
        
        /**
         * Check if the worker is currently in "active" state, i.e., working.
         * 
         * @alias IsWorking
         */
        __inline const bool& IsActive() const { return this->active; }

        /**
         * Check if the worker is currently working.
         * 
         * @alias IsActive
         */
        __inline const bool& IsWorking() const { return this->IsActive(); }

    private:

        unsigned int identity;
        bool active;
        Task* task;
    };

};

#endif // TESSERACT_NATIVE_WORKER_H_
