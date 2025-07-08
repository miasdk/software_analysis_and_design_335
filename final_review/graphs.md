# Graphs

## Conceptual Overview
A **graph** is a collection of nodes (vertices) and connections (edges) between them. Graphs can be directed or undirected, weighted or unweighted. They are used to model networks, relationships, and many real-world problems. In C++, graphs are often represented using adjacency lists or matrices. STL containers like `std::vector`, `std::list`, and `std::queue` are commonly used for graph algorithms.

_See: `class_notes/6_graphs/graphs.md` (What Is a Graph?, Types, Representations)_

---

## Graph Representation in C++

### Adjacency List (most common)
```cpp
std::vector<std::vector<int>> adjList(V);
void addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); // omit for directed
}
```
- **Space:** O(V + E)
- **Edge existence check:** O(degree)

### Adjacency Matrix
```cpp
std::vector<std::vector<int>> adjMat(V, std::vector<int>(V, 0));
adjMat[u][v] = 1; // or weight
```
- **Space:** O(V^2)
- **Edge existence check:** O(1)

---

## STL/Standard Methods & Members for Graph Algorithms
| Container/Method         | Description                        | Example Usage                      | Time Complexity |
|-------------------------|------------------------------------|------------------------------------|----------------|
| `std::vector`           | Dynamic array (adjacency list)     | `v.push_back(x);`                  | O(1) amortized |
| `std::queue`            | FIFO queue (BFS)                   | `q.push(x); q.front(); q.pop();`   | O(1)           |
| `std::stack`            | LIFO stack (DFS)                   | `s.push(x); s.top(); s.pop();`     | O(1)           |
| `std::list`             | Doubly-linked list                 | `l.push_back(x); l.remove(x);`     | O(1)           |
| `std::unordered_set`    | Fast lookup for visited nodes       | `visited.insert(x);`               | O(1)           |

---

## Tutorial & Examples
**BFS (Breadth-First Search):**
```cpp
#include <vector>
#include <queue>
#include <iostream>
void BFS(int start, const std::vector<std::vector<int>>& adjList, std::vector<bool>& visited) {
    std::queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        std::cout << u << " ";
        for (int v : adjList[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
```
**DFS (Depth-First Search):**
```cpp
void DFS(int u, const std::vector<std::vector<int>>& adjList, std::vector<bool>& visited) {
    visited[u] = true;
    std::cout << u << " ";
    for (int v : adjList[u]) {
        if (!visited[v]) {
            DFS(v, adjList, visited);
        }
    }
}
```

---

## Common Pitfalls & Best Practices
- For undirected graphs, always add both `adjList[u].push_back(v)` and `adjList[v].push_back(u)`.
- Always mark nodes as visited to avoid infinite loops in BFS/DFS.
- For weighted graphs, use `std::pair<int, int>` or a struct for adjacency lists.
- For large, sparse graphs, prefer adjacency lists over matrices.
- For graph algorithms (Dijkstra, Kruskal), see: `class_notes/6_graphs/graph_extended.cpp` and `extra_topics/DisjSets.h`.

---

## Practice Problems

### 1. Implement DFS and BFS for an undirected graph.
*Hint: Use recursion for DFS, queue for BFS.*  
_Reference: `class_notes/6_graphs/graphs.md` (Graph Traversal section)_

**Solution:**
See code examples above.

**Related LeetCode Problems:**
- [200. Number of Islands](https://leetcode.com/problems/number-of-islands/)
- [133. Clone Graph](https://leetcode.com/problems/clone-graph/)
- [994. Rotting Oranges](https://leetcode.com/problems/rotting-oranges/)

---

### 2. Detect if a graph has a cycle (undirected).
*Hint: Use DFS and track parent nodes.*  
_Reference: `class_notes/6_graphs/graphs.md`_

**Solution:**
```cpp
bool hasCycle(int u, int parent, const std::vector<std::vector<int>>& adjList, std::vector<bool>& visited) {
    visited[u] = true;
    for (int v : adjList[u]) {
        if (!visited[v]) {
            if (hasCycle(v, u, adjList, visited)) return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}
```
**Related LeetCode Problems:**
- [261. Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/)
- [684. Redundant Connection](https://leetcode.com/problems/redundant-connection/)

---

### 3. Find the shortest path from node A to B in an unweighted graph.
*Hint: Use BFS and track predecessors.*  
_Reference: `class_notes/6_graphs/graphs.md` (BFS section)_

**Solution:**
```cpp
#include <vector>
#include <queue>
#include <iostream>
std::vector<int> shortestPath(int start, int end, const std::vector<std::vector<int>>& adjList) {
    std::vector<int> pred(adjList.size(), -1);
    std::vector<bool> visited(adjList.size(), false);
    std::queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == end) break;
        for (int v : adjList[u]) {
            if (!visited[v]) {
                visited[v] = true;
                pred[v] = u;
                q.push(v);
            }
        }
    }
    // Reconstruct path
    std::vector<int> path;
    for (int at = end; at != -1; at = pred[at]) path.push_back(at);
    std::reverse(path.begin(), path.end());
    if (path.front() != start) return {}; // no path
    return path;
}
```
**Related LeetCode Problems:**
- [127. Word Ladder](https://leetcode.com/problems/word-ladder/)
- [752. Open the Lock](https://leetcode.com/problems/open-the-lock/)

---

### 4. Implement Kruskal's algorithm for MST.
*Hint: Sort edges, use Disjoint Set (Union-Find).*  
_Reference: `class_notes/6_graphs/graph_extended.cpp`, `extra_topics/DisjSets.h`_

**Solution:**
See `class_notes/6_graphs/graph_extended.cpp` for a full implementation. Key steps:
- Sort all edges by weight
- Use Disjoint Set to avoid cycles
- Add smallest edge that doesn't form a cycle until MST is complete

**Related LeetCode Problems:**
- [1135. Connecting Cities With Minimum Cost](https://leetcode.com/problems/connecting-cities-with-minimum-cost/)
- [1584. Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/)

---

### 5. Given a weighted directed graph, implement Dijkstra's algorithm.
*Hint: Use a min-heap for distances.*  
_Reference: `class_notes/6_graphs/graph_extended.cpp`_

**Solution:**
See `class_notes/6_graphs/graph_extended.cpp` for a full implementation. Key steps:
- Use a min-heap (priority queue) to always expand the closest node
- Update distances as you find shorter paths

**Related LeetCode Problems:**
- [743. Network Delay Time](https://leetcode.com/problems/network-delay-time/)
- [787. Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)

---

## References
- _See: `class_notes/6_graphs/graphs.md`, `graph_extended.cpp`, `extra_topics/DisjSets.h`_
- [C++ Reference: std::vector](https://en.cppreference.com/w/cpp/container/vector)
- [C++ Reference: std::queue](https://en.cppreference.com/w/cpp/container/queue)
- [C++ Reference: std::list](https://en.cppreference.com/w/cpp/container/list) 