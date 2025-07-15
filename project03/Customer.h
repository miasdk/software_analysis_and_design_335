// Customer.h - Customer class for priority queue simulation
// Author: Mia Tapia
// Date: 2025-07-11

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Customer {
private:
    std::string name_;
    int service_time_;
    int priority_level_;
    
    // Generate random names
    std::string generateRandomName() const;

public:
    // Constructor
    Customer();
    Customer(const std::string& name);
    
    // Getters
    std::string getName() const { return name_; }
    int getServiceTime() const { return service_time_; }
    int getPriorityLevel() const { return priority_level_; }
    
    // Setters
    void setPriorityLevel();
    void setServiceTime();
    
    // Comparison operator for MaxHeap (compare by priority level)
    bool operator<(const Customer& other) const {
        return priority_level_ < other.priority_level_;
    }
    
    bool operator>(const Customer& other) const {
        return priority_level_ > other.priority_level_;
    }
    
    // Output operator for display
    friend std::ostream& operator<<(std::ostream& os, const Customer& customer);
};

#endif // CUSTOMER_H 