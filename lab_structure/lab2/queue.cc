#include "queue.h"

void Queue::transitElements() {
    while (!StackIn.isEmpty()) {
        StackOut.push(StackIn.pop());
    }
}

Queue::Queue(std::int64_t maxSize) : StackIn(maxSize), StackOut(maxSize) {}

void Queue::enqueue(float value) {
    StackIn.push(value);
}

float Queue::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    if (StackOut.isEmpty()) {
        transitElements();
    }
    return StackOut.pop();
}

bool Queue::isEmpty() {
    return StackIn.isEmpty() && StackOut.isEmpty();
}

std::int64_t Queue::size() {
    return StackIn.size() + StackOut.size();
}
