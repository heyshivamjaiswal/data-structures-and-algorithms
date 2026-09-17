class MedianFinder {
    priority_queue<int> leftHeap;
    priority_queue<int, vector<int>, greater<int>> rightHeap;

public:
    MedianFinder() {
    }

    void addNum(int num) {

        leftHeap.push(num);

        // Make sure left's biggest <= right's smallest
        if (!rightHeap.empty() &&
            leftHeap.top() > rightHeap.top()) {

            int x = leftHeap.top();
            leftHeap.pop();

            rightHeap.push(x);
        }

        // Left should not have more than 1 extra element
        if (leftHeap.size() > rightHeap.size() + 1) {

            int x = leftHeap.top();
            leftHeap.pop();

            rightHeap.push(x);
        }

        // Right should never have more elements than left
        if (rightHeap.size() > leftHeap.size()) {

            int x = rightHeap.top();
            rightHeap.pop();

            leftHeap.push(x);
        }
    }

    double findMedian() {

        if (leftHeap.size() > rightHeap.size()) {
            return leftHeap.top();
        }

        return (leftHeap.top() + rightHeap.top()) / 2.0;
    }
};


// ### Two Heap Rules

// 1. MAX HEAP (leftHeap)
//    → Stores the smaller half of numbers.

// 2. MIN HEAP (rightHeap)
//    → Stores the larger half of numbers.

// 3. leftHeap can have AT MOST 1 extra element.
//    → left.size() == right.size()
//    → OR left.size() == right.size() + 1

// 4. Every number in left must be <= every number in right.
//    → leftHeap.top() <= rightHeap.top()

// 5. Finding median:
//    → left.size() > right.size()
//         median = leftHeap.top()

//    → Same size:
//         median = (leftHeap.top() + rightHeap.top()) / 2.0

//COMPLEXITY

// addNum()     → O(log n)
// findMedian() → O(1)
// Space        → O(n)
