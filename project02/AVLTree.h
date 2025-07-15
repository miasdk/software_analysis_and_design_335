/**
 * @file AVLTree.cpp
 * @author Mia Tapia 
 * @brief Declaration of the AVLTree class
 * @date 2025-07-11
 * @copyright Copyright (c) 2025
 */
// AVLTree.h - AVL Tree implementation for hash table chaining
// Author: Mia Tapia
// Date: 2025-07-11

#ifndef AVLTREE_H
#define AVLTREE_H

#include <string>
#include <iostream>

// AVL Tree Node Structure
struct AVLNode {
    std::string key;
    std::string value;
    AVLNode* left;
    AVLNode* right;
    int height;
    
    AVLNode(const std::string& k, const std::string& v) 
        : key(k), value(v), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;
    int size_;
    
    // Helper functions
    int getHeight(AVLNode* node);
    int getBalanceFactor(AVLNode* node);
    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* x);
    AVLNode* insertHelper(AVLNode* node, const std::string& key, const std::string& value);
    AVLNode* findMin(AVLNode* node);
    AVLNode* deleteHelper(AVLNode* root, const std::string& key);
    AVLNode* searchHelper(AVLNode* node, const std::string& key);
    void displayHelper(AVLNode* node, int level);
    void destroyTree(AVLNode* node);

public:
    AVLTree() : root(nullptr), size_(0) {}
    ~AVLTree();
    
    // Main operations
    void insert(const std::string& key, const std::string& value);
    std::string* search(const std::string& key);
    void remove(const std::string& key);
    void display();
    bool isEmpty() const { return root == nullptr; }
    int getSize() const { return size_; }
};

#endif // AVLTREE_H 