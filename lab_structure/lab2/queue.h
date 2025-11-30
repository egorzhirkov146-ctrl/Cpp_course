#ifndef QUEUE_H
#define QUEUE_H

#include "stack.h"
#include <stdexcept>

class Queue {
private:
    Stack StackIn;
    Stack StackOut;
    void transitElements();

public:
    Queue(std::int64_t maxSize);
    void enqueue(float value);
    float dequeue();
    bool isEmpty();
    std::int64_t size();
};

#endif
