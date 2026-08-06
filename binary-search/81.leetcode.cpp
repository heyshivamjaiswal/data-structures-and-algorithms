// 1. Check mid first.
// 2. If found → return true.
// 3. If left == mid == right:
//       mid isn't target.
//       left and right have the same value as mid.
//       So neither can be the target.
// 4. Safely shrink:
//       left++
//       right--


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while(left  <= right){
            int mid = left + (right-left)/2;

            if(nums[mid] == target) return true;
            //edge case
            if(nums[left] == nums[mid] && nums[mid] == nums[right]){
            left++;
            right--;
            continue;
            }

            if(nums[left] <= nums[mid]){
                if(target >= nums[left] && target < nums[mid]){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
            else{
                if(target <= nums[right] && target > nums[mid]){
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
        }
        return false;
    }
};