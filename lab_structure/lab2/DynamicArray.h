#ifndef DYN_ARR_H
#define DYN_ARR_H

#include <cstdint>

class DynamicArray {
private:
    float* data;
    std::int64_t size;
    std::int64_t capacity;

public:
    DynamicArray();
    DynamicArray(std::int64_t capacity);
    DynamicArray(DynamicArray& other);
    ~DynamicArray();

    void push_back(float x);
    void push_front(float val);
    void insert(std::int64_t idx, float val);
    void delete_element(std::int64_t idx);
    void erase_after(std::int64_t idx);
    
    float front();
    float back();
    float add(std::int64_t idx1, std::int64_t idx2);
    
    float max();
    float min();
    
    void clear();
    void reinitialize();
    void increase_capacity(std::int64_t newCapacity);
    void decrease_capacity(std::int64_t newCapacity);
    
    bool isEmpty();
    void printData();
    
    float operator[](std::int64_t idx);
    float operator()();
    std::int64_t getSize() const { return size; }
};

#endif
