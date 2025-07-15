# Project 2: Hash Table with AVL Tree Chaining

## Learning Objectives
1. **Master AVL Tree Implementation**: Understand self-balancing binary search trees and their rotation mechanisms
2. **Implement Hash Table with Separate Chaining**: Learn how to combine hash tables with tree structures for collision resolution
3. **Apply Data Structures to Real-World Problems**: Build a library catalog system using your data structures
4. **Analyze Time and Space Complexity**: Understand the theoretical performance characteristics of your implementation

## Measurable Learning Outcomes
- ✅ Implement a complete AVL tree with insertion, deletion, and search operations
- ✅ Create a hash table that uses AVL trees for collision resolution
- ✅ Build a functional library catalog system with file I/O
- ✅ Analyze and document time/space complexity of all operations
- ✅ Write clean, well-documented code with proper error handling

## Project Structure
```
project02/
├── AVLTree.h          # AVL tree header file
├── AVLTree.cpp        # AVL tree implementation
├── HashTable.h        # Hash table header file
├── HashTable.cpp      # Hash table implementation
├── main.cpp           # Main application (library catalog)
├── books.txt          # Sample book data
├── Makefile           # Build configuration
└── README.md          # This file
```

## Key Concepts Implemented

### AVL Tree
- **Self-balancing**: Maintains height balance through rotations
- **Four rotation cases**: LL, RR, LR, RL rotations
- **Balance factor**: height(left) - height(right)
- **Time complexity**: O(log n) for all operations

### Hash Table with AVL Chaining
- **Collision resolution**: Uses AVL trees instead of linked lists
- **Hash function**: Uses std::hash for string keys
- **Load factor**: Monitors table utilization
- **Time complexity**: O(log n) average case for operations

### Library Catalog System
- **File I/O**: Loads books from CSV format
- **Search functionality**: Find books by title
- **Interactive menu**: User-friendly interface
- **Data persistence**: Stores author and genre information

## Compilation and Usage

### Build the project:
```bash
make
```

### Run the program:
```bash
make run
# or
./library_catalog
```

### Clean build files:
```bash
make clean
```

## Time and Space Complexity Analysis

### AVL Tree Operations:
- **Insert**: O(log n) - requires rebalancing
- **Search**: O(log n) - balanced tree traversal
- **Delete**: O(log n) - requires rebalancing
- **Space**: O(n) - stores n nodes

### Hash Table Operations:
- **Insert**: O(log n) average - AVL tree insertion in bucket
- **Search**: O(log n) average - AVL tree search in bucket
- **Delete**: O(log n) average - AVL tree deletion in bucket
- **Space**: O(n) - stores n key-value pairs

### Library Catalog Operations:
- **Load from file**: O(n log n) - n insertions
- **Search by title**: O(log n) average - hash table search
- **Display**: O(n) - traverse all buckets

## Testing the Implementation

1. **Load books**: Choose option 1 and use "books.txt"
2. **Search for books**: Try searching for "The Great Gatsby" or "1984"
3. **Display table**: See how books are distributed across hash buckets
4. **Test edge cases**: Search for non-existent books

## Key Learning Points

1. **AVL Tree Balancing**: Understanding when and how rotations occur
2. **Hash Function Design**: Choosing appropriate table size and hash function
3. **Data Structure Integration**: Combining multiple data structures effectively
4. **Real-world Application**: Applying theoretical concepts to practical problems
5. **Performance Analysis**: Understanding trade-offs between different approaches

## Extension Ideas

1. **Dynamic resizing**: Implement hash table resizing when load factor exceeds threshold
2. **Multiple hash functions**: Try different hash functions and compare performance
3. **Book deletion**: Add functionality to remove books from the catalog
4. **Genre-based search**: Implement search by author or genre
5. **Performance metrics**: Add timing measurements for operations 