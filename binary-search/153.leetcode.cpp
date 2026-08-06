// Compare only with nums[right].

// mid > right
// ↓
// mid is in the BIG half
// Go Right

// mid <= right
// ↓
// mid is in the SMALL half
// Keep mid and Go Left
// (right = mid)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;

        while(left < right){
         int  mid = left + (right - left)/2;

            if(nums[mid] > nums[right]){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        return nums[left];
    }
};