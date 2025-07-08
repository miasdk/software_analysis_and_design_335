# Priority Queues & Heaps

## Conceptual Overview
A **priority queue** is a data structure where each element has a priority, and elements are served based on priority (not just insertion order). The most common implementation is the **heap** (usually a binary heap). In C++, the STL provides `std::priority_queue` (max-heap by default). Heaps are used for scheduling, simulation, graph algorithms (Dijkstra, Prim), and more.

_See: `class_notes/5_priority_queues/priority_queue.md` (Naïve Implementations, Binary Heaps)_

---

## STL Priority Queue: `std::priority_queue`

### Essential Methods & Members
| Method/Member         | Description                        | Example Usage                                      | Time Complexity |
|-----------------------|------------------------------------|----------------------------------------------------|----------------|
| `push(x)`             | Insert element                     | `pq.push(5);`                                      | O(log n)       |
| `pop()`               | Remove top element                 | `pq.pop();`                                        | O(log n)       |
| `top()`               | Access top element                 | `pq.top();`                                        | O(1)           |
| `size()`              | Number of elements                 | `pq.size();`                                       | O(1)           |
| `empty()`             | Check if empty                     | `pq.empty();`                                      | O(1)           |
| `emplace(args...)`    | Construct and insert in-place      | `pq.emplace(7);`                                   | O(log n)       |

**Note:** By default, `std::priority_queue` is a max-heap. For a min-heap, use:
```cpp
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
```

---

## Tutorial & Examples
```cpp
#include <queue>
#include <vector>
#include <iostream>

std::priority_queue<int> maxHeap; // max-heap
maxHeap.push(10);
maxHeap.push(2);
maxHeap.push(15);
std::cout << maxHeap.top() << std::endl; // 15
maxHeap.pop();

std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // min-heap
minHeap.push(10);
minHeap.push(2);
minHeap.push(15);
std::cout << minHeap.top() << std::endl; // 2
```

---

## Common Pitfalls & Best Practices
- `std::priority_queue` is a max-heap by default; use `std::greater<>` for min-heap.
- No direct way to remove arbitrary elements or update priorities (use a custom heap or other structure if needed).
- Iterating over a priority queue is not supported (must pop elements to access them).
- For custom heaps, see: `class_notes/5_priority_queues/min_heap.h` and `main_for_heap.cpp`.

---

## Practice Problems

### 1. Use a priority queue to sort a list of numbers (heap sort).
*Hint: Push all numbers, then pop in order.*  
_Reference: `class_notes/5_priority_queues/main_for_heap.cpp`_

**Solution:**
```cpp
#include <queue>
#include <vector>
#include <iostream>
std::vector<int> heapSort(const std::vector<int>& nums) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap(nums.begin(), nums.end());
    std::vector<int> sorted;
    while (!minHeap.empty()) {
        sorted.push_back(minHeap.top());
        minHeap.pop();
    }
    return sorted;
}
```
**Related LeetCode Problems:**
- [215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)
- [703. Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/)
- [347. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)

---

### 2. Simulate a task scheduler where tasks with lower numbers have higher priority.
*Hint: Use a min-heap or priority queue.*  
_Reference: `class_notes/5_priority_queues/priority_queue.md`_

**Solution:**
```cpp
#include <queue>
#include <vector>
#include <iostream>
struct Task {
    int priority;
    std::string name;
    bool operator>(const Task& other) const { return priority > other.priority; }
};
int main() {
    std::priority_queue<Task, std::vector<Task>, std::greater<Task>> pq;
    pq.push({2, "Task A"});
    pq.push({1, "Task B"});
    pq.push({3, "Task C"});
    while (!pq.empty()) {
        std::cout << pq.top().name << "\n";
        pq.pop();
    }
}
```
**Related LeetCode Problems:**
- [621. Task Scheduler](https://leetcode.com/problems/task-scheduler/)
- [502. IPO](https://leetcode.com/problems/ipo/)

---

### 3. Given a stream of numbers, always print the kth smallest number so far.
*Hint: Use two heaps (min and max) to maintain order.*  
_Reference: `class_notes/5_priority_queues/priority_queue.md`_

**Solution:**
```cpp
#include <queue>
#include <vector>
class KthSmallest {
    std::priority_queue<int> maxHeap;
    int k;
public:
    KthSmallest(int k_) : k(k_) {}
    void add(int num) {
        maxHeap.push(num);
        if (maxHeap.size() > k) maxHeap.pop();
    }
    int getKthSmallest() const { return maxHeap.top(); }
};
```
**Related LeetCode Problems:**
- [703. Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/)
- [295. Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)

---

### 4. (Exam-style) Given the following code, what is the output?
```cpp
std::priority_queue<int> pq;
pq.push(3); pq.push(1); pq.push(4); pq.push(2);
while (!pq.empty()) {
    std::cout << pq.top() << " ";
    pq.pop();
}
```
**Solution:**
Output: `4 3 2 1` (max-heap: largest first)

---

### 5. (Exam-style) What is the time complexity of inserting n elements into an empty heap one by one?
**Solution:**
Each insertion is O(log n), so total is O(n log n).

---

### 6. (Conceptual) When would you use a heap over a balanced BST?
**Solution:**
Use a heap when you only need quick access to the largest/smallest element (priority queue), not full ordering or fast arbitrary removal. Use a BST if you need ordered iteration or fast removal of arbitrary elements.

---

## References
- _See: `class_notes/5_priority_queues/priority_queue.md`, `min_heap.h`, `main_for_heap.cpp`_
- [C++ Reference: std::priority_queue](https://en.cppreference.com/w/cpp/container/priority_queue)

## Key Concepts
- Priority queue: serves elements by priority  
  _See: `class_notes/5_priority_queues/priority_queue.md` (Naïve Implementations)_
- Min-heap: parent ≤ children, root is minimum  
  _See: `class_notes/5_priority_queues/priority_queue.md` (Binary Heaps section)_
- Array representation: left child 2k, right child 2k+1, parent k/2  
  _See: `class_notes/5_priority_queues/priority_queue.md` (Binary Heaps section)_
- STL: `std::priority_queue` (max-heap by default)  
  _See: `class_notes/5_priority_queues/priority_queue.md` (Algorithms section)_

## Example Code
```cpp
// From class_notes/5_priority_queues/min_heap.h
MinHeap<int> heap;
heap.insert(10);
heap.insert(-3);
heap.insert(17);
heap.print();
heap.deleteMin();
```

### 1. Implement a min-heap from scratch (array-based, no STL).
*Hint: Use percolate up/down for insert/deleteMin.*  
_Reference: `class_notes/5_priority_queues/min_heap.h`_

### 2. Use a priority queue to sort a list of numbers.
*Hint: Push all numbers, then pop in order.*  
_Reference: `class_notes/5_priority_queues/main_for_heap.cpp`_

### 3. Simulate a task scheduler where tasks with lower numbers have higher priority.
*Hint: Use a min-heap or priority queue.*  
_Reference: `class_notes/5_priority_queues/priority_queue.md`_

### 4. Given a stream of numbers, always print the kth smallest number so far.
*Hint: Use two heaps (min and max) to maintain order.*  
_Reference: `class_notes/5_priority_queues/priority_queue.md`_ 