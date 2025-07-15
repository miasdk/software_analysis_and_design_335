# Project 2 Report: Hash Table with AVL Tree Chaining

## AVL Tree Description

The AVL tree is a self-balancing binary search tree. Each node stores a key-value pair (book title and author-genre info) and keeps track of its height. The tree stays balanced by doing rotations when the balance factor gets too high or low.

**Main features:**
- Four rotation types: LL, RR, LR, RL
- Each node tracks its height
- Automatically balances to keep O(log n) performance
- Good for handling collisions in hash tables

**Operations:**
- Insert: O(log n) - normal BST insert plus rebalancing
- Search: O(log n) - binary search with balanced tree
- Delete: O(log n) - remove and rebalance

## Hash Table Integration

I used AVL trees instead of linked lists for collision resolution. This gives better performance when there are lots of collisions.

**How it works:**
- Fixed array of 101 buckets (prime number)
- Each bucket points to an AVL tree
- Uses std::hash for string keys

**Why this is better:**
- Handles collisions efficiently - O(log n) even with many collisions
- Keeps things sorted within each bucket
- Still works well when table gets full
- Only uses memory for buckets that have data

**Main operations:**
- Insert: hash the key, find bucket, insert into AVL tree
- Search: hash the key, search the AVL tree in that bucket
- Delete: hash the key, remove from AVL tree in bucket

## Time and Space Complexity

### Time Complexity

**Hash table operations:**
- Insert: O(log n) average - hash function + AVL insert
- Search: O(log n) average - hash function + AVL search
- Delete: O(log n) average - hash function + AVL delete

**Library operations:**
- Load from file: O(n log n) - n insertions
- Search by title: O(log n) average
- Display: O(n) - go through all buckets

### Space Complexity

**Hash table:**
- Space: O(n) - stores n key-value pairs
- Bucket overhead: O(b) where b = 101 buckets
- AVL tree overhead: O(n) for nodes and pointers

**Memory usage:**
- Load factor: α = n/b (elements per bucket)
- Good range: 0.5 ≤ α ≤ 1.0
- My implementation: α ≈ 0.15 with 15 elements in 101 buckets

### Performance

**Best case:** O(1) - no collisions
**Average case:** O(log n) - some collisions, small trees
**Worst case:** O(log n) - lots of collisions, but trees stay balanced

**Better than linked lists because:**
- Guaranteed O(log n) no matter how collisions are distributed
- Keeps things sorted in buckets
- Better cache performance
- Good for range queries

This implementation works well for library catalogs, combining fast hash table lookups with reliable balanced trees for handling collisions. 