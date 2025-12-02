#include "DynamicArray.h"
#include <iostream>
#include <stdexcept>
DynamicArray::DynamicArray() {
    this->capacity = 8;
    this->data = new float[this->capacity];
    this->size = -1;  
}

DynamicArray::DynamicArray(std::int64_t capacity) {
    if (capacity < 1) {
        throw std::invalid_argument("Capacity < 1");
    }
    this->capacity = capacity;
    this->data = new float[this->capacity];
    this->size = -1;  
}

DynamicArray::DynamicArray(DynamicArray& other) {
    this->size = other.size;
    this->capacity = other.capacity;
    this->data = new float[this->capacity];

    for (int i = 0; i <= size; ++i) { 
        this->data[i] = other.data[i];
    }
}

DynamicArray::~DynamicArray() {
    if (this->data) {
        delete[] this->data;
    }
}

void DynamicArray::push_back(float x) {
    if (size + 1 >= capacity) { 
        std::int64_t newCapacity = capacity * 2;
        float* tempArray = new float[newCapacity];
        for (int i = 0; i <= size; ++i) {
            tempArray[i] = data[i];
        }
        delete[] data;
        data = tempArray;
        capacity = newCapacity;
    }
    
    if (size == -1) {
        size = 0;
        data[0] = x;
    } else {
        data[++size] = x;
    }
}

void DynamicArray::pop_back() {
    if (size >= 0) {  
        --size;
    }
}
float DynamicArray::add(std::int64_t idx1, std::int64_t idx2) const {
    if (idx1 > size || idx2 > size || idx1 < 0 || idx2 < 0) {
        throw std::invalid_argument("idx1 or idx2 out of range");
    }
    return data[idx1] + data[idx2];
}

float DynamicArray::max() const {
    if (isEmpty()) {
        throw std::invalid_argument("Empty array");
    }
    float currentMax = -1e+38;
    for (int i = 0; i <= size; ++i) { 
        if (data[i] >= currentMax) {
            currentMax = data[i];
        }
    }
    return currentMax;
}

float DynamicArray::min() const {
    if (isEmpty()) {
        throw std::invalid_argument("Empty array");
    }
    float currentMin = 1e+38;
    for (int i = 0; i <= size; ++i) { 
        if (data[i] <= currentMin) {
            currentMin = data[i];
        }
    }
    return currentMin;
}

void DynamicArray::clear() {
    if (this->data) {
        delete[] this->data;
        this->data = nullptr;
    }
    size = -1;  
    capacity = 8;
}

void DynamicArray::reinitialize() {
    clear();
    data = new float[capacity];
}

void DynamicArray::printData() const {
    if (isEmpty()) {
        std::cout << "[Empty]" << std::endl;
        return;
    }
    for (int i = 0; i <= size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

float DynamicArray::operator[](std::int64_t idx) const {
    if (isEmpty() || idx < 0 || idx > size) { 
        throw std::invalid_argument("Out of range");
    }
    return data[size - idx]; 
}

float DynamicArray::operator()() const {
    if (isEmpty()) {
        return 0;
    }
    float sum = 0;
    for (int i = 0; i <= size; ++i) { 
        sum += data[i];
    }
    return sum;
}

bool DynamicArray::isEmpty() const {
    return size == -1;  
}

void DynamicArray::push_front(float val) {
    if (size + 1 >= capacity) {
        std::int64_t newCapacity = capacity * 2;
        float* tempArray = new float[newCapacity];
        
        tempArray[0] = val;
        for (int i = 0; i <= size; ++i) { 
            tempArray[i + 1] = data[i];
        }
        
        delete[] data;
        data = tempArray;
        capacity = newCapacity;
    } else {
        for (int i = size; i >= 0; --i) { 
            data[i + 1] = data[i];
        }
        data[0] = val;
    }
    
    ++size;
}

float DynamicArray::front() const {
    if (isEmpty()) {
        throw std::invalid_argument("Array is empty");
    }
    return data[0];
}

float DynamicArray::back() const {
    if (isEmpty()) {
        throw std::invalid_argument("Array is empty");
    }
    return data[size]; 
}

void DynamicArray::insert(std::int64_t idx, float val) {
    if (idx < 0 || idx > size + 1) { 
        throw std::invalid_argument("Index out of range");
    }
    
    if (size + 1 >= capacity) {
        std::int64_t newCapacity = capacity * 2;
        float* tempArray = new float[newCapacity];
        
        for (int i = 0; i < idx; ++i) {
            tempArray[i] = data[i];
        }
        
        tempArray[idx] = val;
        
        for (int i = idx; i <= size; ++i) { 
            tempArray[i + 1] = data[i];
        }
        
        delete[] data;
        data = tempArray;
        capacity = newCapacity;
    } else {
        for (int i = size; i >= idx; --i) { 
            data[i + 1] = data[i];
        }
        
        data[idx] = val;
    }
    
    ++size;
}

void DynamicArray::delete_element(std::int64_t idx) {
    if (isEmpty() || idx < 0 || idx > size) {
        throw std::invalid_argument("Index out of range or array is empty");
    }
    
    for (int i = idx; i < size; ++i) { 
        data[i] = data[i + 1];
    }
    
    --size;
    
    if (size >= 0 && size < capacity / 4 && capacity > 8) {
        decrease_capacity(capacity / 2);
    }
}

void DynamicArray::erase_after(std::int64_t idx) {
    if (idx < 0 || idx >= size) { 
        throw std::invalid_argument("Index out of range");
    }
    
    size = idx;
    
    if (size >= 0 && size < capacity / 4 && capacity > 8) {
        decrease_capacity(capacity / 2);
    }
}

void DynamicArray::increase_capacity(std::int64_t newCapacity) {
    if (newCapacity <= capacity) {
        throw std::invalid_argument("New capacity must be greater than current");
    }
    
    float* tempArray = new float[newCapacity];
    
    for (int i = 0; i <= size; ++i) { 
        tempArray[i] = data[i];
    }
    
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
}

void DynamicArray::decrease_capacity(std::int64_t newCapacity) {
    if (newCapacity >= capacity) {
        throw std::invalid_argument("New capacity must be less than current");
    }
    
    if (newCapacity <= size) {
        throw std::invalid_argument("New capacity must be greater than current size");
    }
    
    float* tempArray = new float[newCapacity];
    
    for (int i = 0; i <= size; ++i) { 
        tempArray[i] = data[i];
    }
    
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
}
