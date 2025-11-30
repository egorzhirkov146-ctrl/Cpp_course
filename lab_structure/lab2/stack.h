#ifndef STACK_H
#define STACK_H

#include "DynamicArray.h"
#include <stdexcept>

class Stack {
private:
    DynamicArray array;
    std::int64_t maxSize;

public:
    Stack(std::int64_t maxSize = 100);
    void push(float value);
    float top();
    float pop();
    bool isEmpty();
    std::int64_t size();
    std::int64_t getMaxSize();
};

#endif
