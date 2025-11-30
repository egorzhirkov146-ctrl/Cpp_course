#include "stack.h"
#include <stdexcept>

Stack::Stack(std::int64_t maxSize) : maxSize(maxSize) {}

void Stack::push(float value) {
    if (array.getSize() >= maxSize) { 
        throw std::overflow_error("Stack overflow");
    }
    array.push_back(value);
}

float Stack::top() {
    if (array.isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return array.back();
}

float Stack::pop() {
    if (array.isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    float value = array.back();
    array.delete_element(array.getSize() - 1); 
    return value;
}

bool Stack::isEmpty() {
    return array.isEmpty();
}

std::int64_t Stack::size() {
    return array.getSize(); 
}

std::int64_t Stack::getMaxSize() {
    return maxSize;
}
