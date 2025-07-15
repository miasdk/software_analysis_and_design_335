// HashTable.h - Hash table with AVL tree chaining
// Author: Mia Tapia
// Date: 2025-07-11

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "AVLTree.h"
#include <string>
#include <iostream>
#include <functional>

class HashTable {
private:
    static const int TABLE_SIZE = 101; // Prime number for better distribution
    AVLTree* table[TABLE_SIZE];
    
    // Hash function using std::hash
    int hashFunction(const std::string& key) const {
        std::hash<std::string> hasher;
        return hasher(key) % TABLE_SIZE;
    }

public:
    // Constructor
    HashTable();
    
    // Destructor
    ~HashTable();
    
    // Main operations
    void insert(const std::string& key, const std::string& value);
    std::string* search(const std::string& key);
    void remove(const std::string& key);
    void display();
    
    // Utility functions
    int getTableSize() const { return TABLE_SIZE; }
    int getBucketSize(int index) const;
    double getLoadFactor() const;
    int getTotalElements() const;
    int getNonEmptyBuckets() const;
    double getAverageBucketSize() const;
};

#endif // HASHTABLE_H 