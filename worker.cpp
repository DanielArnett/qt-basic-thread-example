#include "worker.h"

Worker::Worker()
{
    this->input = 0;
}
void Worker::run()
{
    while(true)
    {
        if (haltFlag)
        {
            haltFlag = false;
            break;
        }
        inputMutex.lock();
        if (MaxInt <= this->input) {

            this->input = 0;
        }
        this->input++;
        inputMutex.unlock();
    }
}

void Worker::setInput(int newInput = 0)
{
    if (0 <= newInput && newInput <= this->MaxInt)
    {
        this->inputMutex.lock();
        this->input = newInput;
        this->inputMutex.unlock();
    }
}

int Worker::getInput()
{
    return this->input;
}

void Worker::stop()
{
    this->haltFlag = true;
}
