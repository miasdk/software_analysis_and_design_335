# Chapter 1. C++ Preliminaries

## table of contents
1. Initialization Lists
2. Lvalues, Rvalues, and Reference Variables in C++
3. Default Arguments
4. Big 5


## Initialization Lists
An initialization list in C++ is a way to initialize data members of a class before entering the body of the constructor. It's used to provide values to the data members directly, which is often more efficient and sometimes required, especially when dealing with const or reference members.

Here's the basic syntax of an initialization list in a constructor:

```cpp
// Syntax using initialization list
ClassName(type1 param1, type2 param2) : member1(param1), member2(param2) 
{
    // Constructor body
}

// Syntax not using initialization list
ClassName(type1 param1, type2 param2) 
{
    member1=param1;
    member2=param2;    
}
```

The part after the colon (:) is called the initialization list, where you directly initialize the member variables. Here's a more detailed example:

```cpp
class Example {
private:
    int a;
    int b;
    const int c;     // Const member
    int &ref;        // Reference member

public:
    // Constructor with an initialization list
    Example(int x, int y, int z, int& reference) : a(x), b(y), c(z), ref(reference) {
        // The constructor body can still perform other operations if needed
    }

    void display() {
        std::cout << "a: " << a << ", b: " << b << ", c: " << c << ", ref: " << ref << std::endl;
    }
};
```


### Why Use Initialization Lists?
* Efficiency: Initialization lists can be more efficient than assigning values inside the constructor body because the members are initialized directly, rather than being default-initialized and then assigned new values.

* Const and Reference Members: Const members and reference members must be initialized at the time of their creation. They cannot be assigned new values after they've been constructed, so initialization lists are required.


## Lvalues, Rvalues, and Reference Variables in C++
Understanding lvalues, rvalues, and reference variables in C++ is crucial for mastering memory management, function parameter passing, and efficient code design. Let's break them down.

### Lvalues vs. Rvalues
* Lvalue (Left Value): An object that persists beyond a single expression and has an identifiable memory address.
* Rvalue (Right Value): A temporary object or value that does not persist beyond the expression it is used in.

**Examples**
```cpp
int x = 10;   // 'x' is an lvalue (has memory storage)
x = 20;       // Valid: 'x' can appear on the left side of '='

int y = x + 5; // 'x + 5' is an rvalue (temporary result)
10 = x;        //  Error: '10' is an rvalue, cannot be assigned to
```

#### Lvalue and Rvalue Functions
```cpp
int getValue() { return 42; } // Returns an rvalue

int& getReference(int& a) { return a; } // Returns an lvalue reference
```
* ```getValue()``` returns a temporary value (rvalue).
* ```getReference()``` returns an lvalue reference.

### Lvalue References (T&)
A reference variable (lvalue reference) allows modifying the original object.

```cpp
int a = 5;
int& ref = a;  // 'ref' is an lvalue reference to 'a'
ref = 10;      // Modifies 'a'

int& invalidRef = 10; //  Error: Cannot bind lvalue reference to rvalue
```

### Rvalue References (T&&)
C++11 introduced rvalue references (```T&&```), allowing us to bind to temporary objects and enable move semantics.

```cpp
int&& rref = 10; // rvalue reference binds to a temporary value
rref = 20;       // Modifies the rvalue

int&& anotherRref = getValue(); // OK, function returns an rvalue
```


### ```const``` and References
#### Lvalue Reference to const (const T&)
Allows binding an rvalue to an lvalue reference without modification.

```cpp
const int& ref = 10; // OK: Read-only reference to rvalue
ref = 20;           //  Error: Cannot modify a `const` reference
```

#### Rvalue Reference to const (```const T&&```)
Not commonly used but can be useful in some cases:

```cpp
void func(const int&& x) {
    std::cout << x << std::endl;
}
func(42); // Works with rvalues only
```


## Default Arguments
In C++, default arguments are values that are automatically used by a function if no corresponding arguments are passed to it during a function call. This feature makes functions more flexible and allows them to handle multiple scenarios without the need for multiple overloads.

### How Default Arguments Work
Default arguments are specified in the function declaration, and they are used if the caller does not supply values for those parameters. Here's an example of the syntax:

```cpp
void greet(const std::string &name = "Guest") {
    std::cout << "Hello, " << name << "!" << std::endl;
}
```
In this example, the function greet() can be called with or without an argument:

* If no argument is provided, it uses the default value "Guest".
* If an argument is provided, it uses that value.

### Example Usage of Default Arguments
Here is a practical example using multiple default arguments:

```cpp
#include <iostream>

// Function declaration with default arguments
void introduce(const std::string &name = "John Doe", int age = 30, const std::string &country = "USA") {
    std::cout << "Name: " << name << ", Age: " << age << ", Country: " << country << std::endl;
}

int main() {
    introduce();                      // Uses all default arguments
    introduce("Alice");               // Uses defaults for age and country
    introduce("Bob", 25);             // Uses default for country
    introduce("Charlie", 28, "UK");   // No default arguments used
    return 0;
}
```
#### Output:

```yaml
Name: John Doe, Age: 30, Country: USA
Name: Alice, Age: 30, Country: USA
Name: Bob, Age: 25, Country: USA
Name: Charlie, Age: 28, Country: UK
```


### Rules for Using Default Arguments
Order of Parameters: Default arguments must be specified from right to left. You can't have a non-default parameter after a default parameter.

```cpp
void display(int x = 5, int y = 10); // Valid
void show(int x = 5, int y);         // Invalid: non-default parameter after a default one
```
Default arguments are typically specified in the function declaration (often found in header files) rather than in the function definition. This ensures the defaults are visible to all parts of the code.


## big 5

###  What is the Rule of Five?
In modern C++ (C++11 and later), if your class **manages resources** (like heap memory, file handles, sockets, etc.), you should define **five special member functions**. These ensure correct and efficient **copying** and **moving** of objects.

### The Big Five (Special Member Functions)

1. Copy Constructor
   - Purpose: Defines how to **copy construct** from another object.
   - Signature:
     MyClass(const MyClass& other);

2. Copy Assignment Operator
   - Purpose: Defines how to **assign** from another object.
   - Signature:
     MyClass& operator=(const MyClass& other);

3. Move Constructor
   - Purpose: Allows ownership of resources to be **moved** instead of copied.
   - Signature:
     MyClass(MyClass&& other);

4. Move Assignment Operator
   - Purpose: Allows move **assignment** of resources.
   - Signature:
     MyClass& operator=(MyClass&& other);

5. Destructor
   - Purpose: Cleans up owned resources.
   - Signature:
     ~MyClass();

If you define **any** of these manually, it's best to **define all five**, to avoid unexpected behavior (this is the "Rule of Five").

###  What is `std::move`?

- `std::move(obj)` **does not move anything** by itself.
- It **casts** the object `obj` to an **rvalue reference**, which **enables move semantics**.
- Use it when you want to **explicitly transfer ownership** of a resource.

Example:
MyClass a;
MyClass b = std::move(a); // Calls move constructor

Without `std::move`, the compiler treats `a` as an lvalue, and would call the **copy constructor** instead.

###  Example Class with Rule of Five
```c++
class MyClass {
private:
    int* data;

public:
    // Constructor
    MyClass(int val) : data(new int(val)) {}

    // Copy Constructor
    MyClass(const MyClass& other) : data(new int(*other.data)) {}

    // Copy Assignment
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }

    // Move Constructor
    MyClass(MyClass&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    // Move Assignment
    MyClass& operator=(MyClass&& other) noexcept {
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    // Destructor
    ~MyClass() {
        delete data;
    }
};
```

### Why Use `std::move` and Move Semantics?

- Avoid **deep copies** and unnecessary allocations.
- Essential for **performance** in modern C++ (e.g., returning large containers).
- Used heavily in STL containers (e.g., `std::vector`, `std::map`).
