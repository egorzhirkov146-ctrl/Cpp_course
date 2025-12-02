#ifndef DYN_ARR_H
#define DYN_ARR_H

#include <cstdint>

class DynamicArray {
private:
    float* data;
    std::int64_t size=-1;       
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
    void pop_back(); 
    float front() const;
    float back() const;
    float add(std::int64_t idx1, std::int64_t idx2) const;
    float max() const;
    float min() const;
    void clear();
    void reinitialize();
    void increase_capacity(std::int64_t newCapacity);
    void decrease_capacity(std::int64_t newCapacity);
    bool isEmpty() const;
    void printData() const;
    std::int64_t getSize() const { return size; }
    std::int64_t getCapacity() const { return capacity; }
    float operator[](std::int64_t idx) const;
    float operator()() const;
};

#endif 

