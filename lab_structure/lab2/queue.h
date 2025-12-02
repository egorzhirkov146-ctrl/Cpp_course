#ifndef QUEUE_H
#define QUEUE_H

#include "stack.h"
#include <stdexcept>

template<typename T>
class Queue {
private:
    Stack<T> input_stack;   
    Stack<T> output_stack; 
    void transferElements(); 
    
public:
    Queue(std::int64_t max_size);
    void enqueue(const T& value);
    T dequeue();
    bool isEmpty() const;
    std::int64_t size() const;
    T front() const;
    std::int64_t getMaxSize() const;
private:
    void checkOverflow() const;
};

#endif
