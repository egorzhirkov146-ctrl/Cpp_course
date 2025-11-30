#include "DynamicArray.h"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>

DynamicArray::DynamicArray() {
  this->capacity = 8;
  this->data = new float[this->capacity];
  this->size = 0; 
}

DynamicArray::DynamicArray(std::int64_t capacity) {
  if (capacity < 1) {
    throw std::invalid_argument("Capacity < 1");
  }
  this->capacity = capacity;
  this->data = new float[this->capacity];
  this->size = 0; 
}

DynamicArray::DynamicArray(DynamicArray& other) {
  this->size = other.size;
  this->capacity = other.capacity;
  this->data = new float[this->capacity];

  for (int i = 0; i < size; ++i) { 
    this->data[i] = other.data[i];
  }
}

DynamicArray::~DynamicArray() {
  if (this->data) {
    delete[] this->data;
  }
}

void DynamicArray::push_back(float x) {
  if (size >= capacity) { 
    std::int64_t newCapacity = capacity * 2;
    float* tempArray = new float[newCapacity];
    for (int i = 0; i < size; ++i) {
      tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  }
  data[size] = x; 
  size++;         
}

float DynamicArray::add(std::int64_t idx1, std::int64_t idx2) {
  if (idx1 >= size || idx2 >= size || idx1 < 0 || idx2 < 0) {
    throw std::invalid_argument("idx1 or idx2 out of range");
  }
  return data[idx1] + data[idx2];
}

float DynamicArray::max() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  float currentMax = -1e+38;
  for (int i = 0; i < size; ++i) { 
    if (data[i] >= currentMax) {
      currentMax = data[i];
    }
  }
  return currentMax;
}

float DynamicArray::min() {
  if (isEmpty()) {
    throw std::invalid_argument("Empty array");
  }
  float currentMin = 1e+38;
  for (int i = 0; i < size; ++i) { 
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
  size = 0; 
  capacity = 8;
}

void DynamicArray::reinitialize() {
  clear();
  data = new float[capacity]();
}

void DynamicArray::printData() {
  if (isEmpty()) {
    return;
  }
  for (int i = 0; i < size; ++i) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
}

float DynamicArray::operator[](std::int64_t idx) {
  if (isEmpty() || idx < 0 || idx >= size) { 
    throw std::invalid_argument("Out of range");
  }
  return data[idx]; 
}

float DynamicArray::operator()() {
  if (isEmpty()) {
    return 0;
  }
  float sum = 0;
  for (int i = 0; i < size; ++i) { 
    sum += data[i];
  }
  return sum;
}

void DynamicArray::push_front(float val) {
    if (size >= capacity) {
        std::int64_t newCapacity = capacity * 2;
        float* tempArray = new float[newCapacity];
        
        for (int i = 0; i < size; ++i) { 
            tempArray[i + 1] = data[i];
        }
        
        delete[] data;
        data = tempArray;
        capacity = newCapacity;
    } else {
        for (int i = size - 1; i >= 0; --i) { 
            data[i + 1] = data[i];
        }
    }
    
    data[0] = val;
    size++;
}

float DynamicArray::front() {
    if (isEmpty()) {
        throw std::invalid_argument("Array is empty");
    }
    return data[0];
}

float DynamicArray::back() {
    if (isEmpty()) {
        throw std::invalid_argument("Array is empty");
    }
    return data[size - 1]; 
}

void DynamicArray::insert(std::int64_t idx, float val) {
    if (idx < 0 || idx > size) { 
        throw std::invalid_argument("Index out of range");
    }
    
    if (size >= capacity) {
        std::int64_t newCapacity = capacity * 2;
        float* tempArray = new float[newCapacity];
        
        for (int i = 0; i < idx; ++i) {
            tempArray[i] = data[i];
        }
        
        tempArray[idx] = val;
        
        for (int i = idx; i < size; ++i) { 
            tempArray[i + 1] = data[i];
        }
        
        delete[] data;
        data = tempArray;
        capacity = newCapacity;
    } else {
        for (int i = size - 1; i >= idx; --i) { 
            data[i + 1] = data[i];
        }
        
        data[idx] = val;
    }
    
    size++;
}

void DynamicArray::delete_element(std::int64_t idx) {
    if (isEmpty() || idx < 0 || idx >= size) {
        throw std::invalid_argument("Index out of range or array is empty");
    }
    
    for (int i = idx; i < size - 1; ++i) { 
        data[i] = data[i + 1];
    }
    
    size--;
    
    if (size < capacity / 4 && capacity > 8) {
        decrease_capacity(capacity / 2);
    }
}

void DynamicArray::erase_after(std::int64_t idx) {
    if (idx < 0 || idx >= size - 1) { 
        throw std::invalid_argument("Index out of range");
    }
    
    size = idx + 1; 
    
    if (size < capacity / 4 && capacity > 8) {
        decrease_capacity(capacity / 2);
    }
}

void DynamicArray::increase_capacity(std::int64_t newCapacity) {
    if (newCapacity <= capacity) {
        throw std::invalid_argument("New capacity must be greater than current");
    }
    
    float* tempArray = new float[newCapacity];
    
    for (int i = 0; i < size; ++i) { 
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
    
    if (newCapacity < size) {
        throw std::invalid_argument("New capacity must be greater than current size");
    }
    
    float* tempArray = new float[newCapacity];
    
    for (int i = 0; i < size; ++i) { 
        tempArray[i] = data[i];
    }
    
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
}

bool DynamicArray::isEmpty() {
    return size == 0; 
}
