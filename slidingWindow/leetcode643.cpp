//Brute force generate all the possible sub string

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        double maxAvg = -1e9;
        for(int i=0; i<=n-k; i++){
            long long sum = 0;
            
            for(int j=i; j<i+k; j++){
                sum += nums[j];
            }
           double avg = double(sum)/k;
            maxAvg = max(maxAvg, avg);
        }
        return maxAvg;
    }
};

//METHOD 2

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        long long currentSum = 0; 
        double maxAvg = -1e9;     // Handles negative averages correctly

        for (int right = 0; right < n; right++) {
            currentSum += nums[right]; // 1. Add the incoming element

            // 2. If the window exceeds size k, shrink it from the left
            if (right - left + 1 > k) {
                currentSum -= nums[left]; // Subtract the element leaving the window
                left++;                   // Shrink the window
            }

            // 3. When the window is exactly size k, calculate the max average
            if (right - left + 1 == k) {
                maxAvg = max(maxAvg, (double)currentSum / k); // Use k, not 4
            }
        }
        return maxAvg;
    }
};
