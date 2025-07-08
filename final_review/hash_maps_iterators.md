# Hash Maps & Iterators

## Conceptual Overview
A **hash map** (hash table) is a data structure that maps keys to values for fast lookup, insertion, and deletion. In C++, the STL provides `std::unordered_map` (hash table, O(1) average) and `std::map` (balanced BST, O(log n)). **Iterators** are objects that allow you to traverse containers (like vectors, lists, maps) in a generic way, similar to pointers.

Hash maps are used when you need to associate unique keys with values and retrieve them efficiently. Iterators are essential for working with STL containers, enabling flexible and efficient data manipulation.

_See: `class_notes/4_maps/hash_maps.md` (Key Concepts, Operations, STL Maps)_

---

## STL Hash Maps: `std::unordered_map`

### Essential Methods & Members
| Method/Member                | Description                                      | Example Usage                                  | Time Complexity (Avg/Worst)         |
|------------------------------|--------------------------------------------------|------------------------------------------------|-------------------------------------|
| `insert(pair)`               | Insert a key-value pair                          | `umap.insert({"a", 1});`                     | O(1) / O(n)                         |
| `operator[]`                 | Access/insert value by key                       | `umap["b"] = 2;`                              | O(1) / O(n)                         |
| `at(key)`                    | Access value by key (throws if not found)        | `umap.at("a")`                                | O(1) / O(n)                         |
| `find(key)`                  | Returns iterator to key or `end()`               | `auto it = umap.find("a");`                  | O(1) / O(n)                         |
| `erase(key/iterator)`        | Remove element by key or iterator                | `umap.erase("a");`                           | O(1) / O(n)                         |
| `size()`                     | Number of elements                              | `umap.size();`                                 | O(1)                                |
| `empty()`                    | Check if map is empty                           | `umap.empty();`                                | O(1)                                |
| `clear()`                    | Remove all elements                             | `umap.clear();`                                | O(n)                                |
| `begin(), end()`             | Iterators to start/end                          | `for (auto it = umap.begin(); it != umap.end(); ++it)` | O(1)                                |

### Tutorial & Examples
```cpp
#include <unordered_map>
#include <iostream>
#include <string>

std::unordered_map<std::string, int> umap;
umap["apple"] = 5; // insert with []
umap.insert({"banana", 10}); // insert with insert()

// Access
std::cout << umap["apple"] << std::endl; // 5
// std::cout << umap.at("pear"); // throws std::out_of_range if not found

// Find
if (umap.find("banana") != umap.end()) {
    std::cout << "banana found!\n";
}

// Erase
umap.erase("apple");

// Iterate (O(n) total to visit all elements)
for (const auto& pair : umap) {
    std::cout << pair.first << ": " << pair.second << std::endl;
}

// Size/Empty
std::cout << "Size: " << umap.size() << std::endl;
if (umap.empty()) std::cout << "Map is empty!\n";

// Clear
umap.clear();
```

---

## STL Iterators

### What is an Iterator?
An iterator is an object (like a pointer) that allows you to traverse a container. All STL containers provide iterators.

### Essential Iterator Operations
| Operation                | Description                        | Example Usage                      | Time Complexity (vector) |
|--------------------------|------------------------------------|------------------------------------|-------------------------|
| `begin(), end()`         | Start/end of container             | `auto it = v.begin();`             | O(1)                    |
| `++it, --it`             | Move to next/previous element      | `++it;`                            | O(1)                    |
| `*it`                    | Access value pointed to            | `int x = *it;`                     | O(1)                    |
| `container.erase(it)`    | Remove element at iterator         | `v.erase(it);`                     | O(n)                    |
| `container.insert(it, x)`| Insert before iterator             | `v.insert(it, 42);`                | O(n)                    |

### Tutorial & Examples
```cpp
#include <vector>
#include <iostream>

std::vector<int> v = {1, 2, 3, 4, 5};
// Iterate with iterator (O(n) total)
for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
}
// Remove even numbers (each erase is O(n), so total is O(n^2) in vector)
for (auto it = v.begin(); it != v.end(); ) {
    if (*it % 2 == 0) it = v.erase(it);
    else ++it;
}
```
_See: `class_notes/4_maps/stl_iterators.cpp`_

---

## Common Pitfalls & Best Practices
- Accessing a non-existent key with `[]` inserts a default value! Use `find` or `at` to check existence.
- Iterators become invalid after erasing elements from a container (except for `std::list`).
- Prefer range-based for loops for simple iteration, but use iterators for insert/erase.
- For custom hash tables, see: `class_notes/4_maps/hash_table_code/hash_table_linear.cpp` and related files.

---

## Practice Problems

### 1. Implement a hash table with linear probing (no STL).
*Hint: Use an array and handle collisions by moving to the next slot.*  
_Reference: `class_notes/4_maps/hash_table_code/hash_table_linear.cpp`_

**Solution:**
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <utility>

class HashTable {
    std::vector<std::pair<int, std::string>> table;
    std::vector<bool> isOccupied;
    int numBuckets;
public:
    HashTable(int buckets) : numBuckets(buckets), table(buckets), isOccupied(buckets, false) {}
    int hashFunction(int key) const { return key % numBuckets; }
    void insert(int key, const std::string &value) {
        int index = hashFunction(key), startIdx = index;
        while (isOccupied[index]) {
            if (table[index].first == key) { table[index].second = value; return; }
            index = (index + 1) % numBuckets;
            if (index == startIdx) { std::cout << "Table is full!\n"; return; }
        }
        table[index] = {key, value}; isOccupied[index] = true;
    }
    std::string get(int key) const {
        int index = hashFunction(key), startIdx = index;
        while (isOccupied[index]) {
            if (table[index].first == key) return table[index].second;
            index = (index + 1) % numBuckets;
            if (index == startIdx) break;
        }
        return "";
    }
};
```

**Related LeetCode Problems:**
- [705. Design HashSet](https://leetcode.com/problems/design-hashset/)
- [706. Design HashMap](https://leetcode.com/problems/design-hashmap/)
- [217. Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)

---

### 2. Write a function that counts word frequencies in a string using `std::unordered_map`.
*Hint: Use `map[word]++` as you iterate through words.*  
_Reference: `class_notes/4_maps/hash_maps.md` (STL Maps section)_

**Solution:**
```cpp
#include <unordered_map>
#include <sstream>
#include <string>
std::unordered_map<std::string, int> countWords(const std::string& text) {
    std::unordered_map<std::string, int> freq;
    std::istringstream iss(text);
    std::string word;
    while (iss >> word) freq[word]++;
    return freq;
}
```

**Related LeetCode Problems:**
- [242. Valid Anagram](https://leetcode.com/problems/valid-anagram/)
- [49. Group Anagrams](https://leetcode.com/problems/group-anagrams/)
- [451. Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/)

---

### 3. Given a vector of integers, use iterators to remove all even numbers.
*Hint: Use `erase` with an iterator loop.*  
_Reference: `class_notes/4_maps/stl_iterators.cpp`_

**Solution:**
```cpp
#include <vector>
#include <iostream>
std::vector<int> removeEvens(std::vector<int>& v) {
    for (auto it = v.begin(); it != v.end(); ) {
        if (*it % 2 == 0) it = v.erase(it);
        else ++it;
    }
    return v;
}
```

**Related LeetCode Problems:**
- [27. Remove Element](https://leetcode.com/problems/remove-element/)
- [203. Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)
- [283. Move Zeroes](https://leetcode.com/problems/move-zeroes/)

---

### 4. Write a function to check if two strings are anagrams using a hash map.
*Hint: Count characters in both strings and compare.*  
_Reference: `class_notes/4_maps/hash_maps.md` (Strings as keys section)_

**Solution:**
```cpp
#include <unordered_map>
#include <string>
bool isAnagram(const std::string& s, const std::string& t) {
    if (s.size() != t.size()) return false;
    std::unordered_map<char, int> count;
    for (char c : s) count[c]++;
    for (char c : t) if (--count[c] < 0) return false;
    return true;
}
```

**Related LeetCode Problems:**
- [242. Valid Anagram](https://leetcode.com/problems/valid-anagram/)
- [49. Group Anagrams](https://leetcode.com/problems/group-anagrams/)
- [567. Permutation in String](https://leetcode.com/problems/permutation-in-string/) 