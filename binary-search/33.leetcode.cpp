//Method 1 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == target){
                return i;
            }
        }
        return -1;
    }
};

// 1. Check mid.

// 2. Find which half is sorted.

// 3. Check if target belongs to the sorted half.

// 4. Search that half; otherwise search the other half.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;

        while(left <= right){
            
            int mid = left + (right-left)/2;
            if(nums[mid] == target) return mid;

            if(nums[left] <= nums[mid]){
                if(target >= nums[left] && target < nums[mid]){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            else{
                if(target > nums[mid] && target <= nums[right]){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
        }
        return -1;
    }
};