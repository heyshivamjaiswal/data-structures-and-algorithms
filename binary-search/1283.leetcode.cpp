// Guess divisor d
//       ↓
// For every number:
// ceil(nums[i] / d)
//       ↓
// Add them
//       ↓
// sum <= threshold?
// YES → divisor works → go LEFT
// NO  → divisor too small → go RIGHT


class Solution {
public:

 //helper fxn to calculate sum of division
 int sumByDivision(vector<int>&nums, int div){
    int sum = 0;
    for(int num: nums){
        sum = sum + ceil((double)num/div);
    }
    return sum;
 }
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size() > threshold) return -1;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while(low<= high){
            int mid = (low+high)/2;
            if(sumByDivision(nums, mid) <= threshold){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};