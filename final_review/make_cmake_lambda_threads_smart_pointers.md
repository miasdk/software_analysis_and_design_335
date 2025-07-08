# Make/CMake, Lambda, Threads, Smart Pointers

## Conceptual Overview
- **Make/CMake:** Tools for automating the build process. Make uses Makefiles to define build rules; CMake generates platform-specific build files (e.g., Makefiles, Visual Studio projects).
- **Lambda:** Anonymous functions in C++ (since C++11), useful for short, inline operations, especially with STL algorithms.
- **Threads:** Allow concurrent execution of code. C++11 introduced `std::thread` for portable multithreading.
- **Smart Pointers:** Modern C++ memory management tools (`unique_ptr`, `shared_ptr`, `weak_ptr`) that help prevent memory leaks and dangling pointers.

---

## Make/CMake Quick Reference
- **Makefile**: Defines build rules. Example:
  ```makefile
  CXX = g++
  CXXFLAGS = -std=c++17 -Wall
  all: main
  main: main.o foo.o
  	$(CXX) $(CXXFLAGS) -o main main.o foo.o
  clean:
  	rm -f *.o main
  ```
- **CMakeLists.txt**: Used by CMake to generate build files. Example:
  ```cmake
  cmake_minimum_required(VERSION 3.10)
  project(MyProject)
  add_executable(main main.cpp foo.cpp)
  ```

---

## Lambda Functions in C++
| Syntax/Method         | Description                        | Example Usage                                  | Time Complexity |
|-----------------------|------------------------------------|------------------------------------------------|----------------|
| `[capture](args){}`   | Basic lambda syntax                | `auto f = [](int x){return x+1;};`             | O(1)           |
| `std::sort` with lambda| Custom comparator                 | `std::sort(v.begin(), v.end(), [](int a, int b){return a<b;});` | O(n log n) |

**Example:**
```cpp
auto add = [](int a, int b) { return a + b; };
std::cout << add(2, 3);
```

---

## Threads in C++
| Method/Member         | Description                        | Example Usage                                  | Time Complexity |
|-----------------------|------------------------------------|------------------------------------------------|----------------|
| `std::thread`         | Create a new thread                | `std::thread t(func);`                         | O(1)           |
| `join()`              | Wait for thread to finish          | `t.join();`                                    | O(1)           |
| `detach()`            | Run thread independently           | `t.detach();`                                  | O(1)           |

**Example:**
```cpp
#include <thread>
void func() { /* ... */ }
std::thread t(func);
t.join();
```

---

## Smart Pointers in C++
| Type                  | Description                        | Example Usage                                  | Time Complexity |
|-----------------------|------------------------------------|------------------------------------------------|----------------|
| `unique_ptr<T>`       | Sole ownership, auto deletes       | `auto p = std::make_unique<int>(5);`           | O(1)           |
| `shared_ptr<T>`       | Reference-counted shared ownership | `auto p = std::make_shared<int>(5);`           | O(1)           |
| `weak_ptr<T>`         | Non-owning reference to shared_ptr | `std::weak_ptr<int> w = p;`                    | O(1)           |

**Example:**
```cpp
#include <memory>
auto ptr = std::make_unique<int>(5);
```
**Array Example (from extra_topics/smart_pointers.cpp):**
```cpp
unique_ptr<array<int, 3>[]> arr2 = make_unique<array<int,3>[]>(3);
arr2[0]={1,11,111};
```

---

## Common Pitfalls & Best Practices
- Always call `join()` or `detach()` on threads, or your program may terminate unexpectedly.
- Use lambdas for short, local operations; avoid overusing for complex logic.
- Prefer `unique_ptr` for exclusive ownership, `shared_ptr` only when needed.
- Avoid raw `new`/`delete` in modern C++.
- For more, see: `extra_topics/smart_pointers.cpp` and your course Makefile/CMake examples.

---

## Practice Problems

### 1. Write a Makefile to compile a program with two source files and one header.
*Hint: Use variables for compiler and flags.*

**Solution:**
```makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall
all: main
main: main.o foo.o
	$(CXX) $(CXXFLAGS) -o main main.o foo.o
clean:
	rm -f *.o main
```

---

### 2. Use a lambda to sort a vector of pairs by the second element.
*Hint: Pass a custom comparator to `std::sort`.*

**Solution:**
```cpp
#include <vector>
#include <algorithm>
#include <iostream>
std::vector<std::pair<int, int>> v = {{1,3},{2,2},{3,1}};
std::sort(v.begin(), v.end(), [](const auto& a, const auto& b){ return a.second < b.second; });
for (const auto& p : v) std::cout << p.first << "," << p.second << " ";
```
**Related LeetCode Problems:**
- [1122. Relative Sort Array](https://leetcode.com/problems/relative-sort-array/)
- [56. Merge Intervals](https://leetcode.com/problems/merge-intervals/)

---

### 3. Create a thread that prints numbers from 1 to 10.
*Hint: Use a function or lambda with `std::thread`.*

**Solution:**
```cpp
#include <thread>
#include <iostream>
int main() {
    std::thread t([](){
        for (int i = 1; i <= 10; ++i) std::cout << i << " ";
    });
    t.join();
}
```
**Related LeetCode Problems:**
- [1114. Print in Order](https://leetcode.com/problems/print-in-order/) (threading)
- [1115. Print FooBar Alternately](https://leetcode.com/problems/print-foobar-alternately/)

---

### 4. Write a function that returns a `unique_ptr` to an array of integers.
*Hint: Use `std::make_unique<int[]>(size)`.*
_Reference: `extra_topics/smart_pointers.cpp`_

**Solution:**
```cpp
#include <memory>
#include <iostream>
std::unique_ptr<int[]> makeArray(int n) {
    return std::make_unique<int[]>(n);
}
```
**Related LeetCode Problems:**
- [No direct LeetCode, but see C++ memory management interview questions.]

---

## References
- _See: `extra_topics/smart_pointers.cpp`, your course Makefile/CMake examples_
- [C++ Reference: std::thread](https://en.cppreference.com/w/cpp/thread/thread)
- [C++ Reference: std::unique_ptr](https://en.cppreference.com/w/cpp/memory/unique_ptr)
- [C++ Reference: Lambda expressions](https://en.cppreference.com/w/cpp/language/lambda)
