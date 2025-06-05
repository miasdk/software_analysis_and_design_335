# Chapter 2: Mathematical Concepts and Performance Measures

## 1 Notation

To compare algorithm efficiency, we study how functions grow. For example:

- $f(x) = x^2$  
- $g(x) = x^3$  
- $h(x) = 5x^2$

Although $h(x) = 5f(x)$ grows faster than $f(x)$ by a constant factor, both grow at the same *rate* asymptotically. Meanwhile, $g(x)$ outgrows both. So we want a way to classify functions by their rate of growth, ignoring constant factors.

---

## 2 Definitions of Asymptotic Rates of Growth

### Big O

$$
t(n) \in O(f(n)) \text{ if } \exists \ m \geq 0, c \geq 0 \text{ such that } t(n) \leq c \cdot f(n) \text{ for all } n \geq m
$$

Big-O describes functions that grow **no faster than** $f(n)$.

---

### Big Omega

$$
t(n) \in \Omega(f(n)) \text{ if } \exists \ m \geq 0, c > 0 \text{ such that } t(n) \geq c \cdot f(n) \text{ for all } n \geq m
$$

Big-Omega describes functions that grow **no slower than** $f(n)$.

---

### Big Theta

$$
t(n) \in \Theta(f(n)) \iff t(n) \in O(f(n)) \text{ and } t(n) \in \Omega(f(n))
$$

Theta represents functions that grow at **the same rate** as $f(n)$.

---

### Little o

$$
t(n) \in o(f(n)) \iff t(n) \in O(f(n)) \text{ and } t(n) \notin \Theta(f(n))
$$

Little-o represents functions that grow **strictly slower** than $f(n)$.

---

### Little omega

$$
t(n) \in \omega(f(n)) \iff t(n) \in \Omega(f(n)) \text{ and } t(n) \notin \Theta(f(n))
$$

Little-omega represents functions that grow **strictly faster** than $f(n)$.

---

## Implications

**Lemma:** If $t(n) \in O(f(n))$ and $s(n) \in O(g(n))$, then:
1. $s(n) + t(n) \in O(f(n) + g(n))$  
2. $s(n) \cdot t(n) \in O(f(n) \cdot g(n))$
3. $O(f(n)) \subseteq \Omega(f(n)) \land \Omega(f(n)) \subseteq O(f(n)) \Rightarrow \Theta(f(n))$

---

If you can't tell by looking at two functions which is grows faster, use the following formula:
$$
\lim_{n \to \infty} \frac{f(n)}{g(n)} =
\begin{cases}
0 & \Rightarrow f(n) \in o(g(n)) \\
c \neq 0 & \Rightarrow f(n) \in \Theta(g(n)) \\
\infty & \Rightarrow f(n) \in \omega(g(n))
\end{cases}
$$

---
### Rules for Simplifying Big O Notation

Big O notation describes the upper bound of an algorithm’s growth rate. When simplifying, we focus on the **dominant term** and ignore constants or less significant terms. Below are the standard rules:

---

### 1. **Drop Constants**
- Ignore multiplicative constants.
- Example:
  ```
  O(3n) → O(n)
  O(100) → O(1)
  ```

---

### 2. **Drop Non-Dominant Terms**
- Keep only the term with the fastest growth as `n → ∞`.
- Example:
  ```
  O(n + log n) → O(n)
  O(n^2 + n) → O(n^2)
  O(n^3 + 100n^2 + 500) → O(n^3)
  ```

---

### 3. **Use Simplest Form**
- Simplify mathematical expressions.
- Example:
  ```
  O(2n^2 + 3n^2) → O(5n^2) → O(n^2)
  ```

---

### 4. **Multiplicative Behavior**
- Nested loops or combined independent steps multiply.
- Example:
  ```
  O(n) * O(log n) → O(n log n)
  ```

---

### 5. **Transitivity**
- If f(n) ∈ O(g(n)) and g(n) ∈ O(h(n)), then f(n) ∈ O(h(n)).

---

### 6. **Ignore Lower-Order Terms in Polynomials**
- A polynomial function's highest-degree term dominates growth.
- Example:
  ```
  O(n^4 + n^3 + n^2 + n + 1) → O(n^4)
  ```

---

### 7. **Logarithm Base Doesn't Matter**
- All logarithms grow similarly with constant factor differences.
- Example:
  ```
  O(log₂ n) = O(log₁₀ n) = O(log n)
  ```

---

## Summary Table

| Rule                      | Example                       | Result        |
|---------------------------|-------------------------------|---------------|
| Drop constants            | O(5n)                         | O(n)          |
| Drop lower-order terms    | O(n^2 + n)                    | O(n^2)        |
| Simplify expressions      | O(3n^2 + 2n^2)                | O(n^2)        |
| Log base irrelevant       | O(log₂ n)                     | O(log n)      |
| Product of terms          | O(n) * O(log n)               | O(n log n)    |


---

## Some Growth Rate Relationships

$$
c < \log N < \log^k N < N < N \log N < N^2 < N^3 < N^{3+k} < 2^N < 3^N < \ldots < N!
$$

---


## Model of Computation

We assume a theoretical Von Neumann machine with:
- Infinite memory
- Constant-time scalar operations
- Sequential execution

* The goal for time complexity is to count the number of steps in terms of the input size, an algorithm takes to complete.
* The goal for space complexity is to count the amount of additional memory(input not included in analysis) in terms of the input size, an algorithm needs to complete.
---

### Input Size

Defined by the number of data elements. For example:
- Sorting: input size = number of items
- String search: input size = lengths of both strings

---

### What to Analyze

Focus is typically on:
- $T_{\text{best}}(N)$: best-case and gives us Big theta
- $T_{\text{worst}}(N)$: worst-case and gives us Big 0
- $T_{\text{avg}}(N)$: average case 
- $T_{\text{expected}}(N)$: expected time (weighted average, often impractical)

---

### How to Analyze

#### For Loops
Time = iterations × time per body execution

#### Nested Loops
Time = product of iteration counts × time per body

#### Consecutive Statements
Time = sum of statement times; report the dominant term

#### If/Else
Time = time for condition + max(time of true branch, false branch)

#### Function Calls
Recursive calls need recurrence relations to solve time complexity


## Definitions
### t_best (Best Time Complexity):
This usually refers to the best time taken over all possible inputs of a given size. 

### t_worst (Worst Time Complexity):
This usually refers to the worst time taken over all possible inputs of a given size. 

### t_avg (Average Time Complexity):  
This usually refers to the average time taken over all possible inputs of a given size. It assumes a uniform distribution of inputs unless specified otherwise.

### t_expected (Expected Time Complexity):  
This refers to the expected value of the running time, given a probability distribution over the inputs. It takes into account the likelihood of each input occurring.

In simple cases (uniform probability), t_avg and t_expected may be the same, but they differ when the input distribution is non-uniform.

### Example: Find Max in an Array  
Suppose we have a function that finds the maximum element in an array of n elements:

```cpp
int find_max(vector<int> arr):
    int max_val = arr[0];
    for(auto& val: arr)
        if (val > max_val) 
            max_val = val;
    return max_val;
```

**Best-case Time:**<br>
Always does n-1 comparisons → $\Omega(n)$

**Worst-case Time:** 
Always does n-1 comparisons → $O(n)$


**t_avg (Average Time)**  
If we look at all n! permutations of the input (assuming all permutations equally likely), the algorithm still always compares n-1 elements. So:

t_avg = n - 1

Because regardless of values, the loop executes n-1 times, comparing each.

But if we consider a modified algorithm that tries to return early when it finds the maximum early (which isn’t possible here), then t_avg could be lower depending on structure.

**t_expected (Expected Time):**  
Now, imagine a different model: suppose you have a randomized algorithm or an input distribution where the max is more likely to be near the beginning.

Let’s say:

- The max is at position i with probability p_i.
- The algorithm stops scanning once it finds the max.

Then:

t_expected = Σ p_i × (i+1) (since it checks i+1 elements to reach index i)

This gives a weighted average based on probabilities.

Summary Comparison  

| Aspect     | t_avg                       | t_expected                                 |
|------------|-----------------------------|---------------------------------------------|
| Assumption | Uniform input distribution  | Known (or assumed) probability distribution |
| Purpose    | Typical-case analysis       | Probabilistic expected behavior             |
| Same result? | Only if input distribution is uniform | Not necessarily                    |


## Find String in Array: t_avg vs t_expected

### Problem Setup

We define the following linear search function:

```cpp
int find_string(vector<int> arr, string target):
    for(int i =0; i<arr.size(); i++)
        if (arr[i] == target)
            return i;
    return -1;
```

This searches from left to right and returns the index if the target string is found, or -1 if not.

---
### t_best — Best Time
Is the case where the element is in the first index arr[0], where it takes only one step to find O(1)

### t_worst — Worst Time
Is the case where the element is in the last index arr[n-1], where it takes n steps to find $O(n)$ 

### t_avg — Average Time (Uniform Distribution)

Assumptions:
- Array `arr` has `n` strings.
- The target string is **guaranteed to be present**.
- The target is **equally likely** to be at any index from `0` to `n-1`.

If the target is at index `i`, it takes `i+1` comparisons to find it.

So:
$$
t_{\text{avg}} = \frac{1}{n} \sum_{i=0}^{n-1} (i+1) 
= \frac{1}{n} \sum_{i=1}^{n} i 
= \frac{1}{n} \cdot \frac{n(n+1)}{2} 
= \frac{n+1}{2}
$$


So under a uniform distribution:
```
t_avg = (n + 1)/2 comparisons
```

---

### t_expected — Expected Time (Non-uniform Distribution)

Assumptions:
- The target is guaranteed to be present.
- It is **not** equally likely to be at each index.
- Let `p_i` be the probability that the target is at index `i`.

Then:
$$
t_{\text{expected}} = \sum_{i=0}^{n-1} p_i \cdot (i + 1)
$$


### Example:

Let `n = 4` and the target probabilities be: `p = [0.4, 0.3, 0.2, 0.1]`

Then:
$$
\begin{aligned}
t_{\text{expected}} &= 0.4 \cdot 1 + 0.3 \cdot 2 + 0.2 \cdot 3 + 0.1 \cdot 4 \\
                    &= 0.4 + 0.6 + 0.6 + 0.4 \\
                    &= 2.0 \text{ comparisons}
\end{aligned}
$$


This is better than the uniform average:
```
t_avg = (4 + 1)/2 = 2.5
```

---


## Data Structure Operations: Complexity Table: Insert and Delete  
This table shows **space** and **time complexities** for `insert` and `delete` operations in **vector (array)**, **linked list**, and **binary tree**.  
It includes **worst case**, **best case**, **average case**, and **expected case** where applicable.

| Data Structure | Operation | Case        | Time Complexity     | Space Complexity |
|----------------|-----------|-------------|----------------------|------------------|
| **Vector (Array)** | Insert    | Best        | O(1) (append)        | O(1)             |
|                |           | Worst       | O(n) (insert at front or middle) | O($2^{\lceil log(n) \rceil}$)             |
|                |           | Average     | O(n)                 | O(1)             |
|                |           | Expected    | O(1) amortized (append) | O(1)          |
|                | Delete    | Best        | O(1) (remove last)   | O(1)             |
|                |           | Worst       | O(n) (remove front)  | O(1)             |
|                |           | Average     | O(n)                 | O(1)             |
|                |           | Expected    | O(n)                 | O(1)             |
| **Linked List** | Insert    | Best        | O(1) (at head)       | O(1)             |
|                |           | Worst       | O(n) (at tail w/o tail ptr) | O(1)        |
|                |           | Average     | O(n)                 | O(1)             |
|                |           | Expected    | O(1) (at known position) | O(1)         |
|                | Delete    | Best        | O(1) (at head)       | O(1)             |
|                |           | Worst       | O(n) (search + delete) | O(1)          |
|                |           | Average     | O(n)                 | O(1)             |
|                |           | Expected    | O(n)                 | O(1)             |
| **Binary Tree** | Insert    | Best        | O(1) (empty tree)    | O(1)             |
| (Unbalanced)   |           | Worst       | O(n) (degenerate tree) | O(1)           |
|                |           | Average     | O(log n)             | O(1)             |
|                |           | Expected    | O(log n) (random inserts) | O(1)         |
|                | Delete    | Best        | O(log n)             | O(1)             |
|                |           | Worst       | O(n)                 | O(1)             |
|                |           | Average     | O(log n)             | O(1)             |
|                |           | Expected    | O(log n)             | O(1)             |

**Notes**:  
- "Vector" assumes a dynamic array (e.g., C++ `std::vector`, Python `list`).  
- Expected time for vector insert refers to amortized analysis when inserting at the end with occasional resizing.  
- Binary tree here refers to an **unbalanced binary search tree**. For a **balanced tree** like AVL or Red-Black Tree, worst-case time becomes `O(log n)` for insert and delete.

## Maximum Subsequence Problem
### Maximum Subsequence Sum Problem

The problem: Find a contiguous subsequence with the largest sum from a sequence of possibly negative integers.

Given:
```
1, 2, -4, 1, 5, -10, 4, 1
```

The maximum sum is `6` from subsequence `[1, 5]`.

---

### Brute Force Solution (O(n³))

```cpp
int maxSubSeqSum(const vector<int> & a) {
    int max = 0;
    for (int i = 0; i < a.size(); i++)
        for (int j = i; j < a.size(); j++) {
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += a[k];
            if (max < sum)
                max = sum;
        }
    return max;
}
```
- Three nested loops.
- For each pair `(i, j)`, we calculate the sum of the subarray from `i` to `j` by summing the elements one by one.
- The innermost loop dominates the cost and runs up to `O(n)` times per `(i, j)` pair.
- Total time = `O(n × n × n) = O(n³)`.

---

### Divide and Conquer (O(n log n))

```cpp
int maxSumRec(const vector<int> & a, int left, int right) {
    if (left == right)
        return a[left] > 0 ? a[left] : 0;

    int center = (left + right) / 2;
    int maxLeftSum = maxSumRec(a, left, center);
    int maxRightSum = maxSumRec(a, center + 1, right);

    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for (int i = center; i >= left; i--) {
        leftBorderSum += a[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    int maxRightBorderSum = 0, rightBorderSum = 0;
    for (int j = center + 1; j <= right; j++) {
        rightBorderSum += a[j];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

int maxSubSum3(const vector<int> & a) {
    return maxSumRec(a, 0, a.size() - 1);
}
```
A more effcient solution can be obtained from the following observation:
A maximal subsequence is either entirely within the first half, or entirely within the second half, or
it straddles the two halves. If it straddles the two halves, it can be broken into two pieces:
1. the sequence with the largest sum entirely within the first half that contains the last element
of the first half.
2. the sequence with the largest sum entirely within the last half that contains the first element
of the last half.
Thus, we can find the sequences in each half that satisfy these conditions, add them up and compare
to the sequences found recursively in each half. We just take the max of all of them.


This algorithm recursively divides the array into halves.

1. At each level of recursion:
   - We divide the array into two halves — this gives us the `log n` levels (like mergesort).
2. At each level, we:
   - Compute the max sum on the left side (recursive call)
   - Compute the max sum on the right side (recursive call)
   - Compute the max crossing sum — this is done in **linear time** (single pass from the center out to each side).

So:
- Each level does **O(n)** work to find the crossing sum.
- There are **O(log n)** levels due to the division.
- Total time = `O(n log n)`.

Math: 
$$
\begin{align*}
T(1) &= 1 \\
T(N) &= 2T(N/2) + cN \\
&= 2\left(2T(N/4) + cN/2\right) + cN \\
&= 4T(N/4) + cN + cN \\
&= 4\left(2T(N/8) + cN/4\right) + 2cN \\
&= 8T(N/8) + 3cN \\
&\;\;\vdots \\
&= 2^k T(N/2^k) + kcN \quad \text{(1)}
\end{align*}
$$

The telescoping stops when ( \frac{N}{2^k} = 1 ), which implies ( N = 2^k ) or ( k = \log_2 N ).

Substituting ( k = \log_2 N ) into equation (1):

$$
\begin{align*}
T(N) &= 2^{\log_2 N} \cdot T(1) + \log_2 N \cdot cN \\
&= N + cN \log_2 N \\
&\in \mathcal{O}(N + N \log N)
\end{align*}
$$

---

### Linear Time Solution (Kadane's Algorithm, O(n))

```cpp
int maxSubSum4(const vector<int> & a) {
    int maxSum = 0, thisSum = 0;
    for (int j = 0; j < a.size(); j++) {
        thisSum += a[j];
        if (thisSum > maxSum)
            maxSum = thisSum;
        else if (thisSum < 0)
            thisSum = 0;
    }
    return maxSum;
}
```

#### Why It Works
Kadane’s algorithm is based on this invariant:

If the running sum (thisSum) ever becomes negative, it cannot be part of the maximum subsequence.

Here's why:
* If thisSum is negative, then:
    * Adding it to any future element makes that element smaller, not larger.
    * So it’s better to reset and start a new subsequence from the next element.

* If thisSum is non-negative:
    * Then any new positive number can build upon it to possibly form a larger subsequence.
    * So keep adding until it becomes negative.

This ensures that you're always carrying forward only positive contribution, discarding anything that drags the sum down.

- Single loop that runs once through the array: **O(n)** time.
- At each index:
  - Add the current value to a running total (`thisSum`).
  - If the running total becomes negative, reset it to 0.
  - Track the maximum seen so far.

No nested loops or recursion — just a single pass — hence, linear time.

---

### ✅ Summary Table

| **Algorithm**         | **Explanation**                                                               | **Time Complexity** |
|-----------------------|-------------------------------------------------------------------------------|---------------------|
| Brute Force           | Triple loop: check every subarray and compute its sum manually               | O(n³)               |
| Divide and Conquer    | Recursively divide array, merge results in linear time at each level         | O(n log n)          |
| Kadane’s Algorithm    | Scan array once, track max sum in linear time                                | O(n)                |



## Attribution
This repository contains derivative work based on course materials by Professor Stewart Weiss for CSCI 335 at Hunter College, CUNY, Spring 2019.

Original materials are available at: [https://www.cs.hunter.cuny.edu/~sweiss/course_materials/csci335/csci335_s19.php](https://www.cs.hunter.cuny.edu/~sweiss/course_materials/csci335/csci335_s19.php)

The original work is licensed under the [Creative Commons Attribution-ShareAlike 4.0 International License (CC BY-SA 4.0)](https://creativecommons.org/licenses/by-sa/4.0/).  
This repository is licensed under the same license. Changes include summarization, reorganization, and additional commentary.
