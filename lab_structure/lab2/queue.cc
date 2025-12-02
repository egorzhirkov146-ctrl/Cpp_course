#include "queue.h"
template<typename T>
Queue<T>::Queue(std::int64_t max_size) 
    : input_stack(max_size), output_stack(max_size) {}

template<typename T>
void Queue<T>::enqueue(const T& value) {
    checkOverflow();
    input_stack.push(value);
}

template<typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    if (output_stack.isEmpty()) {
        transferElements();
    }
    
    return output_stack.pop();
}

template<typename T>
bool Queue<T>::isEmpty() const {
    return input_stack.isEmpty() && output_stack.isEmpty();
}

template<typename T>
std::int64_t Queue<T>::size() const {
    return input_stack.size() + output_stack.size();
}

template<typename T>
T Queue<T>::front() const {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }

    if (output_stack.isEmpty()) {
        Queue<T>* non_const_this = const_cast<Queue<T>*>(this);
        non_const_this->transferElements();
    }
    
    return output_stack.top();
}

template<typename T>
std::int64_t Queue<T>::getMaxSize() const {
    return input_stack.getMaxSize();
}

template<typename T>
void Queue<T>::transferElements() {
    while (!input_stack.isEmpty()) {
        output_stack.push(input_stack.pop());
    }
}

template<typename T>
void Queue<T>::checkOverflow() const {
    if (size() >= getMaxSize()) {
        throw std::overflow_error("Queue overflow: maximum size reached");
    }
}

template class Queue<int>;
template class Queue<float>;
template class Queue<double>;
template class Queue<char>;
template class Queue<long>;
template class Queue<short>;
