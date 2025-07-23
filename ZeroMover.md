Problem Statement
Given an array, move all zeroes to the end while keeping the order of non-zero elements the same.

Example:
- Input: [1, 2, 0, 4, 3, 0, 5, 0]
- Output: [1, 2, 4, 3, 5, 0, 0, 0]

---
Approach Using Merge Sort
Merge Sort is a divide and conquer algorithm that splits the array into smaller subarrays, sorts them, and then merges them back together. Here, we modify the merge step to prioritize non-zero elements over zeroes.

#### Steps:
1. Divide: Split the array into two halves recursively until each subarray has a single element.
2. Conquer (Merge): Merge the subarrays while ensuring:
   - Non-zero elements come before zeroes.
   - The relative order of non-zero elements is preserved.

---

### Diagrammatic Explanation
Let's visualize the process using the input array [1, 2, 0, 4, 3, 0, 5, 0].

#### Step 1: Divide the Array
We recursively split the array into halves until each subarray has one element.


Original Array: [1, 2, 0, 4, 3, 0, 5, 0]

Split 1: [1, 2, 0, 4] and [3, 0, 5, 0]
Split 2: [1, 2], [0, 4], [3, 0], [5, 0]
Split 3: [1], [2], [0], [4], [3], [0], [5], [0]


#### Step 2: Merge Subarrays
Now, we merge the subarrays while ensuring non-zero elements come first.

##### Merge [1] and [2]
- Both are non-zero → Merge in order: [1, 2]

##### Merge [0] and [4]
- 4 is non-zero → Place 4 first: [4, 0]

##### Merge [3] and [0]
- 3 is non-zero → Place 3 first: [3, 0]

##### Merge [5] and [0]
- 5 is non-zero → Place 5 first: [5, 0]

Now, we have:
- [1, 2], [4, 0], [3, 0], [5, 0]

##### Merge [1, 2] and [4, 0]
- Compare 1 (non-zero) and 4 (non-zero) → Take 1: [1]
- Compare 2 (non-zero) and 4 (non-zero) → Take 2: [1, 2]
- Remaining 4 (non-zero) → [1, 2, 4]
- Remaining 0 → [1, 2, 4, 0]

##### Merge [3, 0] and [5, 0]
- Compare 3 (non-zero) and 5 (non-zero) → Take 3: [3]
- Compare 0 and 5 (non-zero) → Take 5: [3, 5]
- Remaining 0 and 0 → [3, 5, 0, 0]

Now, we have:
- [1, 2, 4, 0] and [3, 5, 0, 0]

##### Final Merge: [1, 2, 4, 0] and [3, 5, 0, 0]
- Compare 1 (non-zero) and 3 (non-zero) → Take 1: [1]
- Compare 2 (non-zero) and 3 (non-zero) → Take 2: [1, 2]
- Compare 4 (non-zero) and 3 (non-zero) → Take 3: [1, 2, 3]
- Compare 4 (non-zero) and 5 (non-zero) → Take 4: [1, 2, 3, 4]
- Compare 0 and 5 (non-zero) → Take 5: [1, 2, 3, 4, 5]
- Remaining 0, 0, 0 → [1, 2, 3, 4, 5, 0, 0, 0]

---

### Final Output
The array after merging is [1, 2, 3, 4, 5, 0, 0, 0].

Wait! This doesn't match the expected output [1, 2, 4, 3, 5, 0, 0, 0].

Issue Identified:
The relative order of 4 and 3 got swapped because merge sort does not inherently preserve the original order of equal elements (unless modified).

---

### Corrected Approach
To preserve the original order of non-zero elements, we need a stable sorting algorithm. However, merge sort is stable by default, but our modification to prioritize non-zero elements affects stability.

#### Alternative Idea:
Instead of modifying merge sort, we can use a two-pointer approach (as in the initial solution) for O(n) time and O(1) space.

But if we must use divide and conquer, we can modify the merge step to:
1. Separate non-zero and zero elements during merging.
2. Concatenate non-zero elements first, followed by zeroes.

---

### Revised Merge Step
1. Divide: Split the array into halves recursively.
2. Merge:
   - Traverse both subarrays.
   - Collect non-zero elements first.
   - Append zeroes at the end.

#### Example with [1, 2, 0, 4] and [3, 0, 5, 0]
- Non-zero elements: [1, 2, 4, 3, 5]
- Zeroes: [0, 0, 0]
- Merged: [1, 2, 4, 3, 5, 0, 0, 0]

This preserves the order of non-zero elements.

---

### Final Answer
The optimal approach is the two-pointer method (O(n) time), but if we must use divide and conquer, we can modify merge sort to separate non-zero and zero elements during merging.

#### Final Output:

[1, 2, 4, 3, 5, 0, 0, 0]

---

