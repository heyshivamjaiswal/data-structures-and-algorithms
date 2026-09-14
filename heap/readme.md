

In C++:

```cpp
// Max Heap
priority_queue<int> pq;

// Min Heap
priority_queue<int, vector<int>, greater<int>> pq;
```

### Remember

```text
Max Heap → largest element at top
Min Heap → smallest element at top
```

---

## 2. Basic Operations

```cpp
pq.push(x);      // O(log n)
pq.pop();        // O(log n)
pq.top();        // O(1)
pq.size();       // O(1)
pq.empty();      // O(1)
```

---

# 3. Most Important Pattern: Top K

### Kth Largest

Use a **Min Heap** of size `k`.

```cpp
for (int x : nums) {
    pq.push(x);

    if (pq.size() > k)
        pq.pop();
}

return pq.top();
```

### Kth Smallest

Use a **Max Heap** of size `k`.

```text
Kth Largest  → Min Heap
Kth Smallest → Max Heap
```

### Why?

For Kth Largest:

```text
Keep K largest
       ↓
Need smallest among them
       ↓
Min Heap
```

For Kth Smallest:

```text
Keep K smallest
       ↓
Need largest among them
       ↓
Max Heap
```

---

# 4. Kth Largest in a Stream

Same Top-K pattern.

Every time a new number arrives:

```cpp
pq.push(val);

if (pq.size() > k)
    pq.pop();

return pq.top();
```

**LeetCode 703**

---

# 5. K-Sorted / Nearly Sorted Array

If every element is at most `k` positions away from its correct position:

```text
Use Min Heap
Heap size = k + 1
```

Why `k + 1`?

The next smallest element can only be somewhere among the next `k + 1` elements.

Complexity:

```text
O(n log k)
```

---

# 6. Common Heap Patterns

| Problem                            | Heap             |
| ---------------------------------- | ---------------- |
| Kth Largest                        | Min Heap         |
| Kth Smallest                       | Max Heap         |
| Top K Largest                      | Min Heap         |
| Top K Smallest                     | Max Heap         |
| K-Sorted Array                     | Min Heap         |
| Merge K Sorted Lists               | Min Heap         |
| Find Median                        | Two Heaps        |
| Smallest/Best candidate repeatedly | Usually Min Heap |
| Largest/Best candidate repeatedly  | Usually Max Heap |

---

# 7. Custom Heap

For pairs:

```cpp
priority_queue<pair<int,int>,
               vector<pair<int,int>>,
               greater<pair<int,int>>> pq;
```

Useful for:

```text
(value, index)
(distance, point)
(cost, node)
(time, task)
```

For more complicated objects, use a custom comparator.

---

# 8. Heap  Thinking

When you see words like:

```text
K largest
K smallest
Top K
smallest element repeatedly
largest element repeatedly
minimum/maximum at every step
merge K sorted things
```

 **Think Heap.**


1. Do I need the smallest or largest?
2. Do I only care about Top K?
3. Can I maintain a heap instead of sorting everything?
4. Can I keep the heap size small?

---

# 9. Complexity Trick

If heap size is `k`:

```text
push/pop → O(log k)
```

For `n` elements:

```text
O(n log k)
```

Space:

```text
O(k)
```

This is often better than:

```text
Sorting → O(n log n)
```

when `k << n`.

---

# 10. Quick Memory Tricks

### Top K

```text
K Largest  → Min Heap
K Smallest → Max Heap
```

### K-Sorted

```text
K distance → Heap size K + 1
```

### Direction trick

Don't think:

> "Largest means Max Heap."

Instead think:

> **"What elements am I keeping, and which one do I need to remove?"**

Example:

```text
K largest
→ remove smallest
→ Min Heap
```

---

## Final Cheat Sheet

```text
              HEAP
                │
       ┌────────┴────────┐
       ↓                 ↓
   MAX HEAP           MIN HEAP
   largest top        smallest top
       │                 │
 K smallest          K largest
       │                 │
       ↓                 ↓
   Max Heap          Min Heap
```

**Golden rule:**

> If you only need the best `K` elements, don't sort everything — maintain a heap of size `K`.
