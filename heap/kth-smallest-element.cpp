class Solution {
public:
    int kthSmallest(vector<int>& arr, int k) {
        priority_queue<int> pq; // max heap

        for (int num : arr) {
            pq.push(num);

            // Keep only k smallest elements
            if (pq.size() > k) {
                pq.pop();
            }
        }

        return pq.top();
    }
};
