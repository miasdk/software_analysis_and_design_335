// main.cpp - Library catalog system using hash table
// Author: Mia Tapia
// Date: 2025-07-11

#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class LibraryCatalog {
private:
    HashTable hashTable;
    
    // Parse CSV line
    void parseBookData(const std::string& line, std::string& title, std::string& author, std::string& genre) {
        std::istringstream iss(line);
        
        std::getline(iss, title, ',');
        std::getline(iss, author, ',');
        std::getline(iss, genre, ',');
        
        // Basic trim
        title.erase(0, title.find_first_not_of(" \t"));
        author.erase(0, author.find_first_not_of(" \t"));
        genre.erase(0, genre.find_first_not_of(" \t"));
    }

public:
    // Load books from file
    bool loadBooksFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cout << "Error: Could not open file " << filename << std::endl;
            return false;
        }
        
        std::string line;
        int count = 0;
        
        while (std::getline(file, line)) {
            if (!line.empty()) {
                std::string title, author, genre;
                parseBookData(line, title, author, genre);
                
                std::string value = author + " - " + genre;
                hashTable.insert(title, value);
                count++;
            }
        }
        
        file.close();
        std::cout << "Loaded " << count << " books from " << filename << std::endl;
        return true;
    }
    
    // Search for a book by title
    void searchBook(const std::string& title) {
        std::string* result = hashTable.search(title);
        if (result != nullptr) {
            std::cout << "\nFound: " << title << std::endl;
            std::cout << "Info: " << *result << std::endl;
        } else {
            std::cout << "\nNot found: " << title << std::endl;
        }
    }
    
    // Display the hash table
    void displayHashTable() {
        hashTable.display();
    }
    
    // User menu
    void runMenu() {
        int choice;
        std::string filename, searchTitle;
        
        do {
            std::cout << "\n=== Library Catalog ===" << std::endl;
            std::cout << "1. Load books from file" << std::endl;
            std::cout << "2. Search for a book by title" << std::endl;
            std::cout << "3. Display hash table" << std::endl;
            std::cout << "4. Exit" << std::endl;
            std::cout << "Enter choice: ";
            std::cin >> choice;
            
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            switch (choice) {
                case 1:
                    std::cout << "Enter filename (default: books.txt): ";
                    std::getline(std::cin, filename);
                    if (filename.empty()) filename = "books.txt";
                    loadBooksFromFile(filename);
                    break;
                    
                case 2:
                    std::cout << "Enter book title: ";
                    std::getline(std::cin, searchTitle);
                    searchBook(searchTitle);
                    break;
                    
                case 3:
                    displayHashTable();
                    break;
                    
                case 4:
                    std::cout << "Goodbye!" << std::endl;
                    break;
                    
                default:
                    std::cout << "Invalid choice." << std::endl;
            }
        } while (choice != 4);
    }
};

int main() {
    std::cout << "Library Catalog System" << std::endl;
    std::cout << "Uses hash table with AVL tree chaining" << std::endl;
    
    LibraryCatalog catalog;
    catalog.runMenu();
    
    return 0;
} 