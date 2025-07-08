# 🚀 FINAL EXAM CHEATSHEET - Quick Reference

## 📐 **ESSENTIAL FORMULAS (MEMORIZE!)**

| Formula | Code | Example |
|---------|------|---------|
| **Load Factor** | `elements / buckets` | 75/100 = 0.75 |
| **Linear Probing** | `(hash + i) % size` | (5+2)%10 = 7 |
| **Quadratic Probing** | `(hash + i²) % size` | (5+4)%10 = 9 |
| **Double Hashing** | `(hash1 + i*hash2) % size` | (5+2×3)%10 = 1 |
| **Heap Parent** | `(i-1)/2` | Parent of 5 = 2 |
| **Heap Left Child** | `2*i + 1` | Left of 2 = 5 |
| **Heap Right Child** | `2*i + 2` | Right of 2 = 6 |

### **Double Hashing Details:**
```
hash1 = key % table_size
hash2 = 7 - (key % 7)
index = (hash1 + i * hash2) % table_size
```

---

## ✅ **TRUE/FALSE ANSWERS (10 Questions)**

1. **Hash collisions occur when two keys map to same index** → **TRUE**
2. **Priority queue push() is O(log n)** → **TRUE**
3. **Load factor = number of buckets** → **FALSE** (it's elements/buckets)
4. **All trees are graphs but not all graphs are trees** → **TRUE**
5. **Must dereference iterators with *** → **TRUE**
6. **Heaps can be used to sort** → **TRUE** (heap sort)
7. **Heaps must be full binary trees** → **FALSE** (must be complete)
8. **Hash insert best case is O(1)** → **TRUE**
9. **Hash map keys don't need to be unique** → **FALSE** (must be unique)
10. **Priority queues allow random access** → **FALSE** (only top access)

---

## 📝 **SHORT ANSWER KEY CONCEPTS**

- **Iterator code:** `for (auto it = v.begin(); it != v.end(); ++it) { cout << *it; }`
- **Hash collision:** Two different keys produce same hash value → same index
- **Min-heap property:** Parent ≤ children for all nodes
- **Load factor formula:** `elements / buckets`
- **Linear probing problem:** Primary clustering (long sequences of occupied slots)
- **Quadratic probing formula:** `(hash + i²) % table_size`
- **Heapify worst case:** O(log n) - travels from root to leaf
- **Sparse graphs best representation:** Adjacency list (O(V+E) vs O(V²))
- **Priority queue vs hash map:** Use PQ for "most important item", hash map for "value of specific key"
- **Iterator necessity:** Not required for traversal (range-for works), but needed for safe deletion

---

## 💻 **CODING TEMPLATES (Write by Hand!)**

### **1. Vector Iterators (GUARANTEED)**
```cpp
for (auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
}
```

### **2. Hash Table Linear Probing (HIGH PROBABILITY)**
```cpp
void insert(int key) {
    int index = key % size;
    while (occupied[index]) {
        index = (index + 1) % size;
    }
    table[index] = key;
    occupied[index] = true;
}
```

### **3. Graph Adjacency List (GUARANTEED)**
```cpp
class Graph {
    int numVertices;
    vector<vector<int>> adjList;
public:
    Graph(int v) : numVertices(v) { adjList.resize(v); }
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
};
```

### **4. Main Function Template**
```cpp
int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(5, 6);
    return 0;
}
```

---

## ⚡ **COLLISION RESOLUTION QUICK REFERENCE**

### **Linear Probing:**
```cpp
while (occupied[index]) {
    index = (index + 1) % size;
}
```

### **Quadratic Probing:**
```cpp
int i = 0;
while (occupied[(hash + i*i) % size]) {
    i++;
}
int index = (hash + i*i) % size;
```

### **Separate Chaining:**
```cpp
table[key % size].push_back(key);
```

### **Double Hashing:**
```cpp
int hash1 = key % size;
int hash2 = 7 - (key % 7);
int i = 0;
while (occupied[(hash1 + i*hash2) % size]) i++;
int index = (hash1 + i*hash2) % size;
```

---

## 📊 **TIME COMPLEXITIES CHEAT SHEET**

| Operation | Hash Map | Priority Queue | Graph (Adj List) | Vector |
|-----------|----------|----------------|------------------|--------|
| **Insert** | O(1) avg, O(n) worst | O(log n) | O(1) | O(1) amortized |
| **Delete** | O(1) avg, O(n) worst | O(log n) | O(degree) | O(n) |
| **Search** | O(1) avg, O(n) worst | O(n) | O(V+E) | O(n) |
| **Access** | O(1) avg | O(1) top only | N/A | O(1) random |

---

## 🔍 **GRAPH REPRESENTATIONS**

### **Adjacency List:**
```cpp
vector<vector<int>> adjList(V);
// Space: O(V + E), Good for sparse graphs
```

### **Adjacency Matrix:**
```cpp
int adjMatrix[V][V];
// Space: O(V²), Good for dense graphs, O(1) edge check
```

---

## 🎯 **LAST-MINUTE EXAM TIPS**

### **Common Mistakes to Avoid:**
- ❌ Forget `*it` when dereferencing iterators
- ❌ Use `it < v.end()` instead of `it != v.end()`
- ❌ Forget both directions for undirected graphs
- ❌ Mix up heap parent/child formulas
- ❌ Confuse load factor definition

### **Time Management:**
- **T/F Section:** 5 minutes (30 seconds each)
- **Short Answer:** 15 minutes (1.5 minutes each)
- **Vector Iterators:** 3 minutes
- **Hash Insertion:** 8 minutes
- **Graph Class:** 10 minutes

### **Writing Strategy:**
1. **Read entire question** before starting
2. **Write function signature first**
3. **Focus on core algorithm** - don't over-engineer
4. **Use simple arrays** when possible
5. **Test with small example** mentally

---

## 🧠 **MEMORY PALACE - Quick Recall**

- **Load Factor:** "Elements / Buckets" (people in rooms)
- **Linear Probing:** "Next door neighbor" (+1)
- **Quadratic Probing:** "Square dance" (+i²)
- **Double Hashing:** "Two-step formula" (hash1 + i×hash2)
- **Min-Heap:** "Parents are smaller" (parent ≤ children)
- **Graph Adjacency List:** "Phone contact lists" (each person has list of friends)

---

## 🔥 **FINAL CONFIDENCE CHECKLIST**

□ Can write iterator loop from memory  
□ Know all collision resolution formulas  
□ Can implement basic graph class  
□ Remember heap parent/child relationships  
□ Know all time complexities  
□ Understand T/F concept reasoning  
□ Can explain short answer concepts clearly  

---

**🚀 YOU'VE GOT THIS! Trust your preparation and stay calm. Good luck!** 