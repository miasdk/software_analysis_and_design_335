// MaxHeap.h - MaxHeap template class for priority queue
// Author: Mia Tapia
// Date: 2025-07-11

#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <vector>
#include <iostream>

template<typename T>
class MaxHeap {
private:
    std::vector<T> heap;
    
    // Helper functions
    int parent(int index) const { return (index - 1) / 2; }
    int leftChild(int index) const { return 2 * index + 1; }
    int rightChild(int index) const { return 2 * index + 2; }
    
    void heapifyUp(int index);
    void heapifyDown(int index);
    void swap(int index1, int index2);

public:
    MaxHeap() {}
    
    // Main operations
    void insert(const T& element);
    T deleteMax();
    T getMax() const;
    bool isEmpty() const { return heap.empty(); }
    int size() const { return heap.size(); }
    
    // Utility functions
    void display() const;
    void clear() { heap.clear(); }
};

// Template implementation
template<typename T>
void MaxHeap<T>::swap(int index1, int index2) {
    T temp = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = temp;
}

template<typename T>
void MaxHeap<T>::heapifyUp(int index) {
    while (index > 0 && heap[parent(index)] < heap[index]) {
        swap(index, parent(index));
        index = parent(index);
    }
}

template<typename T>
void MaxHeap<T>::heapifyDown(int index) {
    int maxIndex = index;
    int left = leftChild(index);
    int right = rightChild(index);
    
    if (left < static_cast<int>(heap.size()) && heap[left] > heap[maxIndex]) {
        maxIndex = left;
    }
    
    if (right < static_cast<int>(heap.size()) && heap[right] > heap[maxIndex]) {
        maxIndex = right;
    }
    
    if (index != maxIndex) {
        swap(index, maxIndex);
        heapifyDown(maxIndex);
    }
}

template<typename T>
void MaxHeap<T>::insert(const T& element) {
    heap.push_back(element);
    heapifyUp(heap.size() - 1);
}

template<typename T>
T MaxHeap<T>::deleteMax() {
    if (isEmpty()) {
        throw std::runtime_error("Heap is empty");
    }
    
    T maxElement = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    
    if (!isEmpty()) {
        heapifyDown(0);
    }
    
    return maxElement;
}

template<typename T>
T MaxHeap<T>::getMax() const {
    if (isEmpty()) {
        throw std::runtime_error("Heap is empty");
    }
    return heap[0];
}

template<typename T>
void MaxHeap<T>::display() const {
    std::cout << "MaxHeap contents:" << std::endl;
    for (size_t i = 0; i < heap.size(); i++) {
        std::cout << "[" << i << "]: " << heap[i] << std::endl;
    }
    std::cout << std::endl;
}

#endif // MAXHEAP_H 