# Final Exam Complete Answer Key with Detailed Explanations

## 📋 **SECTION 1: TRUE OR FALSE**

### **Question 1: Hash collision occur when two different keys generate the same hash value and map to the same index in the hash table**
**Answer: TRUE** ✅

**Detailed Explanation:**
A hash collision is exactly what this statement describes. When two different keys produce the same hash value, they "collide" at the same index in the hash table.

**Example:**
```cpp
// Hash function: h(x) = x % 10
h(15) = 15 % 10 = 5
h(25) = 25 % 10 = 5
// Both keys (15 and 25) map to index 5 → COLLISION!
```

**Collision Resolution Methods:**
- **Linear Probing:** Move to next available slot
- **Quadratic Probing:** Move using quadratic sequence
- **Chaining:** Use linked lists at each index

---

### **Question 2: The push() operation for priority queues has a worst time complexity of O(log n)**
**Answer: TRUE** ✅

**Detailed Explanation:**
Priority queues are typically implemented as binary heaps. When inserting (pushing) an element:
1. Add element at the end of the heap (next available position)
2. "Percolate up" by comparing with parent and swapping if necessary
3. Continue until heap property is restored

**Why O(log n)?**
- The height of a binary heap with n elements is log₂(n)
- In worst case, element travels from bottom to root
- Maximum comparisons/swaps = height = O(log n)

**STL Example:**
```cpp
std::priority_queue<int> pq;
pq.push(5); // O(log n) - may need to bubble up to maintain heap property
```

---

### **Question 3: The load factor of a hash map indicates the number of buckets in the hash table**
**Answer: FALSE** ❌

**Detailed Explanation:**
The load factor is **NOT** the number of buckets. It's a ratio that measures how "full" the hash table is.

**Correct Definition:**
**Load Factor = Number of elements / Number of buckets**

**Examples:**
- Hash table with 10 buckets, 7 elements → Load factor = 7/10 = 0.7
- Hash table with 100 buckets, 50 elements → Load factor = 50/100 = 0.5

**Why it matters:**
- Higher load factor = more collisions = slower performance
- Typical threshold: 0.75 (resize when load factor exceeds this)

---

### **Question 4: All trees are graphs but not all graphs are trees**
**Answer: TRUE** ✅

**Detailed Explanation:**
This is a fundamental relationship in graph theory.

**Tree Definition:** A connected, acyclic graph
**Graph Definition:** Collection of vertices connected by edges

**Why trees are graphs:**
- Trees have vertices (nodes) and edges
- They satisfy the basic definition of a graph

**Why not all graphs are trees:**
- Graphs can have cycles (trees cannot)
- Graphs can be disconnected (trees must be connected)
- Graphs can have multiple paths between nodes (trees have exactly one)

**Examples:**
- Tree: Family tree, file system hierarchy
- Graph (not tree): Social network (cycles possible), road network

---

### **Question 5: To print what an iterator is pointing to you have to dereference it using the * operator**
**Answer: TRUE** ✅

**Detailed Explanation:**
Iterators behave like pointers. To access the value they point to, you must dereference them.

**Example:**
```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
auto it = v.begin();

// WRONG: std::cout << it; // Prints memory address
// CORRECT: 
std::cout << *it; // Prints 1 (the value it points to)

// For pairs/objects:
std::unordered_map<std::string, int> map = {{"apple", 5}};
auto mapIt = map.begin();
std::cout << mapIt->first;  // "apple" (using ->)
std::cout << (*mapIt).first; // "apple" (using * then .)
```

---

### **Question 6: A heap can be used to sort elements**
**Answer: TRUE** ✅

**Detailed Explanation:**
This describes **Heap Sort**, a classic sorting algorithm.

**Heap Sort Algorithm:**
1. Build a max-heap from unsorted array
2. Repeatedly extract the maximum (root) and place at end
3. Restore heap property and repeat

**Time Complexity:** O(n log n)
**Space Complexity:** O(1) - sorts in place

**Example with STL:**
```cpp
std::vector<int> heapSort(std::vector<int> nums) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    
    // Insert all elements: O(n log n)
    for (int num : nums) minHeap.push(num);
    
    // Extract in sorted order: O(n log n)
    nums.clear();
    while (!minHeap.empty()) {
        nums.push_back(minHeap.top());
        minHeap.pop();
    }
    return nums;
}
```

---

### **Question 7: A heap must always be a full binary tree**
**Answer: FALSE** ❌

**Detailed Explanation:**
A heap must be a **complete** binary tree, not necessarily **full**.

**Definitions:**
- **Full Binary Tree:** Every node has either 0 or 2 children
- **Complete Binary Tree:** All levels filled except possibly the last, which fills left-to-right

**Heap Requirements:**
1. **Complete binary tree** (not full)
2. **Heap property** (min-heap: parent ≤ children, max-heap: parent ≥ children)

**Example of valid heap that's NOT full:**
```
      1
     / \
    2   3
   /
  4
```
This has a node (2) with only one child, so it's not full, but it's still a valid heap!

---

### **Question 8: The insert method for hash tables has a best time complexity of O(1)**
**Answer: TRUE** ✅

**Detailed Explanation:**
In the **best case**, hash table insertion is indeed O(1).

**Best Case Scenario:**
- Hash function distributes keys uniformly
- No collisions occur
- Direct insertion at computed index

**Process:**
1. Compute hash: O(1)
2. Find index: O(1)
3. Insert at index: O(1)
**Total: O(1)**

**However:**
- **Average case:** O(1) with good hash function
- **Worst case:** O(n) if all keys hash to same index (all collisions)

**STL Example:**
```cpp
std::unordered_map<int, std::string> map;
map[42] = "answer"; // Best case: O(1)
```

---

### **Question 9: In hash maps, keys do not have to be unique**
**Answer: FALSE** ❌

**Detailed Explanation:**
Keys in hash maps **MUST** be unique. This is a fundamental requirement.

**Why keys must be unique:**
- Hash maps store key-value pairs
- Each key maps to exactly one value
- Duplicate keys would create ambiguity

**What happens with duplicate keys:**
```cpp
std::unordered_map<std::string, int> map;
map["apple"] = 5;
map["apple"] = 10; // Overwrites previous value!
// map["apple"] is now 10, not 5
```

**If you need duplicate keys:**
- Use `std::unordered_multimap<>` (allows multiple values per key)
- Use `std::vector<std::pair<>>` for ordered duplicates

---

### **Question 10: Priority queues allow for random access like vectors**
**Answer: FALSE** ❌

**Detailed Explanation:**
Priority queues do **NOT** support random access. They only allow access to the highest priority element.

**Priority Queue Operations:**
- `top()` - Access highest priority element: O(1)
- `push()` - Insert element: O(log n)
- `pop()` - Remove highest priority: O(log n)

**No random access:**
```cpp
std::priority_queue<int> pq;
pq.push(1); pq.push(5); pq.push(3);

// ALLOWED:
std::cout << pq.top(); // 5 (highest priority)

// NOT ALLOWED:
// std::cout << pq[1]; // ERROR! No [] operator
// No way to access middle elements without popping
```

**Comparison:**
- **Vector:** Random access with `v[i]` in O(1)
- **Priority Queue:** Only top element accessible

---

## 📝 **SECTION 2: SHORT ANSWER**

### **Question 1: Write code that uses iterators in a vector of ints to print the elements**

**Answer:**
```cpp
#include <vector>
#include <iostream>

std::vector<int> v = {1, 2, 3, 4, 5};

// Method 1: Traditional iterator loop
for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
}
std::cout << std::endl;

// Method 2: Range-based for loop (uses iterators internally)
for (const int& element : v) {
    std::cout << element << " ";
}
std::cout << std::endl;

// Method 3: Explicit iterator types
for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
}
```

**Key Points:**
- Must **dereference** iterator with `*it` to get value
- Use `++it` (pre-increment) for efficiency
- `begin()` points to first element, `end()` points past last element

---

### **Question 2: What is a collision in hash maps?**

**Answer:**
A **collision** in hash maps occurs when two different keys produce the same hash value and map to the same index in the hash table.

**Example:**
```cpp
// Hash function: h(x) = x % 7
int key1 = 10; // h(10) = 10 % 7 = 3
int key2 = 17; // h(17) = 17 % 7 = 3
// Both keys map to index 3 → COLLISION!
```

**Collision Resolution Methods:**
1. **Linear Probing:** `(hash + i) % table_size`
2. **Quadratic Probing:** `(hash + i²) % table_size`
3. **Chaining:** Use linked lists at each index
4. **Double Hashing:** Use second hash function

**Impact:** More collisions = slower performance due to additional probing/searching.

---

### **Question 3: What property must a binary heap satisfy to be considered a min-heap?**

**Answer:**
A binary heap must satisfy the **min-heap property**:

**Min-Heap Property:** For every node, the value of the node must be **less than or equal to** the values of its children.

**Formally:** For any node `i` with children `left` and `right`:
- `heap[i] ≤ heap[left]`
- `heap[i] ≤ heap[right]`

**Example Min-Heap:**
```
      1
     / \
    2   3
   / \ / \
  4  5 6  7
```

**Additional Requirements:**
1. **Complete binary tree** (all levels filled except possibly last, which fills left-to-right)
2. **Array representation:** Parent at `i`, children at `2i+1` and `2i+2`

**Result:** The smallest element is always at the root (index 0).

---

### **Question 4: Write the formula to compute the load factor**

**Answer:**
```
Load Factor = Number of elements in hash table / Number of buckets in hash table
```

**Mathematical notation:**
```
λ (lambda) = n / m
where:
- λ = load factor
- n = number of elements stored
- m = number of buckets (table size)
```

**Examples:**
- Hash table with 100 buckets, 75 elements: λ = 75/100 = 0.75
- Hash table with 10 buckets, 3 elements: λ = 3/10 = 0.3

**Significance:**
- **Low load factor (< 0.7):** Few collisions, fast operations
- **High load factor (> 0.8):** Many collisions, slower operations
- **Typical threshold:** Resize table when λ > 0.75

---

### **Question 5: What problem is caused by linear probing?**

**Answer:**
Linear probing causes **primary clustering** (also called clustering problem).

**Primary Clustering Definition:**
When collisions occur, linear probing creates long sequences of occupied slots that grow together, forming "clusters."

**How it happens:**
```cpp
// Hash function: h(x) = x % 7
// Insert: 14, 21, 28 (all hash to index 0)

Step 1: Insert 14 → goes to index 0
Step 2: Insert 21 → collision at 0, goes to index 1  
Step 3: Insert 28 → collision at 0, collision at 1, goes to index 2

Result: Cluster at indices [0,1,2]
```

**Problems caused:**
1. **Longer search times:** Must probe through entire cluster
2. **More collisions:** Any key hashing near cluster causes more probing
3. **Degraded performance:** O(1) average becomes O(n) in worst case
4. **Uneven distribution:** Some areas crowded, others empty

**Solution:** Use quadratic probing or double hashing to reduce clustering.

---

### **Question 6: Write the formula for quadratic probing**

**Answer:**
```
index = (hash + i²) % table_size
```

**Where:**
- `hash` = original hash value of the key
- `i` = probe sequence number (0, 1, 2, 3, ...)
- `table_size` = size of hash table

**Detailed sequence:**
```cpp
// For key with hash value h:
Probe 0: (h + 0²) % table_size = (h + 0) % table_size
Probe 1: (h + 1²) % table_size = (h + 1) % table_size  
Probe 2: (h + 2²) % table_size = (h + 4) % table_size
Probe 3: (h + 3²) % table_size = (h + 9) % table_size
...
```

**Example:**
```cpp
// Key hashes to index 3, table size = 11
Probe 0: (3 + 0) % 11 = 3
Probe 1: (3 + 1) % 11 = 4
Probe 2: (3 + 4) % 11 = 7
Probe 3: (3 + 9) % 11 = 1
```

**Advantage:** Reduces primary clustering compared to linear probing.

---

### **Question 7: What is the worst time complexity for the heapify method?**

**Answer:** **O(log n)**

**Detailed Explanation:**
The **heapify** (or "percolate down") method restores the heap property by moving an element down the tree until it finds its correct position.

**How heapify works:**
1. Start at a node that violates heap property
2. Compare with children and swap with smaller child (min-heap)
3. Continue down until heap property is restored or reach leaf

**Why O(log n)?**
- In worst case, element travels from root to leaf
- Height of binary heap = log₂(n)
- Maximum swaps = height = O(log n)

**Example scenario:**
```cpp
// Min-heap after deleting root:
//   100     ← Violates min-heap property
//   / \
//  2   3
// / \
//4   5

// Heapify process:
// 1. Swap 100 with 2: O(1)
// 2. Move down tree: O(log n) in worst case
```

**Usage:**
- **Building heap:** O(n) using bottom-up heapify
- **Delete min/max:** O(log n) using single heapify
- **Priority queue pop():** O(log n)

---

### **Question 8: What is the best way to represent a graph in C++ for sparse graphs?**

**Answer:** **Adjacency List**

**Definition:**
An adjacency list represents a graph using an array/vector where each index corresponds to a vertex, and each element contains a list of adjacent vertices.

**Implementation:**
```cpp
// For graph with V vertices
std::vector<std::vector<int>> adjList(V);

// Add edge from u to v
void addEdge(int u, int v) {
    adjList[u].push_back(v);
    // For undirected graph, also add:
    adjList[v].push_back(u);
}
```

**Why best for sparse graphs:**

| Representation | Space Complexity | Edge Check | Add Edge | Sparse Graph Efficiency |
|---------------|------------------|------------|----------|------------------------|
| Adjacency List | O(V + E) | O(degree) | O(1) | ✅ Excellent |
| Adjacency Matrix | O(V²) | O(1) | O(1) | ❌ Wasteful |

**For sparse graphs (E << V²):**
- Adjacency list: O(V + E) space (efficient)
- Adjacency matrix: O(V²) space (wasteful)

**Example:** Graph with 1000 vertices, 50 edges:
- Adjacency list: ~1050 storage units
- Adjacency matrix: 1,000,000 storage units

---

### **Question 9: Name a situation where you would use a priority queue over a hash map**

**Answer:** **Task scheduling based on priority/deadline**

**Detailed Explanation:**
Use priority queues when you need to **repeatedly access the highest/lowest priority element**, not when you need fast key-based lookups.

**Specific scenarios:**

1. **Task Scheduler:**
```cpp
struct Task {
    int priority;
    std::string name;
    bool operator>(const Task& other) const {
        return priority > other.priority; // Min-heap by priority
    }
};
std::priority_queue<Task, std::vector<Task>, std::greater<Task>> scheduler;
// Always execute highest priority task next
```

2. **Dijkstra's Algorithm:** Process nearest unvisited vertex
3. **Huffman Coding:** Build tree by merging smallest frequency nodes
4. **Event Simulation:** Process events in chronological order
5. **Top K problems:** Find K largest/smallest elements

**Hash Map is better for:**
- Key-value associations
- Fast lookups by specific key
- Checking existence of specific elements

**Key difference:**
- **Priority Queue:** "Give me the most important item"
- **Hash Map:** "Give me the value for this specific key"

---

### **Question 10: When traversing std::unordered_map are iterators necessary? Explain**

**Answer:** **Not strictly necessary, but highly recommended.**

**Detailed Explanation:**

**Option 1: Range-based for loop (uses iterators internally)**
```cpp
std::unordered_map<std::string, int> map = {{"apple", 5}, {"banana", 3}};

// Preferred method - clean and readable
for (const auto& pair : map) {
    std::cout << pair.first << ": " << pair.second << std::endl;
}
```

**Option 2: Explicit iterators**
```cpp
// Explicit iterator use
for (auto it = map.begin(); it != map.end(); ++it) {
    std::cout << it->first << ": " << it->second << std::endl;
}
```

**Option 3: Structured bindings (C++17)**
```cpp
// Even cleaner with structured bindings
for (const auto& [key, value] : map) {
    std::cout << key << ": " << value << std::endl;
}
```

**When explicit iterators ARE necessary:**
1. **Safe deletion during iteration:**
```cpp
for (auto it = map.begin(); it != map.end(); ) {
    if (it->second == 0) {
        it = map.erase(it); // Returns next valid iterator
    } else {
        ++it;
    }
}
```

2. **Need iterator position for other operations**
3. **Performance-critical code where you want control**

**Conclusion:** Range-based for loops are sufficient for simple traversal, but understanding iterators is essential for advanced operations.

---

## 💻 **SECTION 3: CODING**

### **Question 1: Write a class for a graph data structure that uses an adjacency list**

#### **Part A: Include a constructor that takes in one parameter for the number of nodes**
#### **Part B: Write a method that adds edges**  
#### **Part C: Write a main function that creates a graph object with 7 nodes and adds 4 random edges**

**Complete Solution:**

```cpp
#include <vector>
#include <iostream>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjList;
    
public:
    // Constructor that takes number of nodes
    Graph(int vertices) : numVertices(vertices) {
        adjList.resize(vertices);
    }
    
    // Method to add edges
    void addEdge(int source, int destination) {
        // Add edge from source to destination
        adjList[source].push_back(destination);
        
        // For undirected graph, also add reverse edge
        adjList[destination].push_back(source);
    }
    
    // Method to display the graph (helpful for testing)
    void displayGraph() {
        for (int i = 0; i < numVertices; i++) {
            std::cout << "Vertex " << i << ": ";
            for (int neighbor : adjList[i]) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }
    
    // Getter for number of vertices
    int getNumVertices() const {
        return numVertices;
    }
};

// Main function with 7 nodes and 4 random edges
int main() {
    // Create graph object with 7 nodes
    Graph g(7);
    
    // Add 4 random edges
    g.addEdge(0, 1);  // Edge between node 0 and 1
    g.addEdge(1, 2);  // Edge between node 1 and 2  
    g.addEdge(3, 4);  // Edge between node 3 and 4
    g.addEdge(5, 6);  // Edge between node 5 and 6
    
    // Display the graph
    std::cout << "Graph with " << g.getNumVertices() << " vertices:" << std::endl;
    g.displayGraph();
    
    return 0;
}
```

**Expected Output:**
```
Graph with 7 vertices:
Vertex 0: 1 
Vertex 1: 0 2 
Vertex 2: 1 
Vertex 3: 4 
Vertex 4: 3 
Vertex 5: 6 
Vertex 6: 5 
```

**Key Design Decisions:**
1. **Adjacency List:** `std::vector<std::vector<int>>` for efficient sparse graph storage
2. **Undirected Graph:** Added edges in both directions
3. **Error Handling:** Could add bounds checking for robustness
4. **Extensibility:** Easy to add methods like BFS, DFS, etc.

---

### **Question 2: Write the method for inserting into a hash map**

**Complete Solution:**

```cpp
#include <vector>
#include <iostream>
#include <utility>

class HashTable {
private:
    std::vector<std::pair<int, std::string>> table;
    std::vector<bool> isOccupied;
    int numBuckets;
    int numElements;
    
    // Hash function
    int hashFunction(int key) const {
        return key % numBuckets;
    }
    
public:
    HashTable(int buckets) : numBuckets(buckets), numElements(0) {
        table.resize(buckets);
        isOccupied.resize(buckets, false);
    }
    
    // INSERT METHOD - The main answer
    void insert(int key, const std::string& value) {
        // Check if table is full
        if (numElements == numBuckets) {
            std::cout << "Hash table is full! Cannot insert." << std::endl;
            return;
        }
        
        int index = hashFunction(key);
        int startIndex = index;
        
        // Linear probing to find available slot
        while (isOccupied[index]) {
            // If key already exists, update value
            if (table[index].first == key) {
                table[index].second = value;
                std::cout << "Updated key " << key << " with new value: " << value << std::endl;
                return;
            }
            
            // Move to next slot (linear probing)
            index = (index + 1) % numBuckets;
            
            // If we've come full circle, table is full
            if (index == startIndex) {
                std::cout << "Hash table is full! Cannot insert." << std::endl;
                return;
            }
        }
        
        // Insert new key-value pair
        table[index] = std::make_pair(key, value);
        isOccupied[index] = true;
        numElements++;
        
        std::cout << "Inserted (" << key << ", " << value << ") at index " << index << std::endl;
    }
    
    // Helper method to display table contents
    void display() const {
        std::cout << "\nHash Table Contents:" << std::endl;
        for (int i = 0; i < numBuckets; i++) {
            if (isOccupied[i]) {
                std::cout << "Index " << i << ": (" << table[i].first 
                         << ", " << table[i].second << ")" << std::endl;
            } else {
                std::cout << "Index " << i << ": [empty]" << std::endl;
            }
        }
        std::cout << "Load factor: " << (double)numElements / numBuckets << std::endl;
    }
};

// Test the insert method
int main() {
    HashTable ht(7);  // Create hash table with 7 buckets
    
    // Test insertions
    ht.insert(10, "apple");    // 10 % 7 = 3
    ht.insert(17, "banana");   // 17 % 7 = 3 (collision!)
    ht.insert(5, "cherry");    // 5 % 7 = 5
    ht.insert(24, "date");     // 24 % 7 = 3 (collision!)
    ht.insert(10, "updated");  // Update existing key
    
    ht.display();
    
    return 0;
}
```

**Expected Output:**
```
Inserted (10, apple) at index 3
Inserted (17, banana) at index 4
Inserted (5, cherry) at index 5
Inserted (24, date) at index 6
Updated key 10 with new value: updated

Hash Table Contents:
Index 0: [empty]
Index 1: [empty]
Index 2: [empty]
Index 3: (10, updated)
Index 4: (17, banana)
Index 5: (5, cherry)
Index 6: (24, date)
Load factor: 0.571429
```

**Key Features of the Insert Method:**

1. **Hash Calculation:** `key % numBuckets`
2. **Collision Resolution:** Linear probing `(index + 1) % numBuckets`
3. **Duplicate Key Handling:** Updates existing value
4. **Full Table Check:** Prevents infinite loop
5. **Load Factor Tracking:** Monitors table fullness

**Time Complexity:**
- **Best Case:** O(1) - no collision
- **Average Case:** O(1) - with good hash function and low load factor  
- **Worst Case:** O(n) - all keys hash to same location

---

## 🎯 **QUICK REFERENCE FORMULAS**

| Concept | Formula | Example |
|---------|---------|---------|
| **Load Factor** | `n / m` (elements/buckets) | 75 elements, 100 buckets = 0.75 |
| **Linear Probing** | `(hash + i) % table_size` | hash=5, i=2, size=10 → (5+2)%10 = 7 |
| **Quadratic Probing** | `(hash + i²) % table_size` | hash=5, i=2, size=10 → (5+4)%10 = 9 |
| **Heap Array Relations** | Parent: `(i-1)/2`, Children: `2i+1, 2i+2` | Node 3 → Parent: 1, Children: 7,8 |

## ⏰ **TIME COMPLEXITIES CHEAT SHEET**

| Operation | Hash Map | Priority Queue | Graph (Adj List) |
|-----------|----------|----------------|------------------|
| **Insert** | O(1) avg, O(n) worst | O(log n) | O(1) |
| **Delete** | O(1) avg, O(n) worst | O(log n) | O(V) |
| **Search** | O(1) avg, O(n) worst | O(n) | O(V+E) |
| **Access Min/Max** | N/A | O(1) | N/A |

---

**🚀 Remember: Practice writing this code BY HAND before the exam!** 