#ifndef STACK_H
#define STACK_H

#include "DynamicArray.h"
#include <stdexcept>

template<typename T>
class Stack {
private:
    DynamicArray array;
    std::int64_t max_size;
    
public:
    explicit Stack(std::int64_t max_size);

    void push(const T& value);
    T top() const;
    T pop();
    bool isEmpty() const;
    
    std::int64_t size() const;
    std::int64_t getMaxSize() const;
    bool isFull() const;
    
private:
    void checkOverflow() const;
    float convertToFloat(const T& value) const;
    T convertFromFloat(float value) const;
};

#endif 

