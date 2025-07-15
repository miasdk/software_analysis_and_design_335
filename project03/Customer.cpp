// Customer.cpp - Customer class implementation
// Author: Mia Tapia
// Date: 2025-07-11

#include "Customer.h"
#include <algorithm>

// Static initialization for random number generation
static bool randomInitialized = false;

Customer::Customer() {
    if (!randomInitialized) {
        std::srand(std::time(nullptr));
        randomInitialized = true;
    }
    
    name_ = generateRandomName();
    service_time_ = 0; // Will be set when customer is served
    setPriorityLevel(); // Set priority in constructor
}

Customer::Customer(const std::string& name) {
    if (!randomInitialized) {
        std::srand(std::time(nullptr));
        randomInitialized = true;
    }
    
    name_ = name;
    service_time_ = 0; // Will be set when customer is served
    setPriorityLevel(); // Set priority in constructor
}

std::string Customer::generateRandomName() const {
    // Simple name generation
    static const std::vector<std::string> firstNames = {
        "Alice", "Bob", "Charlie", "Diana", "Eve", "Frank", "Grace", "Henry",
        "Ivy", "Jack", "Kate", "Liam", "Mia", "Noah", "Olivia", "Paul"
    };
    
    static const std::vector<std::string> lastNames = {
        "Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller",
        "Davis", "Rodriguez", "Martinez", "Hernandez", "Lopez", "Gonzalez"
    };
    
    std::string firstName = firstNames[std::rand() % firstNames.size()];
    std::string lastName = lastNames[std::rand() % lastNames.size()];
    
    return firstName + " " + lastName;
}

void Customer::setPriorityLevel() {
    // Generate random priority between 0 and 100
    priority_level_ = std::rand() % 101;
}

void Customer::setServiceTime() {
    // Generate random service time between 0 and 60 minutes
    service_time_ = std::rand() % 61;
}

std::ostream& operator<<(std::ostream& os, const Customer& customer) {
    os << "Customer: " << customer.name_ 
       << " | Priority: " << customer.priority_level_
       << " | Service Time: " << customer.service_time_ << " minutes";
    return os;
} 