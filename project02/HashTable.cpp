
// HashTable.cpp - Implementation of hash table with AVL chaining
// Author: Mia Tapia
// Date: 2025-07-11

#include "HashTable.h"
#include <iomanip>

// Constructor
HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = new AVLTree();
    }
}

// Destructor
HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        delete table[i];
    }
}

// Insert operation
void HashTable::insert(const std::string& key, const std::string& value) {
    int index = hashFunction(key);
    table[index]->insert(key, value);
}

// Search operation
std::string* HashTable::search(const std::string& key) {
    int index = hashFunction(key);
    return table[index]->search(key);
}

// Remove operation
void HashTable::remove(const std::string& key) {
    int index = hashFunction(key);
    table[index]->remove(key);
}

// Display operation
void HashTable::display() {
    std::cout << "\n=== Hash Table Statistics ===" << std::endl;
    std::cout << "Table Size: " << TABLE_SIZE << " buckets" << std::endl;
    std::cout << "Total Elements: " << getTotalElements() << std::endl;
    std::cout << "Non-empty Buckets: " << getNonEmptyBuckets() << std::endl;
    std::cout << "Load Factor: " << std::fixed << std::setprecision(3) << getLoadFactor() << std::endl;
    std::cout << "Average Bucket Size: " << std::fixed << std::setprecision(2) << getAverageBucketSize() << std::endl;
    std::cout << "Bucket Utilization: " << std::fixed << std::setprecision(1) 
              << (static_cast<double>(getNonEmptyBuckets()) / TABLE_SIZE * 100) << "%" << std::endl;
    std::cout << "=================================" << std::endl;
    
    // Show buckets with their sizes
    std::cout << "\n=== Bucket Contents ===" << std::endl;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!table[i]->isEmpty()) {
            std::cout << "\nBucket " << i << " (Size: " << getBucketSize(i) << "):" << std::endl;
            table[i]->display();
        }
    }
}

// Get bucket size (number of elements in a specific bucket)
int HashTable::getBucketSize(int index) const {
    if (index < 0 || index >= TABLE_SIZE) {
        return 0;
    }
    return table[index]->getSize();
}

// Calculate load factor
double HashTable::getLoadFactor() const {
    int totalElements = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        totalElements += table[i]->getSize();
    }
    return static_cast<double>(totalElements) / TABLE_SIZE;
}

// Get additional statistics
int HashTable::getTotalElements() const {
    int total = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        total += table[i]->getSize();
    }
    return total;
}

int HashTable::getNonEmptyBuckets() const {
    int count = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!table[i]->isEmpty()) {
            count++;
        }
    }
    return count;
}

double HashTable::getAverageBucketSize() const {
    int nonEmptyBuckets = getNonEmptyBuckets();
    if (nonEmptyBuckets == 0) return 0.0;
    return static_cast<double>(getTotalElements()) / nonEmptyBuckets;
} 