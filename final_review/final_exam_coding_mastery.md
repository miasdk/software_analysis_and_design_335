# Final Exam Coding Mastery - All Question Types

## 🎯 **EXAM CODING QUESTION TYPES BREAKDOWN**

Based on your professor's hints, expect coding questions on:
1. **Vector Iterators** - Print elements using iterators
2. **Hash Map Insertion** - Implement insert method 
3. **Collision Resolution** - Separate chaining, open addressing, double hashing
4. **Graph Class** - Adjacency list implementation with constructor
5. **Priority Queue Operations** - Basic heap operations
6. **Mixed Data Structure Questions** - Combining concepts

---

## 📝 **SECTION 1: VECTOR ITERATORS - GUARANTEED QUESTION**

### **Basic Iterator Pattern (MEMORIZE THIS!)**
```cpp
#include <vector>
#include <iostream>

// Method 1: Traditional Iterator Loop
std::vector<int> v = {1, 2, 3, 4, 5};
for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
}
std::cout << std::endl;

// Method 2: Const Iterator (read-only)
for (auto it = v.cbegin(); it != v.cend(); ++it) {
    std::cout << *it << " ";
}

// Method 3: Explicit Type (if auto not allowed)
for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
}
```

### **Variations You Might See:**
```cpp
// Reverse iteration
for (auto it = v.rbegin(); it != v.rend(); ++it) {
    std::cout << *it << " ";
}

// Skip every other element
for (auto it = v.begin(); it != v.end(); it += 2) {
    std::cout << *it << " ";
}

// Modify elements while iterating
for (auto it = v.begin(); it != v.end(); ++it) {
    *it = *it * 2;  // Double each element
    std::cout << *it << " ";
}

// Find and erase specific elements
for (auto it = v.begin(); it != v.end(); ) {
    if (*it % 2 == 0) {
        it = v.erase(it);  // Remove even numbers
    } else {
        ++it;
    }
}
```

### **Complete Function Template:**
```cpp
#include <vector>
#include <iostream>

void printVectorWithIterators(const std::vector<int>& v) {
    std::cout << "Vector elements: ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it;
        if (it != v.end() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50};
    printVectorWithIterators(numbers);
    return 0;
}
```

---

## 🗂️ **SECTION 2: HASH MAP INSERTION - HIGH PROBABILITY**

### **EXAM-FRIENDLY SIMPLIFIED VERSIONS (MEMORIZE THESE!)**

**✅ Why these simplified versions are PERFECT for exams:**
- **Simple arrays** instead of vectors (less typing, easier to remember)
- **Fixed size** (no dynamic resizing complexity)  
- **Basic data types** (int keys, not key-value pairs)
- **Core algorithm focus** (no extensive error checking)
- **Minimal includes** (just what's absolutely needed)
- **Easy to write by hand** (no complex STL usage)

### **Template 1: Linear Probing - MINIMAL**
```cpp
class HashTable {
private:
    int table[10];        // Simple array, size 10
    bool occupied[10];    // Track occupied slots
    int size = 10;
    
public:
    HashTable() {
        for (int i = 0; i < size; i++) {
            occupied[i] = false;
        }
    }
    
    // CORE INSERT - Just the essential logic
    void insert(int key) {
        int index = key % size;  // Simple hash function
        
        // Linear probing: keep trying next slot
        while (occupied[index]) {
            index = (index + 1) % size;
        }
        
        table[index] = key;
        occupied[index] = true;
    }
    
    void display() {
        for (int i = 0; i < size; i++) {
            if (occupied[i]) {
                std::cout << "Index " << i << ": " << table[i] << std::endl;
            }
        }
    }
};
```

### **Template 2: Quadratic Probing - MINIMAL**
```cpp
class HashTableQuadratic {
private:
    int table[10];
    bool occupied[10];
    int size = 10;
    
public:
    HashTableQuadratic() {
        for (int i = 0; i < size; i++) occupied[i] = false;
    }
    
    void insert(int key) {
        int hash = key % size;
        int i = 0;
        
        // Quadratic probing: (hash + i²) % size
        while (occupied[(hash + i*i) % size]) {
            i++;
        }
        
        int index = (hash + i*i) % size;
        table[index] = key;
        occupied[index] = true;
    }
};
```

### **Template 3: Separate Chaining - MINIMAL**
```cpp
#include <list>

class HashTableChaining {
private:
    std::list<int> table[10];  // Array of lists
    int size = 10;
    
public:
    void insert(int key) {
        int index = key % size;
        table[index].push_back(key);  // Just add to the chain
    }
    
    bool find(int key) {
        int index = key % size;
        for (int val : table[index]) {
            if (val == key) return true;
        }
        return false;
    }
    
    void display() {
        for (int i = 0; i < size; i++) {
            std::cout << "Bucket " << i << ": ";
            for (int val : table[i]) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }
};
```

### **Template 4: Double Hashing - MINIMAL**
```cpp
class HashTableDouble {
private:
    int table[11];     // Prime size helps double hashing
    bool occupied[11];
    int size = 11;
    
public:
    HashTableDouble() {
        for (int i = 0; i < size; i++) occupied[i] = false;
    }
    
    void insert(int key) {
        int hash1 = key % size;              // First hash
        int hash2 = 7 - (key % 7);           // Second hash  
        int i = 0;
        
        // Double hashing: (hash1 + i * hash2) % size
        while (occupied[(hash1 + i * hash2) % size]) {
            i++;
        }
        
                 int index = (hash1 + i * hash2) % size;
         table[index] = key;
         occupied[index] = true;
     }
};
```

### **⚡ COLLISION RESOLUTION CHEAT SHEET**

| Method | Formula | Key Advantage | When to Use |
|--------|---------|---------------|-------------|
| **Linear Probing** | `(hash + i) % size` | Simple to implement | Small tables, exam problems |
| **Quadratic Probing** | `(hash + i²) % size` | Reduces primary clustering | Medium complexity exams |
| **Separate Chaining** | `table[hash % size].push_back(key)` | No clustering, unlimited items | When you need simplicity |
| **Double Hashing** | `(hash1 + i * hash2) % size` | Best distribution | Advanced exam questions |

---

## 📊 **SECTION 3: GRAPH CLASS - GUARANTEED QUESTION**

### **EXAM-FRIENDLY GRAPH TEMPLATE (MEMORIZE THIS!)**
```cpp
#include <vector>
#include <iostream>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjList;
    
public:
    // Constructor - ESSENTIAL for exam
    Graph(int vertices) : numVertices(vertices) {
        adjList.resize(vertices);
    }
    
    // Add edge method - CORE FUNCTIONALITY  
    void addEdge(int source, int dest) {
        adjList[source].push_back(dest);
        adjList[dest].push_back(source);  // For undirected
    }
    
    // Display method - Often asked for
    void display() {
        for (int i = 0; i < numVertices; i++) {
            std::cout << "Vertex " << i << ": ";
            for (int neighbor : adjList[i]) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }
};

// EXAM-STYLE MAIN FUNCTION
int main() {
    Graph g(7);  // Create graph with 7 nodes
    
    // Add 4 edges (typical exam requirement)
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(5, 6);
    
    g.display();
    return 0;
}
```

### **Alternative: Adjacency Matrix Implementation**
```cpp
class GraphMatrix {
private:
    int numVertices;
    int adjMatrix[10][10];  // 2D array (fixed size for exam simplicity)
    
public:
    // Constructor - Initialize all edges to 0
    GraphMatrix(int vertices) : numVertices(vertices) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                adjMatrix[i][j] = 0;  // No edge initially
            }
        }
    }
    
    // Add edge - Set matrix position to 1
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;  // Edge from u to v
        adjMatrix[v][u] = 1;  // Edge from v to u (undirected)
    }
    
    // Display - Print the matrix
    void display() {
        std::cout << "Adjacency Matrix:" << std::endl;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

// Same main function works for both implementations!
```

**📊 Quick Comparison:**
| Aspect | Adjacency List | Adjacency Matrix |
|--------|---------------|------------------|
| **Data Structure** | `vector<vector<int>>` | `int matrix[V][V]` |
| **Add Edge** | `list[u].push_back(v)` | `matrix[u][v] = 1` |
| **Space** | O(V + E) | O(V²) |
| **Best For** | Sparse graphs | Dense graphs, fast edge lookup |

### **Weighted Graph Variation:**
```cpp
class WeightedGraph {
private:
    int numVertices;
    std::vector<std::vector<std::pair<int, int>>> adjList; // {destination, weight}
    
public:
    WeightedGraph(int vertices) : numVertices(vertices) {
        adjList.resize(vertices);
    }
    
    void addEdge(int source, int dest, int weight) {
        adjList[source].emplace_back(dest, weight);
        adjList[dest].emplace_back(source, weight); // For undirected
    }
    
    void display() const {
        for (int i = 0; i < numVertices; i++) {
            std::cout << "Vertex " << i << ": ";
            for (const auto& edge : adjList[i]) {
                std::cout << "(" << edge.first << "," << edge.second << ") ";
            }
            std::cout << std::endl;
        }
    }
};
```

---

## 🔺 **SECTION 4: PRIORITY QUEUE OPERATIONS**

### **Min-Heap Implementation (Possible Question)**
```cpp
#include <vector>
#include <iostream>

class MinHeap {
private:
    std::vector<int> heap;
    
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }
    
    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] > heap[index]) {
            std::swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }
    
    void heapifyDown(int index) {
        int smallest = index;
        int left = leftChild(index);
        int right = rightChild(index);
        
        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }
        
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }
        
        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }
    
public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    
    int extractMin() {
        if (heap.empty()) return -1;
        
        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        
        if (!heap.empty()) {
            heapifyDown(0);
        }
        
        return min;
    }
    
    int getMin() const {
        return heap.empty() ? -1 : heap[0];
    }
    
    void display() const {
        for (int val : heap) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};
```

### **STL Priority Queue Usage:**
```cpp
#include <queue>
#include <vector>

// Max heap (default)
std::priority_queue<int> maxHeap;
maxHeap.push(10);
maxHeap.push(5);
maxHeap.push(15);
std::cout << maxHeap.top(); // 15

// Min heap
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
minHeap.push(10);
minHeap.push(5);
minHeap.push(15);
std::cout << minHeap.top(); // 5

// Custom comparator for objects
struct Task {
    int priority;
    std::string name;
};

struct TaskComparator {
    bool operator()(const Task& a, const Task& b) {
        return a.priority > b.priority; // Min heap by priority
    }
};

std::priority_queue<Task, std::vector<Task>, TaskComparator> taskQueue;
```

---

## 🔀 **SECTION 5: MIXED CODING SCENARIOS**

### **Scenario 1: Hash Map + Iterators**
```cpp
// Count frequency of elements using hash map and vector iterators
#include <unordered_map>
#include <vector>

std::unordered_map<int, int> countFrequency(const std::vector<int>& v) {
    std::unordered_map<int, int> freq;
    
    // Use iterators to traverse vector
    for (auto it = v.begin(); it != v.end(); ++it) {
        freq[*it]++;
    }
    
    return freq;
}
```

### **Scenario 2: Graph + Priority Queue (Dijkstra Pattern)**
```cpp
#include <vector>
#include <queue>
#include <climits>

class GraphDijkstra {
public:
    std::vector<int> dijkstra(int start, const std::vector<std::vector<std::pair<int, int>>>& graph) {
        int V = graph.size();
        std::vector<int> dist(V, INT_MAX);
        std::priority_queue<std::pair<int, int>, 
                           std::vector<std::pair<int, int>>, 
                           std::greater<>> pq;
        
        dist[start] = 0;
        pq.push({0, start});
        
        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            
            for (const auto& edge : graph[u]) {
                int v = edge.first;
                int weight = edge.second;
                
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist;
    }
};
```

---

## 📋 **QUICK CODING PATTERNS CHEAT SHEET**

### **Iterator Patterns:**
```cpp
// Basic traverse
for (auto it = container.begin(); it != container.end(); ++it) { *it }

// Erase while iterating
for (auto it = v.begin(); it != v.end(); ) {
    if (condition) it = v.erase(it);
    else ++it;
}
```

### **Hash Table Patterns:**
```cpp
// Linear probing
index = (hash + i) % table_size

// Quadratic probing  
index = (hash + i*i) % table_size

// Double hashing
index = (hash1 + i * hash2) % table_size
// where hash1 = key % table_size
//       hash2 = 7 - (key % 7)  [common second hash function]
```

### **Graph Patterns:**
```cpp
// Constructor
Graph(int v) : numVertices(v) { adjList.resize(v); }

// Add edge
void addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); // undirected
}
```

### **Heap Patterns:**
```cpp
// Parent/Child relationships
parent = (i-1)/2
leftChild = 2*i+1  
rightChild = 2*i+2

// Heapify up (after insert)
while (i > 0 && heap[parent] > heap[i]) swap and move up

// Heapify down (after delete)
compare with children, swap with smaller, continue down
```

---

## 🎯 **EXAM DAY CODING STRATEGY**

### **Step 1: Read Question Carefully**
- Identify the data structure required
- Note if it's asking for specific methods
- Check for any special requirements (weighted, directed, etc.)

### **Step 2: Write Function Signature First**
```cpp
// Always start with the basic structure
class ClassName {
private:
    // member variables
public:
    // constructor
    // required methods
};
```

### **Step 3: Implement Core Logic**
- Use the templates above as starting points
- Focus on the specific requirement (insert, traverse, etc.)
- Don't forget edge cases (empty, full, etc.)

### **Step 4: Add Main Function if Required**
```cpp
int main() {
    // Create object with specified parameters
    // Call required methods
    // Display results if needed
    return 0;
}
```

---

## 🚨 **COMMON EXAM MISTAKES TO AVOID**

1. **Forgetting to dereference iterators:** Use `*it`, not `it`
2. **Wrong loop condition:** `it != container.end()`, not `it < container.end()`
3. **Missing collision handling:** Always handle hash collisions
4. **Incorrect array indexing:** Remember 0-based indexing
5. **Forgetting to update counters:** Update `numElements` in hash tables
6. **Missing edge checks:** Check for empty containers, full tables
7. **Wrong graph edge addition:** Add both directions for undirected graphs

---

## 📐 **ESSENTIAL FORMULAS TO MEMORIZE**

| Concept | Formula | Example |
|---------|---------|---------|
| **Load Factor** | `n / m` (elements/buckets) | 75 elements, 100 buckets = 0.75 |
| **Linear Probing** | `(hash + i) % table_size` | hash=5, i=2, size=10 → (5+2)%10 = 7 |
| **Quadratic Probing** | `(hash + i²) % table_size` | hash=5, i=2, size=10 → (5+4)%10 = 9 |
| **Double Hashing** | `(hash1 + i * hash2) % table_size` | hash1=5, hash2=3, i=2, size=10 → (5+2×3)%10 = 1 |
| **Heap Parent** | `(i-1)/2` | Node at index 5 → Parent at (5-1)/2 = 2 |
| **Heap Left Child** | `2*i + 1` | Node at index 2 → Left child at 2×2+1 = 5 |
| **Heap Right Child** | `2*i + 2` | Node at index 2 → Right child at 2×2+2 = 6 |

### **Double Hashing Details:**
```cpp
// Step-by-step double hashing:
hash1 = key % table_size              // Primary hash function
hash2 = 7 - (key % 7)                 // Secondary hash function (common choice)
index = (hash1 + i * hash2) % table_size   // Final probe position

// Example: key=23, table_size=11, probe i=2
hash1 = 23 % 11 = 1
hash2 = 7 - (23 % 7) = 7 - 2 = 5  
index = (1 + 2 * 5) % 11 = 11 % 11 = 0
```

---

## 🎯 **EXAM SUCCESS FORMULA**

### **What Professors Want to See:**
1. **Core algorithm understanding** - not perfect production code
2. **Correct collision resolution logic** - linear, quadratic, chaining, double hashing
3. **Basic graph structure** - constructor + addEdge + simple main
4. **Iterator dereferencing** - using `*it` correctly
5. **Simple, readable code** - arrays over vectors when possible

### **Time Management Strategy:**
- **Vector iterators:** 3-4 minutes max
- **Hash insertion:** 8-10 minutes 
- **Graph class:** 10-12 minutes
- **Save time** with these minimal templates!

### **Common Professor Tricks:**
- "Implement linear probing" → Use simple array + while loop
- "Write a graph class" → Just constructor + addEdge + display
- "Use iterators to print" → Basic for loop with `*it`
- "Handle collisions" → Pick ONE method, implement it simply

---

**🔥 FINAL TIP: Practice writing these BY HAND multiple times before the exam!** 