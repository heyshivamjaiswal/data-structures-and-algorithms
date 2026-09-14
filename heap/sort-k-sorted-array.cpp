class Solution {
public:
    void sortKSortedArray(vector<int>& arr, int k) {

        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Put first k + 1 elements into heap
        for (int i = 0; i <= k && i < arr.size(); i++) {
            minHeap.push(arr[i]);
        }

        int index = 0;

        // Process remaining elements
        for (int i = k + 1; i < arr.size(); i++) {

            arr[index++] = minHeap.top();
            minHeap.pop();

            minHeap.push(arr[i]);
        }

        // Empty the heap
        while (!minHeap.empty()) {
            arr[index++] = minHeap.top();
            minHeap.pop();
        }
    }
};
