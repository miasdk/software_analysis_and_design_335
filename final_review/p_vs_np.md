# P vs NP

## Conceptual Overview
- **P**: Class of problems that can be solved in polynomial time (efficiently) by a deterministic Turing machine.
- **NP**: Class of problems for which a solution can be verified in polynomial time by a deterministic Turing machine.
- **NP-Complete**: The hardest problems in NP; if any NP-complete problem is in P, then P = NP.
- **NP-Hard**: At least as hard as NP-complete, but not necessarily in NP (may not be verifiable in polynomial time).

_Note: For more details, see your class notes or slides on computational complexity if available._

---

## Key Definitions Table
| Class         | Definition                                                                 | Example Problem                |
|---------------|----------------------------------------------------------------------------|--------------------------------|
| P             | Solvable in polynomial time                                                | Sorting, shortest path         |
| NP            | Verifiable in polynomial time                                              | SAT, subset sum                |
| NP-Complete   | In NP, as hard as any in NP (polynomial-time reduction from any NP problem)| SAT, 3-SAT, Hamiltonian cycle  |
| NP-Hard       | At least as hard as NP-complete, not necessarily in NP                     | Halting problem, TSP (general) |

---

## Common Pitfalls & Best Practices
- Not all NP problems are known to be NP-complete.
- "NP" does NOT mean "not polynomial"—it means "nondeterministic polynomial time."
- P ⊆ NP, but whether P = NP is unknown (the famous open question).
- NP-complete problems are in NP and are as hard as any problem in NP.
- NP-hard problems may not even be decision problems (can be optimization or search problems).

---

## Practice Questions

### 1. Give an example of a problem in P and a problem in NP (but not known to be in P).
**Solution:**
- In P: Sorting (e.g., Merge Sort)
- In NP: SAT (Boolean satisfiability problem)

**Related LeetCode Problems:**
- [78. Subsets](https://leetcode.com/problems/subsets/) (exponential number of solutions, but each can be verified quickly)
- [39. Combination Sum](https://leetcode.com/problems/combination-sum/)

---

### 2. Explain what it would mean for P = NP.
**Solution:**
If P = NP, every problem whose solution can be verified quickly (in polynomial time) can also be solved quickly (in polynomial time). This would revolutionize fields like cryptography, optimization, and more.

---

### 3. Why is the traveling salesman problem considered NP-hard?
**Solution:**
TSP is at least as hard as any problem in NP (any NP problem can be reduced to it in polynomial time). The decision version ("is there a tour of length ≤ k?") is NP-complete; the optimization version is NP-hard.

**Related LeetCode Problems:**
- [332. Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/) (graph traversal)
- [943. Find the Shortest Superstring](https://leetcode.com/problems/find-the-shortest-superstring/) (TSP variant)

---

## References
- _See: your class notes/slides on computational complexity_
- [Wikipedia: P vs NP problem](https://en.wikipedia.org/wiki/P_versus_NP_problem)
- [Clay Mathematics Institute: P vs NP](https://www.claymath.org/millennium-problems/p-vs-np-problem) 