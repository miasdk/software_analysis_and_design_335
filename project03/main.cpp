// main.cpp - Customer service simulation with priority queue
// Author: Mia Tapia
// Date: 2025-07-11

#include "MaxHeap.h"
#include "Customer.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

class CustomerServiceSimulation {
private:
    MaxHeap<Customer> customerQueue;
    std::vector<Customer> history;
    
    // Generate random customers
    void generateCustomers(int numCustomers) {
        std::cout << "Generating " << numCustomers << " customers..." << std::endl;
        for (int i = 0; i < numCustomers; i++) {
            Customer customer;
            customerQueue.insert(customer);
        }
        std::cout << "Customers queued by priority!" << std::endl;
    }
    
    // Serve all customers
    void serveCustomers() {
        std::cout << "\n=== Serving Customers ===" << std::endl;
        int customerNumber = 1;
        
        while (!customerQueue.isEmpty()) {
            Customer customer = customerQueue.deleteMax();
            customer.setServiceTime();
            
            std::cout << "Customer #" << customerNumber << ": " << customer.getName() 
                      << " (Priority: " << customer.getPriorityLevel() << ")" << std::endl;
            std::cout << "Service time: " << customer.getServiceTime() << " minutes" << std::endl;
            
            history.push_back(customer);
            customerNumber++;
        }
        
        std::cout << "All customers served!" << std::endl;
    }
    
    // Sort and display history
    void displayHistory() {
        std::cout << "\n=== Customer History (Sorted by Service Time) ===" << std::endl;
        
        std::sort(history.begin(), history.end(), 
                  [](const Customer& a, const Customer& b) {
                      return a.getServiceTime() < b.getServiceTime();
                  });
        
        std::cout << "Rank  Customer Name           Priority    Service Time" << std::endl;
        std::cout << "------------------------------------------------" << std::endl;
        
        for (size_t i = 0; i < history.size(); i++) {
            std::cout << (i + 1) << "     " << history[i].getName() 
                      << "    " << history[i].getPriorityLevel()
                      << "    " << history[i].getServiceTime() << " min" << std::endl;
        }
        
        calculateStatistics();
    }
    
    // Calculate and display statistics
    void calculateStatistics() {
        if (history.empty()) {
            std::cout << "No customers to analyze." << std::endl;
            return;
        }
        
        int totalServiceTime = 0;
        int minServiceTime = history[0].getServiceTime();
        int maxServiceTime = history[0].getServiceTime();
        int totalPriority = 0;
        
        for (const Customer& customer : history) {
            int serviceTime = customer.getServiceTime();
            totalServiceTime += serviceTime;
            minServiceTime = std::min(minServiceTime, serviceTime);
            maxServiceTime = std::max(maxServiceTime, serviceTime);
            totalPriority += customer.getPriorityLevel();
        }
        
        double avgServiceTime = static_cast<double>(totalServiceTime) / history.size();
        double avgPriority = static_cast<double>(totalPriority) / history.size();
        
        std::cout << "\n=== Stats ===" << std::endl;
        std::cout << "Total: " << history.size() << std::endl;
        std::cout << "Avg time: " << std::fixed << std::setprecision(1) 
                  << avgServiceTime << " min" << std::endl;
        std::cout << "Min time: " << minServiceTime << " min" << std::endl;
        std::cout << "Max time: " << maxServiceTime << " min" << std::endl;
        std::cout << "Avg priority: " << std::fixed << std::setprecision(1) 
                  << avgPriority << std::endl;
    }

public:
    void runSimulation() {
        std::cout << "=== Customer Service Simulation ===" << std::endl;
        std::cout << "Priority queue using MaxHeap" << std::endl;
        std::cout << "Customers have random priority (0-100)" << std::endl;
        std::cout << "Higher priority served first" << std::endl;
        std::cout << "================================" << std::endl;
        
        int numCustomers;
        std::cout << "\nEnter number of customers (default: 10): ";
        std::string input;
        std::getline(std::cin, input);
        
        if (input.empty()) {
            numCustomers = 10;
        } else {
            numCustomers = std::stoi(input);
        }
        
        generateCustomers(numCustomers);
        serveCustomers();
        displayHistory();
        
        std::cout << "\nSimulation complete!" << std::endl;
    }
};

int main() {
    CustomerServiceSimulation simulation;
    simulation.runSimulation();
    return 0;
} 