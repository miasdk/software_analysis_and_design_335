// AVLTree.cpp - Implementation of AVL Tree
// Author: Mia Tapia
// Date: 2025-07-11
#include "AVLTree.h"
#include <algorithm>
#include <iomanip>

// Destructor
AVLTree::~AVLTree() {
    destroyTree(root);
}

// Helper function to destroy the tree
void AVLTree::destroyTree(AVLNode* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

// Get height of a node
int AVLTree::getHeight(AVLNode* node) {
    if (node == nullptr) return 0;
    return node->height;
}

// Get balance factor
int AVLTree::getBalanceFactor(AVLNode* node) {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Right rotation
AVLNode* AVLTree::rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    
    // Perform rotation
    x->right = y;
    y->left = T2;
    
    // Update heights
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    
    return x;
}

// Left rotation
AVLNode* AVLTree::leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    
    // Perform rotation
    y->left = x;
    x->right = T2;
    
    // Update heights
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    
    return y;
}

// Insert helper function
AVLNode* AVLTree::insertHelper(AVLNode* node, const std::string& key, const std::string& value) {
    // Standard BST insert
    if (node == nullptr) {
        return new AVLNode(key, value);
    }
    
    if (key < node->key) {
        node->left = insertHelper(node->left, key, value);
    } else if (key > node->key) {
        node->right = insertHelper(node->right, key, value);
    } else {
        // Key already exists, update value
        node->value = value;
        return node;
    }
    
    // Update height of current node
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    
    // Get balance factor
    int balance = getBalanceFactor(node);
    
    // Left Left Case
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }
    
    // Right Right Case
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }
    
    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}

// Public insert function
void AVLTree::insert(const std::string& key, const std::string& value) {
    // Check if key already exists
    AVLNode* existing = searchHelper(root, key);
    if (existing != nullptr) {
        existing->value = value;  // update existing
        return;
    }
    
    root = insertHelper(root, key, value);
    size_++;
}

// Find minimum node
AVLNode* AVLTree::findMin(AVLNode* node) {
    if (node == nullptr || node->left == nullptr) {
        return node;
    }
    return findMin(node->left);
}

// Delete helper function
AVLNode* AVLTree::deleteHelper(AVLNode* root, const std::string& key) {
    if (root == nullptr) {
        return root;
    }
    
    if (key < root->key) {
        root->left = deleteHelper(root->left, key);
    } else if (key > root->key) {
        root->right = deleteHelper(root->right, key);
    } else {
        // Node to be deleted found
        
        // Node with only one child or no child
        if (root->left == nullptr || root->right == nullptr) {
            AVLNode* temp = root->left ? root->left : root->right;
            
            // No child case
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                // One child case
                *root = *temp;
            }
            delete temp;
        } else {
            // Node with two children: Get the inorder successor (smallest in right subtree)
            AVLNode* temp = findMin(root->right);
            
            // Copy the inorder successor's data to this node
            root->key = temp->key;
            root->value = temp->value;
            
            // Delete the inorder successor
            root->right = deleteHelper(root->right, temp->key);
        }
    }
    
    // If the tree had only one node then return
    if (root == nullptr) {
        return root;
    }
    
    // Update height of current node
    root->height = std::max(getHeight(root->left), getHeight(root->right)) + 1;
    
    // Get balance factor
    int balance = getBalanceFactor(root);
    
    // Left Left Case
    if (balance > 1 && getBalanceFactor(root->left) >= 0) {
        return rightRotate(root);
    }
    
    // Left Right Case
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    // Right Right Case
    if (balance < -1 && getBalanceFactor(root->right) <= 0) {
        return leftRotate(root);
    }
    
    // Right Left Case
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}

// Public remove function
void AVLTree::remove(const std::string& key) {
    AVLNode* existing = searchHelper(root, key);
    if (existing != nullptr) {
        root = deleteHelper(root, key);
        size_--;
    }
}

// Search helper function
AVLNode* AVLTree::searchHelper(AVLNode* node, const std::string& key) {
    if (node == nullptr || node->key == key) {
        return node;
    }
    
    if (key < node->key) {
        return searchHelper(node->left, key);
    }
    
    return searchHelper(node->right, key);
}

// Public search function
std::string* AVLTree::search(const std::string& key) {
    AVLNode* result = searchHelper(root, key);
    return (result != nullptr) ? &(result->value) : nullptr;
}

// Display helper function
void AVLTree::displayHelper(AVLNode* node, int level) {
    if (node != nullptr) {
        displayHelper(node->right, level + 1);
        std::cout << std::setw(level * 4) << "" << node->key << " -> " << node->value << std::endl;
        displayHelper(node->left, level + 1);
    }
}

// Public display function
void AVLTree::display() {
    if (root == nullptr) {
        std::cout << "Empty tree" << std::endl;
        return;
    }
    std::cout << "AVL Tree (in-order):" << std::endl;
    displayHelper(root, 0);
} 