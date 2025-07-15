# Project 3: Priority Queue with MaxHeap - Customer Service Simulation

## Learning Objectives
1. **Master MaxHeap Implementation**: Understand heap data structure and its properties
2. **Implement Priority Queue**: Learn how to use heaps for priority-based operations
3. **Simulate Real-World Scenarios**: Build a customer service simulation system
4. **Apply Sorting and Data Management**: Practice with vectors and sorting algorithms

## Measurable Learning Outcomes
- ✅ Implement a complete MaxHeap with insertion and deletion operations
- ✅ Create a Customer class with priority and service time management
- ✅ Build a functional customer service simulation system
- ✅ Apply sorting algorithms to analyze service performance
- ✅ Write clean, well-documented code with proper randomization

## Project Structure
```
project03/
├── MaxHeap.h          # MaxHeap template class header
├── Customer.h         # Customer class header
├── Customer.cpp       # Customer class implementation
├── main.cpp           # Main simulation program
├── Makefile           # Build configuration
└── README.md          # This file
```

## Key Concepts Implemented

### MaxHeap Data Structure
- **Heap property**: Parent is always greater than or equal to children
- **Complete binary tree**: Filled level by level, left to right
- **Heapify operations**: Up and down heapification for maintaining properties
- **Time complexity**: O(log n) for insert and delete operations

### Priority Queue Implementation
- **Priority-based ordering**: Higher priority customers served first
- **MaxHeap usage**: Naturally orders by maximum priority
- **Efficient operations**: O(log n) for insert and extract operations

### Customer Service Simulation
- **Random customer generation**: Names, priority levels, and service times
- **Priority-based service**: Customers served in order of priority
- **Service time tracking**: Records actual service duration
- **Performance analysis**: Statistics and sorted history

## Compilation and Usage

### Build the project:
```bash
make
```

### Run the simulation:
```bash
make run
# or
./customer_simulation
```

### Clean build files:
```bash
make clean
```

## Simulation Flow

1. **Customer Generation**: Random customers arrive with random priority levels (0-100)
2. **Priority Queue**: Customers are inserted into MaxHeap based on priority
3. **Service Process**: Clerk serves customers in priority order (highest first)
4. **Service Time Recording**: Each customer gets a random service time (0-60 minutes)
5. **History Tracking**: All served customers are recorded in a vector
6. **Analysis**: History is sorted by service time and statistics are calculated

## Time and Space Complexity Analysis

### MaxHeap Operations:
- **Insert**: O(log n) - heapify up operation
- **DeleteMax**: O(log n) - heapify down operation
- **GetMax**: O(1) - access root element
- **Space**: O(n) - stores n elements

### Priority Queue Operations:
- **Enqueue**: O(log n) - MaxHeap insert
- **Dequeue**: O(log n) - MaxHeap deleteMax
- **Peek**: O(1) - MaxHeap getMax
- **Space**: O(n) - stores n customers

### Simulation Operations:
- **Customer generation**: O(n log n) - n insertions
- **Service process**: O(n log n) - n deletions
- **History sorting**: O(n log n) - std::sort
- **Statistics calculation**: O(n) - single pass through history

## Key Learning Points

1. **Heap Properties**: Understanding the complete binary tree structure and heap ordering
2. **Priority Queue Design**: Using MaxHeap for natural priority ordering
3. **Template Implementation**: Creating reusable data structures with templates
4. **Random Number Generation**: Proper seeding and distribution for simulation
5. **Data Analysis**: Collecting, sorting, and analyzing simulation results

## Testing the Implementation

1. **Run simulation**: Execute the program and observe customer processing
2. **Verify priority ordering**: Higher priority customers should be served first
3. **Check service times**: Service times should be random between 0-60 minutes
4. **Analyze results**: Review the sorted history and statistics
5. **Test different sizes**: Try different numbers of customers

## Extension Ideas

1. **Multiple clerks**: Simulate multiple service representatives
2. **Customer types**: Different customer categories with different priority ranges
3. **Service categories**: Different types of problems with different service times
4. **Queue visualization**: Display the heap structure during operations
5. **Performance metrics**: Track wait times, queue lengths, and efficiency
6. **Real-time simulation**: Add time delays to simulate real service scenarios

## Comparison with MinHeap

This project demonstrates the conversion from MinHeap to MaxHeap:
- **MinHeap**: Parent ≤ children (smallest element at root)
- **MaxHeap**: Parent ≥ children (largest element at root)
- **Key changes**: Comparison operators in heapify operations
- **Application**: Priority queues naturally use MaxHeap for highest priority first 