#include "stack.h"
#include <type_traits>


template<typename T>
Stack<T>::Stack(std::int64_t max_size) : max_size(max_size) {
    if (max_size <= 0) {
        throw std::invalid_argument("Stack size must be positive");
    }
}

template<typename T>
float Stack<T>::convertToFloat(const T& value) const {
    return static_cast<float>(value);
}

template<typename T>
T Stack<T>::convertFromFloat(float value) const {
    return static_cast<T>(value);
}

template<typename T>
void Stack<T>::push(const T& value) {
    checkOverflow();
    array.push_back(convertToFloat(value));
}

template<typename T>
T Stack<T>::top() const {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return convertFromFloat(array[0]);
}

template<typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    T value = top();
    array.pop_back();
    return value;
}

template<typename T>
bool Stack<T>::isEmpty() const {
    return array.isEmpty();
}

template<typename T>
bool Stack<T>::isFull() const {
    return size() >= max_size;
}

template<typename T>
std::int64_t Stack<T>::size() const {
    return array.getSize() + 1;
}

template<typename T>
std::int64_t Stack<T>::getMaxSize() const {
    return max_size;
}

template<typename T>
void Stack<T>::checkOverflow() const {
    if (isFull()) {
        throw std::overflow_error("Stack overflow: maximum size reached");
    }
}

template class Stack<int>;
template class Stack<float>;
template class Stack<double>;
template class Stack<char>;
template class Stack<long>;
template class Stack<short>;
