# 🔍 Searching and Sorting Algorithms Visualized (C++)

This project demonstrates classic **Searching** and **Sorting** algorithms implemented in **C++**, along with precise runtime comparisons using `chrono`. It’s a console-based educational tool, built to help students and developers understand how these algorithms function behind the scenes.

---

## 📦 Algorithms Included

| Category     | Algorithms Implemented                |
| ------------ | ------------------------------------- |
| 📊 Sorting   | ✅ Merge Sort, ✅ Quick Sort            |
| 🔍 Searching | ✅ Binary Search, ✅ Exponential Search |

---

## 💻 Program Features

- 🔢 Generate `N` random integers between 0 and 999
- 🧠 Sort using two different algorithms
- 🚀 Search for a user-provided number using two searching algorithms
- ⏱️ Measures and compares execution time (in nanoseconds)
- 📋 Clean and user-friendly console output

---

## 📊 Sorting Algorithms

### ✅ Merge Sort

**Description:**\
Merge Sort uses the **Divide and Conquer** strategy. It divides the array into halves recursively, then merges sorted halves into a final sorted array.

**How it works:**

1. Divide array until subarrays of size 1
2. Merge back in sorted order

```
Input: [5, 2, 9, 1]
→ Split: [5, 2] and [9, 1]
→ Split again: [5], [2], [9], [1]
→ Merge: [2, 5], [1, 9]
→ Final Merge: [1, 2, 5, 9]
```

---

### ⚡ Quick Sort

**Description:**\
Quick Sort picks a **pivot** element, partitions the array so that elements less than the pivot go left, others right, and recursively sorts the partitions.

**How it works:**

1. Choose pivot
2. Partition around pivot
3. Recur on subarrays

```
Input: [7, 3, 1, 9]
→ Pivot = 9
→ Partition: [7, 3, 1] | 9 | []
→ Pivot = 1 (left)
→ Partition: [] | 1 | [3, 7]
→ Final: [1, 3, 7, 9]
```

---

## 🔍 Searching Algorithms

### 🔎 Binary Search

**Description:**\
Binary Search operates on **sorted arrays**. It checks the middle element and halves the search space in each step.

---

#### Example: Step-by-step Binary Search

Search for `e = 27` in:\
`A = [1, 3, 7, 8, 10, 11, 12, 15, 19, 21, 22, 23, 29, 31, 37]`

#### Binary Tree Representation (Conceptual)

```
                15 (root)
             /             \
          8                 23
        /   \             /    \
       3    11          21     31
      / \   / \        /  \   /  \
     1  7 10 12       19 22 29  37
```

#### Steps:

1. Compare 27 with root (15) → 27 > 15 → go right
2. Compare 27 with 23 → 27 > 23 → go right
3. Compare 27 with 31 → 27 < 31 → go left
4. Compare 27 with 29 → 27 < 29 → go left → ❌ Not found (no subtree)

---

### 🚀 Exponential Search

**Description:**\
Best suited for **unbounded or large sorted arrays**. It first finds a range by doubling the index, then performs binary search in that range.

**How it works:**

1. Compare at index `1, 2, 4, 8...` until value ≥ target
2. Apply binary search in the bounded range

---

## 🖼️ Visual Representations


### Merge Sort Animation
https://www.lavivienpost.net/wp-content/uploads/2022/02/merge-sort-400.gif


### Quick Sort Animation
https://www.lavivienpost.net/wp-content/uploads/2022/02/quicksort-600-1.gif


### Binary Search Tree Steps
https://d18l82el6cdm1i.cloudfront.net/uploads/bePceUMnSG-binary_search_gif.gif

### Exponential Search
https://www.mathwarehouse.com/programming/images/binary-vs-linear-search/binary-and-linear-search-animations.gif

---

## 🛠️ How to Compile & Run

### 📒 Requirements

- C++ compiler (e.g., `g++`)
- C++11 or later

### ⚙️ Build Instructions

```bash
# Clone the repository
git clone https://github.com/your-username/your-repo-name.git
cd your-repo-name

# Compile the code
g++ -std=c++11 -o sort_search main.cpp

# Run the executable
./sort_search
```

---

## 📂 File Structure

```
📁 your-repo-name/
├── main.cpp             # C++ source code
├── README.md            # Project documentation
```

---

## 📈 Performance Measurement

Each algorithm prints its execution time in **nanoseconds** for fair comparison.

Example:

```
Merge Sort Time:         6400 ns
Quick Sort Time:         5200 ns
Binary Search Time:       300 ns
Exponential Search Time:  200 ns
```

---

## 📄 License

This project is open-source under the **MIT License**. Feel free to use, learn from, and modify the code.

---

## 🙌 Acknowledgments

Made with ❤️ as part of a learning project on Data Structures and Algorithms in C++.

