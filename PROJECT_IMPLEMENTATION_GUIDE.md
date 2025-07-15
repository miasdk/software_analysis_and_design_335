# Data Structures & Algorithms Implementation Guide
## Projects 2 & 3 - Complete Tutorial Implementation

This guide provides structured, tutorial-style implementation for both Project 2 (Hash Table with AVL Tree Chaining) and Project 3 (Priority Queue with MaxHeap). Each project includes clear learning objectives, measurable outcomes, and comprehensive implementation.

---

## Project 2: Hash Table with AVL Tree Chaining

### 🎯 Learning Objectives
1. **Master AVL Tree Implementation**: Understand self-balancing binary search trees and their rotation mechanisms
2. **Implement Hash Table with Separate Chaining**: Learn how to combine hash tables with tree structures for collision resolution
3. **Apply Data Structures to Real-World Problems**: Build a library catalog system using your data structures
4. **Analyze Time and Space Complexity**: Understand the theoretical performance characteristics of your implementation

### ✅ Measurable Learning Outcomes
- [x] Implement a complete AVL tree with insertion, deletion, and search operations
- [x] Create a hash table that uses AVL trees for collision resolution
- [x] Build a functional library catalog system with file I/O
- [x] Analyze and document time/space complexity of all operations
- [x] Write clean, well-documented code with proper error handling

### 📁 Project Structure
```
project02/
├── AVLTree.h          # AVL tree header file
├── AVLTree.cpp        # AVL tree implementation
├── HashTable.h        # Hash table header file
├── HashTable.cpp      # Hash table implementation
├── main.cpp           # Main application (library catalog)
├── books.txt          # Sample book data
├── Makefile           # Build configuration
└── README.md          # Detailed documentation
```

### 🔑 Key Concepts Implemented

#### AVL Tree
- **Self-balancing**: Maintains height balance through rotations
- **Four rotation cases**: LL, RR, LR, RL rotations
- **Balance factor**: height(left) - height(right)
- **Time complexity**: O(log n) for all operations

#### Hash Table with AVL Chaining
- **Collision resolution**: Uses AVL trees instead of linked lists
- **Hash function**: Uses std::hash for string keys
- **Load factor**: Monitors table utilization
- **Time complexity**: O(log n) average case for operations

#### Library Catalog System
- **File I/O**: Loads books from CSV format
- **Search functionality**: Find books by title
- **Interactive menu**: User-friendly interface
- **Data persistence**: Stores author and genre information

### 🚀 Usage
```bash
cd project02
make
./library_catalog
```

---

## Project 3: Priority Queue with MaxHeap

### 🎯 Learning Objectives
1. **Master MaxHeap Implementation**: Understand heap data structure and its properties
2. **Implement Priority Queue**: Learn how to use heaps for priority-based operations
3. **Simulate Real-World Scenarios**: Build a customer service simulation system
4. **Apply Sorting and Data Management**: Practice with vectors and sorting algorithms

### ✅ Measurable Learning Outcomes
- [x] Implement a complete MaxHeap with insertion and deletion operations
- [x] Create a Customer class with priority and service time management
- [x] Build a functional customer service simulation system
- [x] Apply sorting algorithms to analyze service performance
- [x] Write clean, well-documented code with proper randomization

### 📁 Project Structure
```
project03/
├── MaxHeap.h          # MaxHeap template class header
├── Customer.h         # Customer class header
├── Customer.cpp       # Customer class implementation
├── main.cpp           # Main simulation program
├── Makefile           # Build configuration
└── README.md          # Detailed documentation
```

### 🔑 Key Concepts Implemented

#### MaxHeap Data Structure
- **Heap property**: Parent is always greater than or equal to children
- **Complete binary tree**: Filled level by level, left to right
- **Heapify operations**: Up and down heapification for maintaining properties
- **Time complexity**: O(log n) for insert and delete operations

#### Priority Queue Implementation
- **Priority-based ordering**: Higher priority customers served first
- **MaxHeap usage**: Naturally orders by maximum priority
- **Efficient operations**: O(log n) for insert and extract operations

#### Customer Service Simulation
- **Random customer generation**: Names, priority levels, and service times
- **Priority-based service**: Customers served in order of priority
- **Service time tracking**: Records actual service duration
- **Performance analysis**: Statistics and sorted history

### 🚀 Usage
```bash
cd project03
make
./customer_simulation
```

---

## 📊 Time and Space Complexity Analysis

### Project 2: Hash Table with AVL Tree
| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| AVL Insert | O(log n) | O(n) |
| AVL Search | O(log n) | O(n) |
| AVL Delete | O(log n) | O(n) |
| Hash Insert | O(log n) avg | O(n) |
| Hash Search | O(log n) avg | O(n) |
| Hash Delete | O(log n) avg | O(n) |

### Project 3: Priority Queue with MaxHeap
| Operation | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| MaxHeap Insert | O(log n) | O(n) |
| MaxHeap DeleteMax | O(log n) | O(n) |
| MaxHeap GetMax | O(1) | O(n) |
| Priority Queue Enqueue | O(log n) | O(n) |
| Priority Queue Dequeue | O(log n) | O(n) |
| Priority Queue Peek | O(1) | O(n) |

---

## 🧠 Key Learning Points

### Data Structure Integration
1. **Combining Structures**: How to effectively combine multiple data structures
2. **Template Implementation**: Creating reusable, generic data structures
3. **Real-world Application**: Applying theoretical concepts to practical problems

### Algorithm Design
1. **Balancing Mechanisms**: Understanding AVL tree rotations and heap properties
2. **Efficiency Trade-offs**: Choosing appropriate data structures for specific use cases
3. **Performance Analysis**: Analyzing and documenting complexity characteristics

### Software Engineering
1. **Clean Code**: Writing well-documented, maintainable code
2. **Error Handling**: Proper exception handling and input validation
3. **Testing**: Comprehensive testing of data structure operations

---

## 🎓 Mastery Checklist

### Project 2 Mastery
- [ ] Can explain AVL tree balancing and rotation mechanisms
- [ ] Can implement hash table with custom collision resolution
- [ ] Can analyze time/space complexity of combined data structures
- [ ] Can build real-world applications using data structures
- [ ] Can handle file I/O and user interaction

### Project 3 Mastery
- [ ] Can explain heap properties and heapify operations
- [ ] Can implement priority queue using heap data structure
- [ ] Can design and implement simulation systems
- [ ] Can apply sorting algorithms for data analysis
- [ ] Can use templates for generic data structures

---

## 🔧 Extension Ideas

### Project 2 Extensions
1. **Dynamic resizing**: Implement hash table resizing when load factor exceeds threshold
2. **Multiple hash functions**: Try different hash functions and compare performance
3. **Book deletion**: Add functionality to remove books from the catalog
4. **Genre-based search**: Implement search by author or genre
5. **Performance metrics**: Add timing measurements for operations

### Project 3 Extensions
1. **Multiple clerks**: Simulate multiple service representatives
2. **Customer types**: Different customer categories with different priority ranges
3. **Service categories**: Different types of problems with different service times
4. **Queue visualization**: Display the heap structure during operations
5. **Performance metrics**: Track wait times, queue lengths, and efficiency

---

## 📚 Additional Resources

### Recommended Reading
- **AVL Trees**: "Introduction to Algorithms" by Cormen et al.
- **Hash Tables**: "Data Structures and Algorithms" by Aho et al.
- **Heaps**: "The Art of Computer Programming" by Knuth
- **Priority Queues**: "Algorithms" by Sedgewick

### Practice Problems
1. Implement a MinHeap and compare with MaxHeap
2. Create a hash table with different collision resolution strategies
3. Build a more complex simulation with multiple queues
4. Implement a balanced binary search tree (Red-Black tree)
5. Design a cache system using hash tables and heaps

---

## 🎯 Success Metrics

### Technical Skills
- [ ] Can implement complex data structures from scratch
- [ ] Can analyze and optimize algorithm performance
- [ ] Can design and build real-world applications
- [ ] Can write clean, maintainable code
- [ ] Can document and explain technical concepts

### Problem-Solving Skills
- [ ] Can break down complex problems into manageable components
- [ ] Can choose appropriate data structures for specific problems
- [ ] Can implement efficient solutions with proper complexity analysis
- [ ] Can test and validate implementations thoroughly
- [ ] Can extend and modify existing code effectively

---

**Good luck with your data structures and algorithms journey! These projects provide a solid foundation for understanding fundamental concepts and their practical applications.** 