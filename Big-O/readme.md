# 📊 Big-O Time Complexities – Learn by Examples (C Language)

Welcome to the **Big-O Notation** section of this DSA repository!  
Here, you'll learn how to measure the **efficiency of algorithms** using **time complexity**, explained with simple and well-commented C programs.

---

## 🧠 What is Big-O Notation?

**Big-O notation** describes how the runtime of an algorithm grows with the size of the input.  
It's **not about exact timing**, but about how fast things get **slower** as your input grows!

---

## 📚 Common Time Complexities

| Time Complexity | Name                  | Description                                                                 | Example Code                    |
|-----------------|-----------------------|-----------------------------------------------------------------------------|----------------------------------|
| O(1)            | Constant Time         | Executes in the same time, no matter the input size.                        | `constant.c`                    |
| O(log n)        | Logarithmic Time      | Cuts the problem in half each time.                                         | `binary_search.c` (in Arrays)   |
| O(n)            | Linear Time           | Grows proportionally with input size.                                       | `linear.c`                      |
| O(n log n)      | Linearithmic Time     | Slightly slower than linear, faster than quadratic.                         | (Coming soon)                   |
| O(n²)           | Quadratic Time        | Time grows rapidly; often in nested loops.                                  | `quadratic.c`                   |
| O(2^n)          | Exponential Time      | Time doubles with each increase in input; very inefficient.                 | `exponential.c`                 |
| O(n!)           | Factorial Time        | Extremely slow; all possible permutations.                                  | `factorial.c`                   |

---

## 📁 Files in This Folder

| File Name            | What It Demonstrates             | Time Complexity |
|---------------------|----------------------------------|-----------------|
| `constant.c`         | Print a number                   | O(1)            |
| `linear.c`           | Traverse an array                | O(n)            |
| `quadratic.c`        | Nested loops                     | O(n²)           |
| `exponential.c`      | Recursive exponentiation         | O(2^n)          |
| `factorial.c`        | Print all permutations (basic)   | O(n!)           |

---
